#include <bits/stdc++.h>
using namespace std;

using LL = long long;

constexpr int MX = 200005;

bool vis[MX];
vector<int> G[MX];

void dfs(int u, int ban) {
    vis[u] = true;
    for(int i : G[u]) if(!vis[i] && i != ban) dfs(i, ban);
}

int count(int n) {
    int ans = 0;
    for(int i = 1; i <= n; i++) if(!vis[i]) ans++;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        for(int i = 1; i <= n; i++) G[i].clear();
        for(int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        memset(vis + 1, false, sizeof(bool[n]));
        dfs(b, a);
        int cnt1 = count(n) - 1;
        memset(vis + 1, false, sizeof(bool[n]));
        dfs(a, b);
        int cnt2 = count(n) - 1;
        cout << (LL)cnt1 * cnt2 << "\n";
    }
    return 0;
}
