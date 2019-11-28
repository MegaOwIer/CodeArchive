#include<bits/stdc++.h>
using namespace std;

template<typename flow_t = int>
struct MaxFlow_ISAP {
	const flow_t MAX_VAL = numeric_limits<flow_t>::max();

	struct edge_t {
		int to, rev;
		flow_t f;
		edge_t() {}
		edge_t(int _t, int _r, flow_t _f) : to(_t), rev(_r), f(_f) {}
	};

	vector<vector<edge_t>> G;
	vector<typename vector<edge_t>::iterator> cur;
	int V;
	vector<int> gap, dep;

	MaxFlow_ISAP(int v) : G(v + 1), cur(v + 1), V(v) {}

	void add_edge(int u, int v, flow_t f) {
		G[u].emplace_back(v, G[v].size(), f);
		G[v].emplace_back(u, G[u].size() - 1, 0);
	}

	void BFS(int T) {
		gap.assign(V + 2, 0);
		dep.assign(V + 1, 0);
		queue<int> Q;
		Q.push(T), ++gap[dep[T] = 1];
		while(!Q.empty()) {
			int u = Q.front();
			Q.pop();
			for(edge_t &e : G[u]) {
				int v = e.to;
				if(dep[v]) continue;
				Q.push(v), ++gap[dep[v] = dep[u] + 1];
			}
		}
	}

	flow_t dfs(int u, flow_t flow, const int S, const int T) {
		if(u == T || !flow) return flow;
		flow_t w, used = 0;
		for(auto &i = cur[u]; i != G[u].end(); i++) {
			if(i -> f && dep[i -> to] == dep[u] - 1) {
				w = dfs(i -> to, min(flow - used, i -> f), S, T);
				i -> f -= w, G[i -> to][i -> rev].f += w;
				used += w;
			}
			if(used == flow) return flow;
		}
		if(!--gap[dep[u]]) dep[S] = V + 1;
		if(dep[u] <= V) ++dep[u];
		++gap[dep[u]], cur[u] = G[u].begin();
		return used;
	}

	flow_t operator () (int S, int T) {
		flow_t ans = 0;
		BFS(T);
		while(dep[S] <= V) {
			for(int i = 1; i <= V; i++) cur[i] = G[i].begin();
			ans += dfs(S, MAX_VAL, S, T);
		}
		return ans;
	}
};

const int MX = 705;

int A[MX], B[MX], C[MX];
int dp[MX], id[MX];

int read() {
	int x = 0, c = getchar();
	while(!isdigit(c)) c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	return x;
}

bool BFS(MaxFlow_ISAP<int> *ISAP, int S, int T) {
	static bool vis[MX << 1];
	memset(vis + 1, false, sizeof(bool[ISAP -> V]));
	queue<int> Q;
	Q.push(S), vis[S] = true;
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for(auto e : ISAP -> G[u])
			if(!vis[e.to] && e.f) Q.push(e.to), vis[e.to] = true;
	}
	return vis[T];
}

int main() {
	int cas = read();
	while(cas--) {
		int n = read();
		for(int i = 1; i <= n; i++) A[i] = read();
		for(int i = 1; i <= n; i++) B[i] = read();
		for(int i = 1; i <= n; i++) C[i] = read();
		
		for(int i = 1; i <= n; i++) {
			dp[i] = 1;
			for(int j = 1; j < i; j++)
				if(A[i] > A[j]) dp[i] = max(dp[i], dp[j] + 1);
		}

		int mxVal = *max_element(dp + 1, dp + n + 1);

		MaxFlow_ISAP<int> *ISAP = new MaxFlow_ISAP<int>(n + n + 2);
		int S = n + n + 1, T = n + n + 2;
		for(int i = 1; i <= n; i++) ISAP -> add_edge(i, i + n, B[i]);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j < i; j++)
				if(A[j] < A[i] && dp[j] + 1 == dp[i])
					ISAP -> add_edge(j + n, i, INT_MAX);
			if(dp[i] == 1) ISAP -> add_edge(S, i, INT_MAX);
			if(dp[i] == mxVal) ISAP -> add_edge(i + n, T, INT_MAX);
		}

		int ans = (*ISAP)(S, T);
		vector<int> res;

		for(int i = 1; i <= n; i++) id[i] = i;
		sort(id + 1, id + n + 1, [&](int u, int v){return C[u] < C[v];});
		for(int j = 1; j <= n; j++) {
			int i = id[j];
			MaxFlow_ISAP<int>::edge_t e = ISAP -> G[i].front();
			if(e.f != 0 || BFS(ISAP, i, i + n)) continue;
			ISAP -> G[i].begin() -> f = 0;
			ISAP -> G[i + n].begin() -> f = 0;
			(*ISAP)(i, S);
			(*ISAP)(T, i + n);
			res.push_back(i);
		}
		
		sort(res.begin(), res.end());
		printf("%d %d\n", ans, (int)res.size());
		for(int num : res) printf("%d ", num);
		putchar('\n');
		delete ISAP;
	}
	return 0;
}
