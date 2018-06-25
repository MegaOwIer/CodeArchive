#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MX=30005;

namespace FastIO
{
	char c;
	int tp,bf[22];
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		tp=0;
		do bf[++tp]=x%10,x/=10;while(x);
		while(tp)putchar(48+bf[tp--]);
	}
}
using FastIO::read;
using FastIO::write;

int N,L,S;
ULL pre[MX][205],suf[MX][205];
LL ans;
char s[MX][205];
pair<ULL,ULL> ha[MX];

int main()
{
	read(N),read(L),read(S);
	for(int i=1,j;i<=N;i++)
	{
		scanf("%s",s[i]+1);
		for(j=1;j<=L;j++)pre[i][j]=pre[i][j-1]*129+s[i][j];
		for(j=L;j;j--)suf[i][j]=suf[i][j+1]*129+s[i][j];
	}
	for(int i=1;i<=L;i++)
	{
		for(int j=1;j<=N;j++)ha[j]=make_pair(pre[j][i-1],suf[j][i+1]);
		sort(ha+1,ha+N+1);
		for(int j=1,k;j<=N;j=k)
		{
			for(k=j;ha[k]==ha[j]&&k<=N;k++);
			ans+=(LL)(k-j)*(k-j-1)/2;
		}
	}
	write(ans);
	return 0;
}