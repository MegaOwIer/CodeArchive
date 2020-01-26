#include <bits/stdc++.h>
using namespace std;

using LL = long long;

constexpr int MX = 3005;

vector<int> E[MX];
bitset<MX> G[MX];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        E[u].push_back(v);
        G[u].set(v);
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) if(i != j) {
            int cnt = 0;
            for(int u : E[i]) cnt += G[u][j];
            ans += LL(cnt - 1) * cnt / 2;
        }
    }
    cout << ans << "\n";
    return 0;
}
