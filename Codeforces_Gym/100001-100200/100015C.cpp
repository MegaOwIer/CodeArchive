#include<bits/stdc++.h>
using namespace std;

#define ENDL "\n"
using edge_t = tuple<int, int, int>;
const int MX = 100005;

int fa[19][MX], dep[MX], top[MX], dis[MX];
int length, lth[MX];
bool ins[MX];
vector<edge_t> G[MX];

void dfs1(int u, int from) {
	static int *fa = ::fa[0];
	ins[u] = true;
	for(edge_t &cur : G[u]) {
		int v, w, id;
		tie(v, w, id) = cur;
		if(id == from) continue;
		if(ins[v]) {
			length = w + dep[u] - dep[v];
			for(int i = u; i != v; i = fa[i])
				lth[i] = dep[i] - dep[v];
			lth[v] = 0;
		} else if(lth[v] == -1) {
			fa[v] = u, dep[v] = dep[u] + w;
			dfs1(v, id);
		}
	}
	ins[u] = false;
}

void dfs2(int u, int f, int t) {
	top[u] = t;
	for(int i = 1; (1 << i) <= dep[u]; i++)
		fa[i][u] = fa[i - 1][fa[i - 1][u]];
	for(edge_t &cur : G[u]) {
		int v, w, id;
		tie(v, w, id) = cur;
		if(v == f || lth[v] != -1) continue;
		fa[0][v] = u;
		dep[v] = dep[u] + 1;
		dis[v] = dis[u] + w;
		dfs2(v, u, t);
	}
}

inline int getDis(int u, int v) {
	int ans = abs(lth[u] - lth[v]);
	return min(ans, length - ans);
}

int getLCA(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	for(int i = 17; i >= 0; i--)
		if((1 << i) <= dep[u] - dep[v]) u = fa[i][u];
	if(u == v) return v;
	for(int i = 17; i >= 0; i--)
		if(fa[i][u] != fa[i][v])
			u = fa[i][u], v = fa[i][v];
	return fa[0][u];
}

int main() {
	ios::sync_with_stdio(false);
	int N, Q;
	while(cin >> N, N) {
		memset(dis + 1, 0, sizeof(int[N]));
		memset(lth + 1, -1, sizeof(int[N]));
		memset(dep + 1, 0, sizeof(int[N]));
		memset(ins + 1, false, sizeof(bool[N]));
		for(int i = 1; i <= N; i++) G[i].clear();
		for(int i = 0; (1 << i) <= N; i++)
			memset(fa[i] + 1, 0, sizeof(int[N]));
		for(int i = 1; i <= N; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			++u, ++v;
			G[u].push_back({v, w, i});
			G[v].push_back({u, w, i});
		}
		dfs1(1, 0);
		memset(dep + 1, 0, sizeof(int[N]));
		memset(fa[0] + 1, 0, sizeof(int[N]));
		for(int i = 1; i <= N; i++)
			if(lth[i] != -1) dfs2(i, 0, i);
		cin >> Q;
		while(Q--) {
			int u, v;
			cin >> u >> v;
			++u, ++v;
			if(top[u] != top[v]) {
				cout << dis[u] + dis[v] + getDis(top[u], top[v]) << ENDL;
			} else {
				cout << dis[u] + dis[v] - 2 * dis[getLCA(u, v)] << ENDL;
			}
		}
	}
	return 0;
}
