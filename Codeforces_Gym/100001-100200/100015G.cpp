#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 1005;

bool inq[MX];
int vis[MX];
long long dis[MX];
vector<pair<int, int>> G[MX];

bool SPFA(int u, const int N) {
	queue<int> Q;
	Q.push(u), vis[u] = 1, dis[u] = 0, inq[u] = true;
	while(!Q.empty()) {
		int nw = Q.front();
		Q.pop(), inq[nw] = false;
		for(pair<int, int> &cur : G[nw]) {
			int v = cur.first;
			long long tmp = cur.second + dis[nw];
			if(tmp < dis[v]) {
				dis[v] = tmp;
				if(++vis[v] == N) return true;
				if(!inq[v]) Q.push(v), inq[v] = true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	while(true) {
		int n, m, Q;
		cin >> n >> m >> Q;
		if(n == 0 && m == 0 && Q == 0) break;
		int N = n + m;
		for(int i = 1; i <= N; i++) G[i].clear();
		for(int i = 1; i <= Q; i++) {
			int u, v, w;
			string op;
			cin >> u >> v >> op >> w;
			if(op == "<=")
				G[n + v].push_back({u, w});
			else
				G[u].push_back({n + v, -w});
		}
		memset(inq + 1, false, sizeof(bool[N]));
		memset(vis + 1, 0, sizeof(int[N]));
		memset(dis + 1, 0x3f, sizeof(LL[N]));
		bool ans = false;
		for(int i = 1; i <= N; i++) if(!vis[i])
			ans = ans || SPFA(i, N);
		puts(ans ? "Impossible" : "Possible");
	}
	return 0;
}
