#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

using pii = pair<int, int>;
using Heap = __gnu_pbds::priority_queue<pii, less<pii>, __gnu_pbds::thin_heap_tag>;

const int MX = 10005;

int deg[MX];
bool vis[MX];
vector<int> G[MX];
Heap::point_iterator pos[MX];

void MCS(int n) {
    Heap heap;
    for(int i = 1; i <= n; i++) pos[i] = heap.push({0, i});
    while(!heap.empty()) {
        int u = heap.top().second;
        heap.pop();
        vis[u] = true;
        for(int v : G[u]) if(!vis[v]) {
            heap.modify(pos[v], {++deg[v], v});
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    MCS(n);
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, deg[i] + 1);
    printf("%d\n", ans);
    return 0;
}
