#include<bits/stdc++.h>
using namespace std;

const int MX = 2005, X = 666, Y = 1332;

int n, m, pos[MX >> 1], cnt[MX];
string ans;

inline char get_bit() {return getchar();}
inline void push_bit(char c) {putchar(c), fflush(stdout);}

void initialize()
{
	ifstream fin("bob.in");
	fin >> n >> m;
	for(int i = 1; i <= n; i++)
		fin >> pos[i], cnt[pos[i]] = 1;
	for(int i = 1; i <= 2000; i++)
		cnt[i] += cnt[i - 1];
}

void receive_string(int l, int r)
{
	for(int i = l; i <= r; i++)
		if(cnt[i]) ans.push_back(get_bit());
		else get_bit();
}

void interact(int l, int r)
{
	for(int i = l; i <= r; i++)
	{
		push_bit('0' + cnt[i]);
		if(cnt[i]) ans.push_back(get_bit());
	}
}

void push_answer()
{
	ofstream fout("bob.out");
	fout << ans << endl;
}

int main()
{
	initialize();
	int c1 = cnt[X], c2 = cnt[Y] - cnt[X], c3 = n - cnt[Y];
	int mx = max({c1, c2, c3});
	memset(cnt + 1, 0, sizeof(int[2000]));
	for(int i = 1; i <= n; i++) cnt[pos[i]] = 1;
	if(c1 == mx)
	{
		push_bit('0'), push_bit('0');
		receive_string(1, X);
		interact(X + 1, 2000);
	}
	else if(c2 == mx)
	{
		push_bit('0'), push_bit('1');
		interact(1, X);
		receive_string(X + 1, Y);
		interact(Y + 1, 2000);
	}
	else
	{
		push_bit('1'), push_bit('0');
		interact(1, Y);
		receive_string(Y + 1, 2000);
	}
	push_answer();
	return 0;
}
