/**
 * @date 2023-01-12
 * @author MegaOwIer (megaowier@gmail.com)
 * @brief BF & Greedy.
 */

#include <bits/stdc++.h>
using namespace std;

const int MX =  1000005;

vector<int> G[MX];
int dep[MX], son[MX];
bool vis[MX];

void dfs(int u) {
    int cur = 0, ss = -1;
    for(int v : G[u]) {
        dfs(v);
        if(dep[v] > cur) {
            cur = dep[v];
            ss = v;
        }
    }
    dep[u] = cur + 1;
    son[u] = ss;
}

int solve() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        G[i].clear();
    }
    memset(vis + 1, false, sizeof(bool[n]));

    for(int i = 2; i <= n; i++) {
        int fa;
        cin >> fa;
        G[fa].push_back(i);
    }

    dfs(1);

    set<pair<int, int>, greater<pair<int, int>>> nodes;
    for(int i = 1; i <= n; i++) {
        nodes.emplace(dep[i], i);
    }

    int ans = dep[1], cnt = 0;
    while(!nodes.empty()) {
        int u = nodes.begin() -> second;

        while(u != -1) {
            nodes.erase(make_pair(dep[u], u));
            u = son[u];
        }

        cnt++;
        ans = min(ans, cnt + nodes.begin()->first);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cout << solve() << "\n";
    }
    return 0;
}
