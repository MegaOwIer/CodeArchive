#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 100005;

int N, c[MX];
LL dep[MX], ans;
vector<pair<int, int>> G[MX];

void dfs(int u, int f) {
    for(pair<int, int> &e : G[u]) {
        if(e.first == f) continue;
        dep[e.first] = dep[u] + e.second;
        dfs(e.first, u);
    }
    dep[u] -= c[u];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i <= N; i++) cin >> c[i];
    for(int i = 1; i <= N; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
        ans += w;
    }
    dfs(0, -1);
    cout << ans * 2 - *max_element(dep, dep + N + 1) << endl;
    return 0;
}
