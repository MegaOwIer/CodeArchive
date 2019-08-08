#include<bits/stdc++.h>
using namespace std;

const int MX = 100005;

struct edge_t {
    int u, v, w, id;
};

int n, m, fa[MX];
vector<edge_t> G;

int find(int u) {return u == fa[u] ? u : fa[u] = find(fa[u]);}

bool check(int val) {
    for(auto &i : G)
        if(i.id == 1) i.w = val;
    sort(G.begin(), G.end(), [](edge_t a, edge_t b){return a.w == b.w ? a.id < b.id : a.w < b.w;});
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(auto &cur : G) {
        int fu = find(cur.u), fv = find(cur.v);
        if(cur.id == 1) {
            return fu != fv;
        }
        fa[fu] = fv;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G.push_back({u, v, w, i});
    }
    int L = 0, R = 1000000000, ans;
    while(L <= R) {
        int mid = (L + R) >> 1;
        if(check(mid)) ans = mid, L = mid + 1;
        else R = mid - 1;
    }
    cout << ans << "\n";
    return 0;
}
