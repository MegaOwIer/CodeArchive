#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int mod = 1000000007, MX = 100005;

int n, ans;
long long a[MX];
vector<int> G[MX];
map<long long, int> cnt[MX];

LL gcd(LL u, LL v) {
    return v == 0 ? u : gcd(v, u % v);
}

void dfs(int u, int f) {
    for(auto &cur : cnt[u])
        ans = (ans + cur.first * cur.second) % mod;
    for(int v : G[u]) if(v != f) {
        cnt[v][a[v]] = 1;
        for(auto &cur : cnt[u])
            cnt[v][gcd(cur.first, a[v])] += cur.second;
        dfs(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cnt[1][a[1]] = 1, dfs(1, 0);
    cout << ans << "\n";
    return 0;
}
