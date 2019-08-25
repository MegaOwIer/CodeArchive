#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int mod = 998244353, MX = 1005;

int n, ind[MX], res[MX];
long long dis[MX];
bool vis[MX];
vector<pair<int, int>> G[MX];
vector<int> T[MX], pre[MX];

void Dijkstra(int u) {
    memset(dis + 1, 0x3f, sizeof(LL[n]));
    memset(vis + 1, false, sizeof(bool[n]));
    using pLi = pair<LL, int>;
    priority_queue<pLi, vector<pLi>, greater<pLi>> Heap;
    Heap.push({dis[u] = 0, u});
    while(!Heap.empty()) {
        int nw = Heap.top().second;
        Heap.pop();
        if(vis[nw]) continue;
        vis[nw] = true;
        for(int i : pre[nw]) T[i].push_back(nw);
        ind[nw] = pre[nw].size();
        pre[nw].clear();
        for(auto &cur : G[nw]) {
            long long tmp = dis[nw] + cur.second;
            if(dis[cur.first] > tmp) {
                Heap.push({dis[cur.first] = tmp, cur.first});
                pre[cur.first] = {nw};
            } else if(dis[cur.first] == tmp) {
                pre[cur.first].push_back(nw);
            }
        }
    }
}

int BFS(int u) {
    memset(res + 1, 0x3f, sizeof(int[n]));
    res[u] = 0;
    queue<int> Q;
    Q.push(u);
    int ans = 0;
    while(!Q.empty()) {
        int nw = Q.front();
        Q.pop();
        for(int v : T[nw]) {
            res[v] = min(res[v], res[nw]);
            if(!--ind[v]) {
                ans += res[v];
                res[v] = max(res[v], v);
                Q.push(v);
            }
        }
    }
    return ans;
}

int solve(int u) {
    int ans = 0;
    for(int i = 1; i <= n; i++) T[i].clear();
    Dijkstra(u);
    return BFS(u);
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) G[i].clear();
        for(int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) ans += solve(i);
        cout << ans % mod << "\n";
    }
    return 0;
}
