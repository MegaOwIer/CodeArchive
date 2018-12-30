#include<bits/stdc++.h>
using namespace std;

/*----------------- Templates Begin ----------------------------*/

template<typename char_t = char, int MX = 2000000>
struct Istream {
private:
	FILE *F;
	char_t bf[MX], *p1, *p2;
	int getchar() {
		return p1 == p2 && (p2 = (p1 = bf) + fread(bf, sizeof(char_t), MX, F)) == p1 ? EOF : int(*p1++);
	}
public:
	Istream() : F(stdin), p1(bf), p2(bf) {}
	Istream(FILE *F) : F(F), p1(bf), p2(bf) {}
	Istream(string f) : F(fopen(f.c_str(), "r")), p1(bf), p2(bf) {}
	~Istream() {fclose(F);}
	Istream& operator >> (char_t &c) {return c = getchar(), *this;}
	Istream& operator >> (int &x) {
		int f = 1, c;
		x = 0;
		while(!isdigit(c = getchar()))
			if(c == '-') f = -1;
		while(isdigit(c))
			x = x * 10 + c - '0', c = getchar();
		return x *= f, *this;
	}
};

template<typename char_t = char, int MX = 2000000>
struct Ostream {
private:
	FILE *F;
	char_t bf[MX], *p1, *const p2;
	void putchar(int x) {*p1++ = x; if(p1 == p2) flush();}
public:
	Ostream() : F(stdout), p1(bf), p2(bf + MX) {}
	Ostream(FILE *F) : F(F), p1(bf), p2(bf + MX) {}
	Ostream(string f) : F(fopen(f.c_str(), "w")), p1(bf), p2(bf + MX) {}
	~Ostream() {flush(), fclose(F);}
	Ostream& operator << (char_t &c) {return putchar(c), *this;}
	Ostream& operator << (int x) {
		static char dig[12], *top = dig;
		if(x < 0) putchar('-'), x = -x;
		do *top++ = '0' + x % 10;
		while(x /= 10);
		while(top != dig) putchar(*--top);
		return *this;
	}
    Ostream& operator << (const char *s) {
		while(*s) putchar(*s++);
		return *this;
	}
	void flush() {fwrite(bf, sizeof(char_t), p1 - bf, F), p1 = bf;}
};

/*----------------- Templates End ----------------------------*/

using edge_t = pair<int, int>;
const int MX = 100005;

int dis[MX], dp[MX][53], p;
char vis[MX], ins[5500053];
vector<edge_t> G1[MX], G2[MX];
Istream<char> fin;
Ostream<char> fout;

void Dijkstra(int n)
{
	using pii = pair<int, int>;
	priority_queue<pii, vector<pii>, greater<pii>> Q;
    memset(dis + 1, 0x3f, sizeof(int[n]));
	memset(vis + 1, 0, sizeof(char[n]));
	Q.push({dis[1] = 0, 1});
	while(!Q.empty())
	{
		int u = Q.top().second;
		Q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto &e : G1[u])
			if(dis[e.first] > dis[u] + e.second)
				Q.push({dis[e.first] = dis[u] + e.second, e.first});
	}
}

bool Dp(int n, int k)
{
	int sta = n * 55 + k;
	if(ins[sta]) return true;
	if(dp[n][k] != -1) return false;
	int &cur = dp[n][k];
	cur = 0;
	ins[sta] = true;
	for(auto &e : G2[n])
	{
		int tmp = dis[n] + k - dis[e.first] - e.second;
		if(tmp < 0) continue;
		if(Dp(e.first, tmp))
			return ins[sta] = false, true;
		cur = (cur + dp[e.first][tmp]) % p;
	}
	return ins[sta] = false;
}

int work()
{
    int n, m, k, ans = 0;
    fin >> n >> m >> k >> p;
    for(int i = 1; i <= n; i++)
        G1[i].clear(), G2[i].clear();
    for(int i = 1, u, v, w; i <= m; i++)
    {
        fin >> u >> v >> w;
        G1[u].push_back({v, w});
        G2[v].push_back({u, w});
    }
    Dijkstra(n);
	memset(ins + 1, 0, sizeof(char[5500050]));
	for(int i = 1; i <= n; i++)
		memset(dp[i], -1, sizeof(int[k + 1]));
	G2[1].push_back({0, 0});
	dp[0][0] = 1;
	for(int i = 0; i <= k; i++)
	{
		if(Dp(n, i)) return -1;
		ans = (ans + dp[n][i]) % p;
	}
	return ans;
}

int main()
{
    int T;
    fin >> T;
    while(T--)
        fout << work() << "\n";
    return 0;
}
