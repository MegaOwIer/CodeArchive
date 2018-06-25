#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=1005,dx[]={0,1,0,-1},dy[]={1,0,-1,0};

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
	inline void getal(char& x){do x=getchar();while(!isalpha(x));}
}
using FastIO::read;
using FastIO::write;
using FastIO::getal;

int N,M,X1[MX],X2[MX],Y1[MX],Y2[MX];
LL dp[MX][MX];
char c;

inline int id(char c)
{
	if(c=='N')return 0;
	if(c=='E')return 1;
	if(c=='S')return 2;
	if(c=='W')return 3;
}
inline int sqr(int x){return x*x;}

int main()
{
	read(N),read(M),read(X1[0]),read(Y1[0]),read(X2[0]),read(Y2[0]);
	for(int i=1;i<=N;i++)
	{
		getal(c);
		X1[i]=X1[i-1]+dx[id(c)];
		Y1[i]=Y1[i-1]+dy[id(c)];
	}
	for(int i=1;i<=M;i++)
	{
		getal(c);
		X2[i]=X2[i-1]+dx[id(c)];
		Y2[i]=Y2[i-1]+dy[id(c)];
	}
	for(int i=0;i<=N;i++)for(int j=0;j<=M;j++)dp[i][j]=sqr(X1[i]-X2[j])+sqr(Y1[i]-Y2[j]);
	dp[0][0]=0;
	for(int i=2;i<=N;i++)dp[i][0]+=dp[i-1][0];
	for(int i=2;i<=M;i++)dp[0][i]+=dp[0][i-1];
	for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)
		dp[i][j]+=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
	write(dp[N][M]);
	return 0;
}
