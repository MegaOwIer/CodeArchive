#include<bits/stdc++.h>
using namespace std;

const int MX = 100005;

int n, m, q, c, fa[MX];
set<int> reach[MX];
map<int, int> G[MX];

int find(int u) {return u == fa[u] ? u : fa[u] = find(fa[u]);}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return;
    if(reach[u].size() < reach[v].size()) swap(u, v);
    fa[v] = u;
    reach[u].insert(reach[v].begin(), reach[v].end());
    reach[v].clear();
}
void add_edge(int u, int v, int w) {
    if(G[u].count(w)) merge(G[u][w], v);
    else G[u][w] = v;
    if(G[v].count(w)) merge(G[v][w], u);
    else G[v][w] = u;
    reach[find(u)].insert(v);
    reach[find(v)].insert(u);
}

bool check(int x, int y) {
    int fx = find(x);
    return find(y) == fx || reach[fx].find(y) != reach[fx].end();
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> c >> q;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    while(q--) {
        string op;
        cin >> op;
        if(op == "+") {
            int x, y, z;
            cin >> x >> y >> z;
            add_edge(x, y, z);
        } else {
            int x, y;
            cin >> x >> y;
            puts(check(x, y) ? "Yes" : "No");
        }
    }
    return 0;
}
