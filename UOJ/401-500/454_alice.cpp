#include<bits/stdc++.h>
using namespace std;

const int MX = 2005, X = 666, Y = 1332;

int n, m;
char s[MX];

inline char get_bit() {return getchar();}
inline void push_bit(char c) {putchar(c), fflush(stdout);}

void initialize()
{
	ifstream fin("alice.in");
	fin >> n >> m >> (s + 1);
}

void send_string(int l, int r)
{
	for(int i = l; i <= r; i++) push_bit(s[i]);
}

void interact(int l, int r)
{
	for(int i = l; i <= r; i++)
		if(get_bit() == '1') push_bit(s[i]);
		else fflush(stdout);
}

int main()
{
	initialize();
	string cur;
	cur.push_back(get_bit()), cur.push_back(get_bit());
	if(cur == "00")
		send_string(1, X), interact(X + 1, 2000);
	else if(cur == "01")
		interact(1, X), send_string(X + 1, Y), interact(Y + 1, 2000);
	else if(cur == "10")
		interact(1, Y), send_string(Y + 1, 2000);
	else assert(false);
	return 0;
}
