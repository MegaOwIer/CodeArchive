#include <bits/stdc++.h>
using namespace std;

template<int MX = 2000000>
struct Istream {
    FILE *F;
    char bf[MX], *p1, *p2;

    Istream() : F(stdin), p1(bf), p2(bf) {}
    Istream(FILE *F) : F(F), p1(bf), p2(bf) {}
    Istream(string f) : F(fopen(f.c_str(), "r")), p1(bf), p2(bf) {}
    ~Istream() {fclose(F);}
    
    int getchar() {
        return p1 == p2 && (p2 = (p1 = bf) + fread(bf, sizeof(char), MX, F)) == bf ? 
            EOF : 
            static_cast<int>(*p1++);
    }
    Istream& operator >> (char &c) {return c = getchar(), *this;}
    template<typename T>
    Istream& operator >> (T &x) {
        int f = 1, c;
        x = 0;
        while(!isdigit(c = getchar()))
            if(c == '-') f = -1;
        while(isdigit(c))
            x = x * 10 + c - '0', c = getchar();
        return x *= f, *this;
    }
};

using LL = long long;
const int MX = 200005, mod = 1000000007;

vector<int> _G[MX];
vector<pair<int, int>> G[MX];
int dfn[MX], low[MX], fa[MX], dep[MX], siz[MX], inv[MX];
int dp[MX];

void solve(int u, int v, int &ans) {
    static int points[MX], sum1[MX], sum2[MX];
    int len = dep[v] - dep[u] + 1, total_siz = 0;
    for(int i = len - 1; i >= 0; i--, v = fa[v]) {
        points[i] = v;
        total_siz += siz[v];
    }
    // update ans
    for(int i = 0; i < len; i++) {
        int v = points[i];
        ans = static_cast<int>(
            (ans + dp[v] * LL(total_siz - siz[v])) % mod
        );
    }
    sum1[len] = 0, sum2[len] = 0;
    for(int i = len - 1; i >= 0; i--) {
        sum1[i] = (sum1[i + 1] + siz[points[i]]) % mod;
        sum2[i] = static_cast<int>(
            ((LL)sum2[i + 1] + 2 * sum1[i + 1] + siz[points[i]]) % mod
        );
    }

    int cur = 0, tmp = 0;
    for(int i = len - 1; i >= 1; i--) {
        tmp = (tmp + sum1[i]) % mod;
        ans = static_cast<int>(
            (ans + (LL)siz[points[i - 1]] * tmp) % mod
        );
    }

    tmp = 0;
    for(int i = len - 1; i >= 1; i--) {
        tmp = (tmp + sum2[i]) % mod;
        cur = static_cast<int>(
            (cur + (LL)siz[points[i - 1]] * tmp) % mod
        );
    }

    ans = static_cast<int>((ans - (LL)cur * inv[len] % mod + mod) % mod);

    for(int i = 1; i < len; i++) {
        int v = points[i];
        dp[u] = static_cast<int>(
            (dp[u] + dp[v] + (LL)i * (len - i) % mod * inv[len] % mod * siz[v]) % mod
        );
    }
    siz[u] = total_siz;
}

void tarjan(int u, int pre, int &ans) {
    static int cnt = 0;
    if(pre == -1) {
        cnt = 0;
    }
    dfn[u] = low[u] = ++cnt;
    dp[u] = 0, siz[u] = 1;
    for(auto &cur : G[u]) {
        int v = cur.first, w = cur.second;
        if(v == pre) continue;
        if(!dfn[v]) {
            fa[v] = u;
            dep[v] = dep[u] + 1;
            tarjan(v, u, ans);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dfn[v]);
        }
        if(low[v] > dfn[u]) {
            ans = static_cast<int>(
                (ans + (LL)dp[u] * siz[v] + (LL)dp[v] * siz[u] + (LL)w * siz[u] % mod * siz[v]) % mod
            );
            dp[u] = static_cast<int>((dp[u] + dp[v] + (LL)w * siz[v]) % mod);
            siz[u] += siz[v];
        }
    }
    for(auto &cur : G[u]) {
        int v = cur.first;
        if(fa[v] != u && dfn[v] > dfn[u]) {
            solve(u, v, ans);
        }
    }
}

Istream<> input;

int main() {
    inv[1] = 1;
    for(int i = 2; i <= 200000; i++) {
        inv[i] = static_cast<int>(LL(mod - mod / i) * inv[mod % i] % mod);
    }
    int _;
    input >> _;
    while(_--) {
        int n, m;
        input >> n >> m;
        memset(dfn + 1, 0, sizeof(int[n]));
        for(int i = 1; i <= n; i++) G[i].clear();
        for(int i = 1; i <= n; i++) _G[i].clear();
        for(int i = 1; i <= m; i++) {
            int u, v;
            input >> u >> v;
            _G[u].push_back(v);
            _G[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) {
            sort(_G[i].begin(), _G[i].end());
            G[i].emplace_back(_G[i][0], 1);
            for(size_t j = 1; j < _G[i].size(); j++) {
                if(_G[i][j] == G[i].back().first) {
                    G[i].back().second = inv[2];
                } else {
                    G[i].emplace_back(_G[i][j], 1);
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            for(auto &cur : G[i]) {
                cur.second = inv[cur.second];
            }
        }
        int ans = 0;
        tarjan(1, -1, ans);
        printf("%d\n", ans);
    }
    return 0;
}
