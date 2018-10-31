#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, int> edge_t;
const int MX = 100000 + 5, MK = 50 + 3;

int P, dis[MX], dp[MX][MK];
char vis[MX];
bool ins[6000050];
vector<edge_t> G[MX], G1[MX];

void init(int N, int K)
{
	memset(dis + 1, 0x3f, sizeof(int[N]));
	memset(vis + 1, 0, sizeof(char[N]));
	for (int i = 1; i <= N; i++)
	{
		G[i].clear();
		G1[i].clear();
	}
	G1[1].push_back(make_pair(0, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= N ; i++)
		memset(dp[i], -1, sizeof(int[K + 1]));
}

void Dijkstra()
{
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	Q.push(make_pair(dis[1] = 0, 1));
	while (!Q.empty())
	{
		pii cur = Q.top();
		Q.pop();
		int nw = cur.second, d = cur.first;
		if (vis[nw])
			continue;
		vis[nw] = true;
		for (vector<edge_t>::iterator it = G[nw].begin(); it != G[nw].end(); ++it)
			if (dis[it -> first] > d + it -> second)
			{
				dis[it -> first] = d + it -> second;
				Q.push(make_pair(dis[it -> first], it -> first));
			}
	}
}

bool dfs(int n, int k)
{
	int sta = n * 60 + k;
	if (ins[sta])
		return true;
	if (dp[n][k] != -1)
		return false;
	int &cur = dp[n][k];
	cur = 0;
	ins[sta] = true;
	for (vector<edge_t>::iterator it = G1[n].begin(); it != G1[n].end(); ++it)
	{
		int tmp = it -> second - dis[n] + dis[it -> first];
		if (tmp > k)
			continue;
		if (dfs(it -> first, k - tmp))
		{
			ins[sta] = false;
			return true;
		}
		cur = (cur + dp[it -> first][k - tmp]) % P;
	}
	ins[sta] = false;
	return false;
}

int work()
{
	int N, M, K, ans = 0;
	cin >> N >> M >> K >> P;
	init(N, K);
	while (M--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back(make_pair(b, c));
		G1[b].push_back(make_pair(a, c));
	}
	Dijkstra();
	for (int i = 0; i <= K; i++)
	{
		if(dfs(N, i))
			return -1;
		ans = (ans + dp[N][i]) % P;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
		cout << work() << "\n";
	return 0;
}
