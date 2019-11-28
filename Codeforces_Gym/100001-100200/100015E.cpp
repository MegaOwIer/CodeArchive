#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 505, MV = 124755;

struct Line {
	long long A, B, C; // Ax + By = C
	Line() {}
	Line(int x1, int y1, int x2, int y2) {
		A = y2 - y1;
		B = x1 - x2;
		C = x1 * y2 - x2 * y1;
	}
}L[MX];

int ID[MX][MX];
vector<pair<pair<double, double>, int>> P;
vector<int> G[MV];

int find(vector<int> vec, int val) {
	for(int u : vec)
		if(u == val) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	while(true) {
		int n;
		cin >> n;
		if(n == 0) break;
		for(int i = 1; i <= n; i++) {
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			L[i] = Line(x1, y1, x2, y2);
		}
		int cnt = 0;
		for(int i = 2; i <= n; i++)
			for(int j = 1; j < i; j++)
				ID[i][j] = ID[j][i] = ++cnt;
		for(int i = 1; i <= cnt; i++) G[i].clear();
		for(int i = 1; i <= n; i++) {
			P.clear();
			for(int j = 1; j <= n; j++) if(i != j) {
				LL D = L[i].A * L[j].B - L[i].B * L[j].A, 
				   X = L[i].C * L[j].B - L[i].B * L[j].C, 
				   Y = L[i].A * L[j].C - L[i].C * L[j].A;
				if(D == 0) continue;
				P.push_back({{(double)X / D, (double)Y / D}, ID[i][j]});
			}
			sort(P.begin(), P.end());
			for(size_t i = 1; i < P.size(); i++) {
				int u = P[i].second, v = P[i - 1].second;
				G[u].push_back(v);
				G[v].push_back(u);
			}
		}
		int ans = 0;
		for(int u = 1; u <= cnt; u++)
			for(size_t i = 0; i < G[u].size(); i++)
				for(size_t j = i + 1; j < G[u].size(); j++)
					ans += find(G[G[u][i]], G[u][j]);
		printf("%d\n", ans / 3);
	}
	return 0;
}
