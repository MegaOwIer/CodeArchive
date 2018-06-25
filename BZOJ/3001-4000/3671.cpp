#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int buf[22],top;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do buf[top++]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[--top]);
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int maxn=5000;

int g[maxn+1][maxn+1],N,M,Q,MX,arr[maxn*maxn+1],ans[maxn<<1];
LL seed,a,b,c,d;
bool vis[maxn+1][maxn+1],fl;

inline LL rd(){return seed=(seed*seed*a+b*seed+c)%d;}

int main()
{
	read(seed),read(a),read(b),read(c),read(d),read(N),read(M),read(Q),MX=M*N;
	for(int i=1;i<=MX;i++)arr[i]=i,swap(arr[i],arr[rd()%i+1]);
	for(int i=1,x,y;i<=Q;i++)read(x),read(y),swap(arr[x],arr[y]);
	for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)g[i][j]=arr[(i-1)*M+j];
	for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)arr[g[i][j]]=(i-1)*M+j;
	for(int i=1,x,y;i<=MX;i++)
	{
		x=(arr[i]-1)/M+1,y=arr[i]-(x-1)*M;
		if(!vis[x][y])
		{
			if(fl)putchar(' ');
			write(i),fl=1;
			for(int j=x+1;j<=N;j++)for(int k=y-1;k;k--)
			{
				if(vis[j][k])break;
				vis[j][k]=1;
			}
			for(int j=x-1;j;j--)for(int k=y+1;k<=M;k++)
			{
				if(vis[j][k])break;
				vis[j][k]=1;
			}
		}
	}
	return 0;
}
