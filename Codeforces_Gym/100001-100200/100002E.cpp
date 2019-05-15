#include<bits/stdc++.h>
using namespace std;

using edge_t = tuple<int, int, int, int>;

template<int MXV, int MXE>
struct MinCostMaxFlow {
    struct edge {
        int to, flow, cost;
        edge *rev;
        edge() {}
        edge(int t, int f, int c, edge *r) : to(t), flow(f), cost(c), rev(r) {}
    }Pool[MXE * 2 + 5], *G[MXV + 5], *cur[MXV + 5];
    int V, S, T, dis[MXV + 5];
    bool vis[MXV + 5];

    MinCostMaxFlow() {}
    MinCostMaxFlow(int V, const vector<edge_t> &E, int S, int T) : V(V), S(S), T(T) {
        static int deg[MXV + 5];
        for(const edge_t &val : E)
            ++deg[get<0>(val)], ++deg[get<1>(val)];
        G[1] = Pool;
        for(int i = 1; i <= V; i++)
            G[i + 1] = G[i] + deg[i];
        for(const edge_t &val : E) {
            int u, v, f, c;
            tie(u, v, f, c) = val;
            int e1 = --deg[u], e2 = --deg[v];
            G[u][e1] = edge(v, f, c, G[v] + e2);
            G[v][e2] = edge(u, 0, -c, G[u] + e1);
        }
    }
    bool spfa() {
        queue<int> Q;
        memset(vis + 1, 0, sizeof(bool) * V);
        memset(dis + 1, 0x3f, sizeof(int) * V);
        Q.push(S), dis[S] = 0, vis[S] = true;
        while(!Q.empty()) {
            int nw = Q.front();
            Q.pop(), vis[nw] = false;
            for(edge *i = G[nw]; i != G[nw + 1]; ++i)
                if(i -> flow && dis[i -> to] > dis[nw] + i -> cost) {
                    dis[i -> to] = dis[nw] + i -> cost;
                    if(!vis[i -> to])
                        Q.push(i -> to), vis[i -> to] = true;
                }
        }
        return dis[T] != 0x3f3f3f3f;
    }
    int dfs(int u, int mxflow) {
        if(!mxflow || u == T) return mxflow;
        int flow = 0, w;
        vis[u] = true;
        for(edge* &i = cur[u]; i != G[u + 1]; ++i)
            if(i -> flow && !vis[i -> to] && dis[i -> to] == dis[u] + i -> cost) {
                w = dfs(i -> to, min(mxflow - flow, i -> flow));
                flow += w, i -> flow -= w, i -> rev -> flow += w;
                if(flow == mxflow) break;
            }
        vis[u] = false;
        return flow;
    }
    int operator () () {
        int ans = 0;
        while(spfa()) {
            memcpy(cur + 1, G + 1, sizeof(edge*) * (V + 1));
            ans += dfs(S, INT_MAX) * dis[T];
        }
        return ans;
    }
};

#define ENDL "\n"
const int MX = 105;

pair<int, int> B[MX], S[MX];
int C[MX], W[MX], ans[MX][MX];

inline int distance(int b, int s) {
    return abs(B[b].first - S[s].first) + abs(B[b].second - S[s].second) + 1;
}

int main() {
    ifstream cin("evacuate.in");
    ofstream cout("evacuate.out");
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
        cin >> B[i].first >> B[i].second >> W[i];
    for(int i = 1; i <= M; i++)
        cin >> S[i].first >> S[i].second >> C[i];
    vector<edge_t> edge;
    for(int i = 1; i <= N; i++)
        edge.push_back({N + M + 1, i, W[i], 0});
    for(int i = 1; i <= M; i++)
        edge.push_back({N + i, N + M + 2, C[i], 0});
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            edge.push_back({i, N + j, INT_MAX, distance(i, j)});
    int res = 0;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++) {
            int val;
            cin >> val;
            res += val * distance(i, j);
        }
    MinCostMaxFlow<202, 10200> solve(N + M + 2, edge, N + M + 1, N + M + 2);
    if(res == solve())
        cout << "OPTIMAL" << ENDL;
    else {
        cout << "SUBOPTIMAL" << ENDL;
        for(int i = 1; i <= N; i++) {
            for(auto e = solve.G[i]; e != solve.G[i + 1]; ++e)
                if(e -> to > N && e -> to <= N + M)
                    ans[i][e -> to - N] = e -> rev -> flow;
            for(int j = 1; j <= M; j++)
                cout << ans[i][j] << ' ';
            cout << ENDL;
        }
    }
    return 0;
}
