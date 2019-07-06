#include<bits/stdc++.h>
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

template<int MX = 2000000>
struct Ostream {
    FILE *F;
    char bf[MX], *p1, *const p2;
    
    Ostream() : F(stdout), p1(bf), p2(bf + MX) {}
    Ostream(FILE *F) : F(F), p1(bf), p2(bf + MX) {}
    Ostream(string f) : F(fopen(f.c_str(), "w")), p1(bf), p2(bf + MX) {}
    ~Ostream() {flush(), fclose(F);}
    
    void putchar(int x) {*p1++ = x; if(p1 == p2) flush();}
    Ostream& operator << (char &c) {return putchar(c), *this;}
    template<typename T>
    Ostream& operator << (T x) {
        static char dig[20], *top = dig;
        if(x < 0) putchar('-'), x = -x;
        do *top++ = '0' + x % 10;
        while(x /= 10);
        while(top != dig) putchar(*--top);
        return *this;
    }
    Ostream& operator << (const char *s) {
        while(*s) putchar(*s++);
        return *this;
    }
    void flush() {fwrite(bf, sizeof(char), p1 - bf, F), p1 = bf;}
};

using LL = long long;
const int MX = 250005, MXLG = 19;

int n, fa[MXLG][MX], dep[MX], sum[MX];
long long sum2[MX], dp1[MX], dp2[MX], dp3[MX];

struct edge_t {
    int to, nxt;
}e[MX << 1];
int head[MX], tot;

inline void add_edge(int u, int v) {
    e[++tot] = (edge_t){v, head[u]}, head[u] = tot;
    e[++tot] = (edge_t){u, head[v]}, head[v] = tot;
}

inline long long sqr(LL x) {return x * x;}
void dfs1(int u, int f) {
    sum[u] = 0, sum2[u] = 0;
    for(int i = 1; (1 << i) <= dep[u]; i++)
        fa[i][u] = fa[i - 1][fa[i - 1][u]];
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if(v == f) continue;
        dep[v] = dep[u] + 1;
        fa[0][v] = u;
        dfs1(v, u);
        sum[u] += sum[v] + 1;
        sum2[u] += sqr(sum[v] + 1);
    }
}

void dfs2(int u, int f) {
    dp1[u] = dp1[f] + (sqr(sum[u]) - sum2[u]) / 2;
    dp2[u] = dp2[f] + sum[f] * LL(sum[u] + 1);
    dp3[u] = dp3[f] + sqr(sum[u] + 1);
    for(int i = head[u]; i; i = e[i].nxt)
        if(e[i].to != f) dfs2(e[i].to, u);
}

int getLCA(int u, int v) {
    for(int i = 18; dep[u] > dep[v]; i--)
        if((1 << i) <= dep[u] - dep[v]) u = fa[i][u];
    if(u == v) return u;
    for(int i = 18; ~i; i--)
        if(fa[i][u] != fa[i][v])
            u = fa[i][u], v = fa[i][v];
    return fa[0][u];
}
int getFa(int u, int dep) {
    for(int i = 18; dep; i--)
        if((1 << i) <= dep)
            u = fa[i][u], dep -= 1 << i;
    return u;
}

long long solve1(int u, int f) {
    int fu = getFa(u, dep[u] - dep[f] - 1), ff = fa[0][f];
    long long ans = LL(n - sum[f] - 1) * (sum[f] - sum[fu] - 1);
    ans += dp1[u] - dp1[ff] - dp2[u] + dp2[f] + dp3[u] - dp3[f];
    return ans;
}
long long solve2(int u, int v, int f) {
    int fu = getFa(u, dep[u] - dep[f] - 1), fv = getFa(v, dep[v] - dep[f] - 1), ff = fa[0][f];
    long long ans = LL(n - sum[f] - 1) * (sum[f] - sum[fu] - sum[fv] - 2);
    ans += dp1[u] + dp1[v] - dp1[f] - dp1[ff];
    ans -= dp2[u] + dp2[v] - 2 * dp2[f];
    ans += dp3[u] + dp3[v] - 2 * dp3[f];
    ans += LL(sum[fu] + 1) * (sum[fv] + 1);
    return ans;
}

int main() {
    Istream<> cin(stdin);
    Ostream<> cout(stdout);
    int T;
    cin >> T;
    while(T--) {
        int Q;
        cin >> n >> Q;
        tot = 0;
        memset(head + 1, 0, sizeof(int[n]));
        for(int i = 0; (1 << i) <= n; i++)
            memset(fa[i] + 1, 0, sizeof(int[n]));
        for(int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            add_edge(u, v);
        }
        dfs1(1, 0), dfs2(1, 0);
        while(Q--) {
            int u, v;
            cin >> u >> v;
            if(dep[u] < dep[v]) swap(u, v);
            int lca = getLCA(u, v);
            if(u == v)
                cout << n + (sqr(n - 1) - sum2[u] - sqr(n - 1 - sum[u])) / 2 << "\n";
            else if(lca == v)
                cout << n + solve1(u, v) << "\n";
            else
                cout << n + solve2(u, v, lca) << "\n";
        }
    }
    return 0;
}
