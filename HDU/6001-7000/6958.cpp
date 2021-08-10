#include <bits/stdc++.h>
using namespace std;

const int MX = 100005;

int fa[MX];
map<int, vector<pair<int, int>>> edges;

int find(int u) {return u == fa[u] ? u : fa[u] = find(fa[u]);}

int solve(int n, int k) {
    if(k == n) {
        return 0;
    }

    int res = n;
    for(auto &cur : edges) {
        int w = cur.first;
        for(auto &tmp : cur.second) {
            int fu = find(tmp.first), fv = find(tmp.second);
            if(fu != fv) {
                fa[fu] = fv;
                res--;
            }
        }
        if(res < k) {
            return -1;
        }
        if(res == k) {
            return w;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        for(int i = 1; i <= n; i++) fa[i] = i;

        edges.clear();
        for(int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges[w].emplace_back(u, v);
        }
        printf("%d\n", solve(n, k));
    }
    return 0;
}
