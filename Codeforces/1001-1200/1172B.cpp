#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 200005, mod = 998244353;

int n, frac[MX], dp[MX];
vector<int> G[MX];

void dfs(int u, int f) {
    dp[u] = frac[G[u].size()];
    for(int v : G[u]) if(v != f) {
        dfs(v, u);
        dp[u] = (LL)dp[u] * dp[v] % mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    frac[0] = 1;
    for(LL i = 1; i <= n; i++) frac[i] = frac[i - 1] * i % mod;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    cout << dp[1] * (LL)n % mod << "\n";
    return 0;
}
