#include<bits/stdc++.h>
using namespace std;

const int MX = (1 << 17) + 5;

int cnt[7], siz[MX];
vector<int> G[MX];

int NoSolution() {
	puts("0\n");
	return 0;
}
int Solved(vector<int> val) {
	cout << val.size() << "\n";
	sort(val.begin(), val.end());
	for(int v : val) cout << v << ' ';
	return 0;
}

bool dfs2(int u, int f) {
	vector<int> sonsize;
	siz[u] = 1;
	for(int v : G[u]) if(v != f) {
		if(!dfs2(v, u))
			return false;
		siz[u] += siz[v];
		sonsize.push_back(siz[v]);
	}
	if(G[u].size() == 4) {
		++siz[u];
		sort(sonsize.begin(), sonsize.end());
		return sonsize[0] == sonsize[1] && sonsize[2] == sonsize[0] * 2 + 1;
	} else {
		assert(sonsize.size() == 2 || sonsize.empty());
		return sonsize.empty() || sonsize[0] == sonsize[1];
	}
}

bool check_leaf(int u, int v, int root) {
	static int cnt = 0;
	++cnt;
	G[u].push_back(v);
	G[v].push_back(u);
	if(dfs2(root, -1)) 
		return Solved({u}), true;
	else {
		G[u].pop_back();
		G[v].pop_back();
		return false;
	}
}
int solve_leave(int N) {
	int u = -1, v = -1;
	for(int i = 1; i <= N; i++)
		if(G[i].size() == 2) (u == -1 ? u : v) = i;
	if(check_leaf(u, N + 1, v) || check_leaf(v, N + 1, u)) return 0;
	else return NoSolution();
}

bool precheck_mid() {
	int val = cnt[1];
	return cnt[2] == 1 && cnt[4] == 1 && val == (val & -val);
}
int solve_mid(int N) {
	if(!precheck_mid())
		return NoSolution();
	int root = -1, fa = -1;
	for(int i = 1; i <= N; i++) {
		if(G[i].size() == 2) root = i;
		if(G[i].size() == 4) fa = i;
	}
	if(dfs2(root, -1)) return Solved({fa});
	else return NoSolution();
}

int fa[MX], dis[MX];
void dfs3(int u, int f) {
	for(int v : G[u]) if(v != f)
		fa[v] = u, dis[v] = dis[u] + 1, dfs3(v, u);
}
int solve_dep_2(int N) {
	dfs3(1, -1);
	int u = max_element(dis + 1, dis + N + 1) - dis;
	fa[u] = dis[u] = 0;
	dfs3(u, -1);
	int v = max_element(dis + 1, dis + N + 1) - dis;
	if(dis[v] % 2 == 0)
		return NoSolution();
	int k = dis[v] / 2;
	for(int i = 1; i <= k; i++) v = fa[v];
	bool ans = true;
	for(int node : G[v]) if(node != fa[v])
		ans = ans && dfs2(node, v);
	for(int node : G[fa[v]]) if(node != v)
		ans = ans && dfs2(node, fa[v]);
	if(ans)
		return Solved({v, fa[v]});
	else
		return NoSolution();
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int N = (1 << n) - 2;
	for(int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= N; i++) {
		if(G[i].size() >= 5)
			return NoSolution();
		cnt[G[i].size()]++;
	}
	switch(cnt[2]) {
		case 0:
			return solve_dep_2(N);
		case 1:
			return solve_mid(N);
		case 2:
			return solve_leave(N);
		default:
			return NoSolution();
	}
	assert(false);
	return 0;
}
