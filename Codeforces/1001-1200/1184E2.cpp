#include<bits/stdc++.h>
using namespace std;
 
const int MX = 100005, MXLG = 22, ME = 1000005;
 
struct edge {
    int u, v, w, id;
}G[ME];
bool vis[ME];
 
int par[MX];
vector<pair<int, int>> T[MX];
 
int find(int u) {return u == par[u] ? u : par[u] = find(par[u]);}
 
int dep[MX], mx[MXLG][MX], fa[MXLG][MX];
 
void dfs(int u, int f) {
    for(int i = 1; (1 << i) <= dep[u]; i++) {
        fa[i][u] = fa[i - 1][fa[i - 1][u]];
        mx[i][u] = max(mx[i - 1][u], mx[i - 1][fa[i - 1][u]]);
    }
    for(auto &cur : T[u]) if(cur.first != f) {
        dep[cur.first] = dep[u] + 1;
        fa[0][cur.first] = u;
        mx[0][cur.first] = cur.second;
        dfs(cur.first, u);
    }
}
 
int getAns(int u, int v) {
    int ans = 0;
    if(dep[u] > dep[v]) swap(u, v);
    for(int i = MXLG - 1; dep[v] - dep[u]; i--)
        if((1 << i) <= dep[v] - dep[u]) {
            ans = max(ans, mx[i][v]);
            v = fa[i][v];
        }
    if(u == v) return ans;
    for(int i = MXLG - 1; i >= 0; i--)
        if(fa[i][u] != fa[i][v]) {
            ans = max(ans, max(mx[i][u], mx[i][v]));
            u = fa[i][u], v = fa[i][v];
        }
    return max(ans, max(mx[0][u], mx[0][v]));
}
 
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[i] = {u, v, w, i};
    }
    sort(G + 1, G + m + 1, [](edge a, edge b){return a.w < b.w;});
    for(int i = 1; i <= n; i++) par[i] = i;
    for(int i = 1; i <= m; i++) {
        int u = G[i].u, v = G[i].v, w = G[i].w, id = G[i].id;
        int fu = find(u), fv = find(v);
        if(fu == fv) continue;
        vis[id] = true;
        par[fu] = fv;
        T[u].push_back({v, w}), T[v].push_back({u, w});
    }
    dfs(1, 0);
    sort(G + 1, G + m + 1, [](edge a, edge b){return a.id < b.id;});
    for(int i = 1; i <= m; i++) if(!vis[i]) {
        int u = G[i].u, v = G[i].v;
        printf("%d\n", getAns(u, v));
    }
    return 0;
}
