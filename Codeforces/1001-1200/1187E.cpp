#include<bits/stdc++.h>
using namespace std;

const int MX = 200005;

int n, siz[MX];
long long ans;
vector<int> G[MX];

void dfs1(int u, int f) {
    siz[u] = 1;
    for(int v : G[u]) if(v != f)
        dfs1(v, u), siz[u] += siz[v];
    ans += siz[u];
}

void dfs2(int u, int f, long long cur) {
    ans = max(ans, cur);
    for(int v : G[u]) if(v != f)
        dfs2(v, u, cur - siz[v] * 2 + n);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, -1);
    dfs2(1, -1, ans);
    cout << ans << "\n";
    return 0;
}
