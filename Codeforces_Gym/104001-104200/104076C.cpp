#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using poly_t = vector<vector<int>>;

const int MX = 505;
const int mod = 998244353;

int frac[MX];
int siz[MX], dfs_cnt[MX];
vector<int> G[MX];
vector<int> P[MX];

int Pow(int a, int b) {
    int ans = 1;
    for(; b; b >>= 1) {
        if(b & 1) {
            ans = (LL)ans * a % mod;
        }
        a = (LL)a * a % mod;
    }
    return ans;
}

void multiply(poly_t &cur, int siz) {
    for(int i = MX - 2; i >= 0; i--) {
        for(int j = 0; j + siz < MX; j++) {
            if(cur[i][j] == 0) {
                continue;
            }
            (cur[i + 1][j + siz] += cur[i][j]) %= mod;
        }
    }
}

void division(poly_t &cur, int siz) {
    for(int i = 0; i + 1 < MX; i++) {
        for(int j = 0; j + siz < MX; j++) {
            if(cur[i][j] == 0) {
                continue;
            }
            (cur[i + 1][j + siz] += mod - cur[i][j]) %= mod;
        }
    }
}

void dfs(int u, int f) {
    int num_son = (int)G[u].size() - (f != -1);
    
    siz[u] = 1;
    dfs_cnt[u] = frac[num_son];
    for(int v : G[u]) {
        if(v == f) {
            continue;
        }
        dfs(v, u);
        siz[u] += siz[v];
        dfs_cnt[u] = (LL)dfs_cnt[u] * dfs_cnt[v] % mod;
    }

    if(num_son == 0) {
        return;
    }

    poly_t cur(MX, vector<int>(MX));
    cur[0][0] = 1;

    int prod = 1;
    for(int v : G[u]) {
        if(v == f) {
            continue;
        }
        multiply(cur, siz[v]);
        prod = (LL)prod * dfs_cnt[v] % mod;
    }

    for(int v : G[u]) {
        if(v == f) {
            continue;
        }
        
        division(cur, siz[v]);

        for(int i = 0; i < num_son; i++) {
            LL factor = (LL)frac[i] * frac[num_son - 1 - i] % mod;
            for(int j = 0; j < MX; j++) {
                if(cur[i][j] == 0) {
                    continue;
                }
                P[v][j] = (P[v][j] + cur[i][j] * factor) % mod;
            }
        }
        
        int coef = (LL)prod * Pow(dfs_cnt[v], mod - 2) % mod;
        for(int &val : P[v]) {
            val = (LL)val * coef % mod;
        }

        multiply(cur, siz[v]);
    }
}

// A = A * B * x
void mult(vector<int> &A, const vector<int> &B) {
    vector<int> ans(MX);
    for(int i = 0; i < MX; i++) {
        for(int j = 0; i + j + 1 < MX; j++) {
            (ans[i + j + 1] += (LL)A[i] * B[j] % mod) %= mod;
        }
    }
    A = ans;
}

void dfs2(int u, int f) {
    for(int v : G[u]) {
        if(v == f) {
            continue;
        }
        mult(P[v], P[u]);
        dfs2(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    frac[0] = 1;
    for(int i = 1; i <= n; i++) {
        frac[i] = (LL)frac[i - 1] * i % mod;
    }

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        P[i].resize(MX);
    }
    P[1][0] = 1;

    dfs(1, -1);
    dfs2(1, -1);

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < n; j++) {
            cout << (LL)P[i][j] * dfs_cnt[i] % mod << ' ';
        }
        cout << '\n';
    }
    return 0;
}
