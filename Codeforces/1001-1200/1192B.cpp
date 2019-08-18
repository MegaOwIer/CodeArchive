#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 100005, MXLG = 19;

int n, dfn[MX], pnt[MX], ed[MX], dep[MX], fa[MXLG + 2][MX];
long long dis[MX];
vector<pair<int, LL>> G[MX];
tuple<int, int, long long> e[MX];
int tr[MX << 2][2];
long long bit[MX];

template<typename T = int>
T read() {
    T x = 0;
    int c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c))
        x = x * 10 + c - 48, c = getchar();
    return x;
}

void dfs(int u, int f) {
    static int cnt = 0;
    for(int i = 1; (1 << i) <= dep[u]; i++)
        fa[i][u] = fa[i - 1][fa[i - 1][u]];
    dfn[u] = ++cnt, pnt[cnt] = u;
    for(auto &cur : G[u]) if(cur.first != f) {
        int v = cur.first;
        long long w = cur.second;
        dep[v] = dep[u] + 1, dis[v] = dis[u] + w;
        fa[0][v] = u;
        dfs(v, u);
    }
    ed[u] = cnt;
}

void bit_add(int x, long long u) {
    for(; x <= n; x += x & -x) bit[x] += u;
}
long long bit_query(int x) {
    long long ans = 0;
    for(; x; x -= x & -x) ans += bit[x];
    return ans;
}

int getLCA(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = MXLG; dep[u] != dep[v]; i--)
        if((1 << i) <= dep[u] - dep[v]) u = fa[i][u];
    if(u == v) return u;
    for(int i = MXLG; i >= 0; i--)
        if(fa[i][u] != fa[i][v])
            u = fa[i][u], v = fa[i][v];
    return fa[0][u];
}
inline long long getdis(int u, int v) {
    return bit_query(dfn[u]) + bit_query(dfn[v]) - 2 * bit_query(dfn[getLCA(u, v)]);
}

void maintain(int x) {
    long long mx = 0;
    int points[] = {tr[x << 1][0], tr[x << 1][1], tr[x << 1 | 1][0], tr[x << 1 | 1][1]};
    for(int i = 0; i < 4; i++)
        for(int j = i + 1; j < 4; j++) {
            int u = points[i], v = points[j];
            long long lth = getdis(u, v);
            if(lth > mx)
                mx = lth, tr[x][0] = u, tr[x][1] = v;
        }
}
void segTree_build(int l, int r, int id) {
    if(l == r) {
        tr[id][0] = tr[id][1] = pnt[l];
        return;
    }
    int mid = (l + r) >> 1;
    segTree_build(l, mid, id << 1);
    segTree_build(mid + 1, r, id << 1 | 1);
    maintain(id);
}
void segTree_modify(int l, int r, int id, int L, int R) {
    if(r < L || l > R || (L <= l && r <= R)) return;
    int mid = (l + r) >> 1;
    segTree_modify(l, mid, id << 1, L, R);
    segTree_modify(mid + 1, r, id << 1 | 1, L, R);
    maintain(id);
}

int main() {
    n = read();
    int q = read();
    long long w = read<LL>();
    for(int i = 1; i < n; i++) {
        int u = read(), v = read();
        long long w = read<LL>();
        G[u].push_back({v, w});
        G[v].push_back({u, w});
        e[i] = {u, v, w};
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++) bit_add(i, dis[pnt[i]] - dis[pnt[i - 1]]);
    segTree_build(1, n, 1);
    long long lastans = 0;
    while(q--) {
        int id = (read() + lastans) % (n - 1) + 1;
        long long _w = (read<LL>() + lastans) % w;
        int u = get<0>(e[id]), v = get<1>(e[id]);
        if(dep[u] < dep[v]) swap(u, v);
        bit_add(dfn[u], _w - get<2>(e[id]));
        bit_add(ed[u] + 1, get<2>(e[id]) - _w);
        get<2>(e[id]) = _w;
        segTree_modify(1, n, 1, dfn[u], ed[u]);
        lastans = getdis(tr[1][0], tr[1][1]);
        printf("%lld\n", lastans);
    }
    return 0;
}
