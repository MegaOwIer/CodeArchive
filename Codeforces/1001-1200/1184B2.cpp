#include<bits/stdc++.h>
using namespace std;

namespace MaxFlow {
    using LL = long long;
    const int ME = 2 * 1003005, MV = 2005;
    struct edge {
        int to, nxt, f;
    }e[ME];
    int tot = 1, head[MV], cur[MV], dis[MV];
    bool inq[MV];

    void add_edge(int u, int v, int f) {
        e[++tot] = (edge){v, head[u], f}, head[u] = tot;
        e[++tot] = (edge){u, head[v], 0}, head[v] = tot;
    }

    bool SPFA(int T, int S) {
        memset(inq + 1, false, sizeof(bool[T]));
        memset(dis + 1, 0x3f, sizeof(int[T]));
        queue<int> Q;
        Q.push(T), dis[T] = 0;
        while(!Q.empty()) {
            int nw = Q.front();
            Q.pop(), inq[nw] = false;
            for(int i = head[nw]; i; i = e[i].nxt)
                if(e[i ^ 1].f && dis[e[i].to] > dis[nw] + 1) {
                    dis[e[i].to] = dis[nw] + 1;
                    Q.push(e[i].to), inq[e[i].to] = true;
                }
        }
        return dis[S] != 0x3f3f3f3f;
    }
    int dfs(int u, int flow, int T) {
        if(u == T) return flow;
        int used = 0, w;
        for(int &i = cur[u]; i; i = e[i].nxt)
            if(e[i].f && !inq[e[i].to] && dis[e[i].to] == dis[u] - 1) {
                w = dfs(e[i].to, min(flow - used, e[i].f), T);
                e[i].f -= w, e[i ^ 1].f += w, used += w;
                if(used == flow) return flow;
            }
        return used;
    }

    int solve(int S, int T) {
        static int ans = 0;
        while(SPFA(T, S)) {
            memcpy(cur + 1, head + 1, sizeof(int[T]));
            ans += dfs(S, INT_MAX, T);
        }
        return ans;
    }
}

using LL = long long;
const int MX = 105, MN = 1005;

int G[MX][MX], ss[MN][3], bs[MN][2];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        memset(G[i] + 1, 0x3f, sizeof(int[n]));
    for(int i = 1; i <= n; i++) G[i][i] = 0;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if(u != v)
            G[u][v] = G[v][u] = 1;
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
    int s, b, k, h;
    cin >> s >> b >> k >> h;
    for(int i = 1; i <= s; i++)
        for(int j : {0, 1, 2}) cin >> ss[i][j];
    for(int i = 1; i <= b; i++)
        for(int j : {0, 1}) cin >> bs[i][j];
    int S = s + b + 1, T = s + b + 2;
    for(int i = 1; i <= s; i++) MaxFlow::add_edge(S, i, 1);
    for(int i = 1; i <= b; i++) MaxFlow::add_edge(s + i, T, 1);
    for(int i = 1; i <= s; i++)
        for(int j = 1; j <= b; j++)
            if(G[ss[i][0]][bs[j][0]] <= ss[i][2] && ss[i][1] >= bs[j][1])
                MaxFlow::add_edge(i, s + j, 1);
    int mx = MaxFlow::solve(S, T);
    long long ans = LLONG_MAX;
    for(int i = 0; i <= s; i++)
        ans = min(ans, 1LL * i * h + k * min<LL>(s - i, mx));
    cout << ans << endl;
    return 0;
}
