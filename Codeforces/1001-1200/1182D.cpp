#include<bits/stdc++.h>
using namespace std;

const int MX = 100005;

int n, dis[MX], deg[MX], fa[MX], flag[MX];
vector<int> G[MX], D;

void dfs1(int u, int f) {
    dis[u] = dis[f] + 1, fa[u] = f;
    for(int v : G[u]) if(v != f) dfs1(v, u);
}

bool dfs2(int u, int f, int dep) {
    if(flag[dep] == -1) flag[dep] = deg[u];
    else if(flag[dep] != deg[u]) return false;
    for(int v : G[u]) if(v != f)
        if(!dfs2(v, u, dep + 1)) return false;
    return true;
}
void check(int x) {
    if(x == 0) return;
    memset(flag + 1, -1, sizeof(int[n]));
    if(dfs2(x, 0, 1))
        printf("%d\n", x), exit(0);
}

pair<int, int> dfs3(int u, int f, int dep) {
    pair<int, int> ans = {INT_MAX, 0};
    for(int v : G[u]) if(v != f) {
        if(deg[v] == 1) ans = min(ans, {dep + 1, v});
        if(deg[v] == 2) ans = min(ans, dfs3(v, u, dep + 1));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        ++deg[u], ++deg[v];
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 0);
    int S = max_element(dis + 1, dis + n + 1) - dis;
    dfs1(S, 0);
    int T = max_element(dis + 1, dis + n + 1) - dis;
    for(int i = T; i != S; i = fa[i]) D.push_back(i);
    D.push_back(S);
    check(S), check(T);
    if(D.size() & 1) {
        int u = D[D.size() >> 1];
        check(u);
        check(dfs3(u, 0, 0).second);
    }
    puts("-1");
    return 0;
}
