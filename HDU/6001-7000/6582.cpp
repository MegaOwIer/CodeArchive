#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 10005;

long long dis[MX];
bool vis[MX];
vector<array<int, 2>> G[MX];

template<int V, int E>
struct MaxFlow {
	using LL = long long;
	struct edge_t {
		int to, nxt, f;
		edge_t() {}
		edge_t(int t, int n, int f) : to(t), nxt(n), f(f) {}
	};

	int tot, head[V + 1], cur[V + 1], dis[V + 1];
	bool vis[V + 1];
	edge_t e[E * 2 + 1];

	MaxFlow() {reset();}
	void reset(int v = V) {
		tot = 1;
		memset(head + 1, 0, sizeof(int[v]));
	}

	void add_edge(int u, int v, int f) {
		e[++tot] = edge_t(v, head[u], f), head[u] = tot;
		e[++tot] = edge_t(u, head[v], 0), head[v] = tot;
	}

	bool BFS(int S, int T) {
		queue<int> Q;
		memset(vis + 1, false, sizeof(bool[V]));
		memset(dis + 1, 0x3f, sizeof(int[V]));
		Q.push(S), vis[S] = true, dis[S] = 0;
		while(!Q.empty()) {
			int u = Q.front();
			Q.pop();
			for(int i = head[u]; i; i = e[i].nxt)
				if(!vis[e[i].to] && e[i].f) {
					Q.push(e[i].to), vis[e[i].to] = true;
					dis[e[i].to] = dis[u] + 1;
				}
		}
		return vis[T];
	}

	long long dfs(int u, LL flow, int T) {
		if(u == T || !flow) return flow;
		LL w, used = 0;
		for(int &i = cur[u]; i; i = e[i].nxt)
			if(dis[e[i].to] == dis[u] + 1 && e[i].f) {
				w = dfs(e[i].to, min<LL>(flow - used, e[i].f), T);
				e[i].f -= w, e[i ^ 1].f += w;
				used += w;
			}
		return used;
	}

	long long operator () (int S, int T) {
		long long ans = 0;
		while(BFS(S, T)) {
			memcpy(cur + 1, head + 1, sizeof(int[V]));
			ans += dfs(S, INT_MAX, T);
		}
		return ans;
	}
};

MaxFlow<10000, 10000> Dinic;

void Dijkstra(int n) {
	using data_t = pair<long long, int>;
	memset(vis + 1, false, sizeof(bool[n]));
	memset(dis + 1, 0x3f, sizeof(LL[n]));
	priority_queue<data_t, vector<data_t>, greater<data_t>> Q;
	Q.push({dis[1] = 0, 1});
	while(!Q.empty()) {
		int u = Q.top().second;
		Q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(auto &cur : G[u]) {
			int v = cur[0], w = cur[1];
			if(dis[v] > dis[u] + w)
				Q.push({dis[v] = dis[u] + w, v});
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; i++) G[i].clear();
		for(int i = 1; i <= m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			G[u].push_back({v, w});
		}
		Dijkstra(n);
		for(int i = 1; i <= n; i++)
			for(auto &cur : G[i])
				if(dis[i] + cur[1] == dis[cur[0]])
					Dinic.add_edge(i, cur[0], cur[1]);
		cout << Dinic(1, n) << "\n";
		Dinic.reset(n);
	}
	return 0;
}
