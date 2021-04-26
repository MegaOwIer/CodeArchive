#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;

const int MX = 10005;

vector<pair<int, int> > G[MX];
bool vis[MX];
int siz[MX], mxsz[MX], dep[MX];

int dfs1(int u, int fa, int total_siz) {
    int ans = -1;
    siz[u] = 1, mxsz[u] = 0;
    for(size_t i = 0; i < G[u].size(); i++) {
        int v = G[u][i].first;
        if(v == fa || vis[v]) continue;
        int cur = dfs1(v, u, total_siz);
        if(ans == -1) ans = cur;
        siz[u] += siz[v];
        mxsz[u] = max(mxsz[u], siz[v]);
    }
    mxsz[u] = max(mxsz[u], total_siz - siz[u]);
    if(mxsz[u] * 2 <= total_siz) ans = u;
    return ans;
}

void dfs2(int u, int fa, int *&data) {
    *data++ = dep[u], siz[u] = 1;
    for(size_t i = 0; i < G[u].size(); i++) {
        int v = G[u][i].first, w = G[u][i].second;
        if(v == fa || vis[v]) continue;
        dep[v] = dep[u] + w;
        dfs2(v, u, data);
        siz[u] += siz[v];
    }
}

int calc(int *st, int *ed, int k) {
    sort(st, ed);
    int ans = 0;
    for(int *l = st, *r = ed - 1; l < r; l++) {
        while(r != l && *l + *r > k) r--;
        ans += r - l;
    }
    return ans;
}

int solve(int u, int fa, int total_siz, int k) {
    static int data[MX], *ed;
    data[0] = 0;
    ed = data + 1;
    int g = dfs1(u, fa, total_siz), ans = 0;
    dep[g] = 0;
    for(size_t i = 0; i < G[g].size(); i++) {
        int v = G[g][i].first, w = G[g][i].second;
        if(vis[v]) continue;
        dep[v] = w;
        int *st = ed;
        dfs2(v, g, ed);
        ans -= calc(st, ed, k);
    }
    ans += calc(data, ed, k);
    vis[g] = true;
    for(size_t i = 0; i < G[g].size(); i++) {
        int v = G[g][i].first;
        if(vis[v]) continue;
        ans += solve(v, g, siz[v], k);
    }
    return ans;
}

int main() {
    int n, k;
    while(~scanf("%d%d", &n, &k)) {
        if(n == 0 && k == 0) break;
        memset(vis + 1, false, sizeof(bool[n]));
        for(int i = 1; i <= n; i++) G[i].clear();
        for(int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(make_pair(v, w));
            G[v].push_back(make_pair(u, w));
        }
        printf("%d\n", solve(1, -1, n, k));
    }
    return 0;
}
