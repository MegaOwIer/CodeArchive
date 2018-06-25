#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[12],f;
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar(),f=1;
		while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
		while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
	}
	template<typename T>
	inline void write(T x,int f=0)
	{
		top=0;
		if(x<0)putchar('-'),x=-x;
		do buf[top++]=x%10,x/=10;while(x);
		for(int i=top-1;~i;i--)putchar(buf[i]+48);
		if(f)putchar(f&1?' ':'\n');
	}
}
using FastIO::read;
using FastIO::write;
const int maxn=(1<<20)+4;

int n,m,B[2][105],F[2][105],f[105],dis[maxn],now,S,T;
char s[105];
bool inq[maxn];
queue<int> q;

int main()
{
	read(n),read(m),S=(1<<n)-1;
	for(int i=1;i<=m;i++)
	{
		read(f[i]);
		scanf("%s",s);
		for(int j=0;j<n;j++)
			if(s[j]=='+')B[0][i]|=1<<j;
			else if(s[j]=='-')B[1][i]|=1<<j;
		scanf("%s",s);
		for(int j=0;j<n;j++)
			if(s[j]=='+')F[1][i]|=1<<j;
			else if(s[j]=='-')F[0][i]|=1<<j;
	}
	memset(dis,-1,sizeof(dis)),dis[S]=0,q.push(S);
	while(!q.empty())
	{
		now=q.front(),q.pop(),inq[now]=0;
		for(int i=1;i<=m;i++)if(((~now)&B[0][i])==0&&(now&B[1][i])==0)
		{
			T=(now&(~F[0][i]))|F[1][i];
			if(!~dis[T]||dis[T]>dis[now]+f[i])
			{
				dis[T]=dis[now]+f[i];
				if(!inq[T])inq[T]=1,q.push(T);
			}
		}
	}
	write(~dis[0]?dis[0]:0);
	return 0;
}
