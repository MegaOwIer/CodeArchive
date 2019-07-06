#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 1005;

map<int, int> G[MX];
vector<tuple<int, int, int>> ans;

int dfs(int u, int f) {
    if(G[u].size() == 1) return u;
    for(auto &cur : G[u]) if(cur.first != f) {
        int res = dfs(cur.first, u);
        if(res) return res;
    }
    assert(false);
}

void work1(int u, int v, int k) {
    vector<int> leaf;
    for(auto &cur : G[v]) if(cur.first != u) {
        leaf.push_back(dfs(cur.first, v));
        if(leaf.size() == 2) break;
    }
    ans.push_back({u, leaf[0], k});
    ans.push_back({u, leaf[1], k});
    ans.push_back({leaf[0], leaf[1], -k});
}

void work2(int u, int v, int k) {
    vector<int> leafu, leafv;
    for(auto &cur : G[u]) if(cur.first != v) {
        leafu.push_back(dfs(cur.first, u));
        if(leafu.size() == 2) break;
    }
    for(auto &cur : G[v]) if(cur.first != u) {
        leafv.push_back(dfs(cur.first, v));
        if(leafv.size() == 2) break;
    }
    ans.push_back({leafu[0], leafv[0], k});
    ans.push_back({leafu[1], leafv[1], k});
    ans.push_back({leafu[0], leafu[1], -k});
    ans.push_back({leafv[0], leafv[1], -k});
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u][v] = G[v][u] = w;
    }
    for(int i = 1; i <= n; i++) if(G[i].size() == 2) {
        if(G[i].begin() -> second != G[i].rbegin() -> second)
            return puts("NO"), 0;
        int u = G[i].begin() -> first, v = G[i].rbegin() -> first;
        int w = G[i].begin() -> second;
        G[u].erase(i), G[v].erase(i);
        G[u][v] = G[v][u] = w;
    }
    for(int i = 1; i <= n; i++) {
        for(auto &cur : G[i]) if(cur.first > i) {
            int v = cur.first, w = cur.second;
            if(G[i].size() == 1 && G[v].size() == 1) {
                ans.push_back({i, v, w});
            } else if(G[i].size() == 1) {
                work1(i, v, w / 2);
            } else if(G[v].size() == 1) {
                work1(v, i, w / 2);
            } else {
                work2(i, v, w / 2);
            }
        }
    }
    cout << "YES\n" << ans.size() << "\n";
    for(auto &cur : ans) {
        int u, v, w;
        tie(u, v, w) = cur;
        cout << u << ' ' << v << ' ' << w << "\n";
    }
    return 0;
}
