#include<bits/stdc++.h>
using namespace std;

using edge_t = tuple<int, int, int, int>;
const int MV = 100005, ME = 1000005;

vector<edge_t> G;
bool vis[ME];
vector<pair<int, int>> T[MV];
int ans[ME];

namespace Kruskal {
    const int MV = 100005;

    int fa[MV];

    int find(int u) {return u == fa[u] ? u : fa[u] = find(fa[u]);}

    void work(int n, int m) {
        sort(G.begin(), G.end(), [](edge_t a, edge_t b){return get<2>(a) < get<2>(b);});
        for(int i = 1; i <= n; i++) fa[i] = i;
        for(edge_t &cur : G) {
            int u, v, w, id;
            tie(u, v, w, id) = cur;
            int fu = find(u), fv = find(v);
            if(fu == fv) continue;
            vis[id] = true;
            fa[fu] = fv;
            T[u].push_back({v, w}), T[v].push_back({u, w});
        }
    }
}

namespace HLD {
    const int MX = 100005;

    int n, siz[MX], mxs[MX], dep[MX], fa[MX], dfn[MX], pnt[MX], top[MX];
    int mx[MX << 2], mn[MX << 2];

    void dfs1(int u, int f) {
        siz[u] = 1;
        for(auto &cur : T[u]) if(cur.first != f) {
            int v = cur.first;
            fa[v] = u, dep[v] = dep[u] + 1;
            dfs1(v, u);
            siz[u] += siz[v];
            if(siz[v] > siz[mxs[u]]) mxs[u] = v;
        }
    }

    void insert(int l, int r, int id, int pos, int val) {
        mx[id] = max(mx[id], val);
        mn[id] = 1000000000;
        if(l == r) return;
        int mid = (l + r) >> 1;
        if(pos <= mid) insert(l, mid, id << 1, pos, val);
        else insert(mid + 1, r, id << 1 | 1, pos, val);
    }
    void dfs2(int u, int f, int root) {
        static int cnt = 0;
        dfn[u] = ++cnt, pnt[cnt] = u, top[u] = root;
        if(mxs[u]) dfs2(mxs[u], u, root);
        for(auto &cur : T[u]) {
            int v = cur.first;
            if(v == f) continue;
            if(v != mxs[u]) dfs2(v, u, v);
            insert(1, n, 1, dfn[v], cur.second);
        }
    }

    int queryMax(int l, int r, int id, int L, int R) {
        if(L <= l && r <= R) return mx[id];
        int mid = (l + r) >> 1, ans = 0;
        if(L <= mid) ans = max(ans, queryMax(l, mid, id << 1, L, R));
        if(R > mid) ans = max(ans, queryMax(mid + 1, r, id << 1 | 1, L, R));
        return ans;
    }
    int getMax(int u, int v) {
        int ans = 0;
        while(top[u] != top[v]) {
            if(dep[top[u]] < dep[top[v]]) swap(u, v);
            ans = max(ans, queryMax(1, n, 1, dfn[top[u]], dfn[u]));
            u = fa[top[u]];
        }
        if(u != v) {
            if(dep[u] < dep[v]) swap(u, v);
            ans = max(ans, queryMax(1, n, 1, dfn[v] + 1, dfn[u]));
        }
        return ans;
    }

    void updateMin(int l, int r, int id, int L, int R, int val) {
        if(L <= l && r <= R) {
            mn[id] = min(mn[id], val);
            return;
        }
        int mid = (l + r) >> 1;
        if(L <= mid) updateMin(l, mid, id << 1, L, R, val);
        if(R > mid) updateMin(mid + 1, r, id << 1 | 1, L, R, val);
    }
    void update(int u, int v, int w) {
        while(top[u] != top[v]) {
            if(dep[top[u]] < dep[top[v]]) swap(u, v);
            updateMin(1, n, 1, dfn[top[u]], dfn[u], w);
            u = fa[top[u]];
        }
        if(u != v) {
            if(dep[u] < dep[v]) swap(u, v);
            updateMin(1, n, 1, dfn[v] + 1, dfn[u], w);
        }
    }

    int queryMin(int l, int r, int id, int pos) {
        if(l == r) return mn[id];
        int mid = (l + r) >> 1;
        if(pos <= mid) return min(mn[id], queryMin(l, mid, id << 1, pos));
        else return min(mn[id], queryMin(mid + 1, r, id << 1 | 1, pos));
    }
    void work(int _n) {
        n = _n;
        dfs1(1, 0);
        dfs2(1, 0, 1);
        for(edge_t &cur : G) {
            int u, v, w, id;
            tie(u, v, w, id) = cur;
            if(vis[id]) continue;
            ans[id] = getMax(u, v);
            update(u, v, w);
        }
        for(edge_t &cur : G) {
            int u, v, w, id;
            tie(u, v, w, id) = cur;
            if(!vis[id]) continue;
            ans[id] = queryMin(1, n, 1, max(dfn[u], dfn[v]));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G.push_back({u, v, w, i});
    }
    Kruskal::work(n, m);
    HLD::work(n);
    for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);
    return 0;
}
