#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;

using Heap = __gnu_pbds::priority_queue<int, less<int>, __gnu_pbds::pairing_heap_tag>;

const int MX = 100005;

int fa[MX];
Heap G[MX];

int find(int u) {return u == fa[u] ? u : fa[u] = find(fa[u]);}

int main() {
	ios::sync_with_stdio(false);
	int n;
	while(cin >> n) {
		for(int i = 1; i <= n; i++) {
			int val;
			cin >> val;
			G[i].clear();
			G[i].push(val);
			fa[i] = i;
		}
		int Q;
		cin >> Q;
		while(Q--) {
			int u, v;
			cin >> u >> v;
			u = find(u), v = find(v);
			if(u == v) cout << -1 << "\n";
			else {
				int mxU = G[u].top() / 2, mxV = G[v].top() / 2;
				G[u].pop(), G[v].pop();
				if(G[u].size() < G[v].size()) swap(u, v);
				G[u].join(G[v]);
				G[v].clear();
				fa[v] = u;
				G[u].push(mxU), G[u].push(mxV);
				cout << G[u].top() << "\n";
			}
		}
	}
	return 0;
}
