#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MX = 105;

struct edge_t {
    int w, u, v;
    const bool operator < (const edge_t& a) const {return w < a.w;}
}E[MX * MX];

int fa[MX];

int find(int u) {return u == fa[u] ? u : fa[u] = find(fa[u]);}

int main() {
    while(true) {
        int n, m;
        scanf("%d%d", &n, &m);
        if(n == 0 && m == 0) break;
        for(int i = 1; i <= m; i++)
            cin >> E[i].u >> E[i].v >> E[i].w;
        sort(E + 1, E + m + 1);
        int ans = 2147483647;
        for(int it = 1; it <= m; it++) {
            int cnt = 0, mxw = 0;
            for(int i = 1; i <= n; i++) fa[i] = i;
            for(size_t i = it; i <= m; i++) {
                int fu = find(E[i].u), fv = find(E[i].v);
                if(fu != fv) {
                    ++cnt;
                    mxw = E[i].w;
                    fa[fu] = fv;
                }
            }
            if(cnt < n - 1) break;
            ans = min(ans, mxw - E[it].w);
        }
        printf("%d\n", ans == 2147483647 ? -1 : ans);
    }
    return 0;
}
