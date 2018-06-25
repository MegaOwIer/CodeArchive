#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[20];
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		if(x<0)putchar('-'),x=-x;
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int maxn=1e7+5;

int pr[664600],cnt,miu[maxn],T,n,ans[maxn],tmp,d[maxn],a[25],f[maxn];
bool vis[maxn];

inline int dfs(int k,int x,int v)
{
	if(k>tmp)return f[x]+=v,miu[x]*f[x];
	return dfs(k+1,x*a[k],v)+dfs(k+1,x,v);
}

int main()
{
	miu[1]=1;
	for(int i=2,cc;i<=1e7;i++)
	{
		if(!vis[i])pr[++cnt]=i,miu[i]=-1,d[i]=i;
		for(int j=1;j<=cnt&&(cc=i*pr[j])<=1e7;j++)
		{
			vis[cc]=1,d[cc]=pr[j];
			if(i%pr[j]==0){miu[cc]=0;break;}
			miu[cc]=-miu[i];
		}
	}
	for(int i=1,j=1;i<=1e7;j=++i)
	{
		ans[i]=ans[i-1];
		if(miu[i])
		{
			tmp=0;
			while(j>1)a[++tmp]=d[j],j/=d[j];
			ans[i]+=miu[i]*dfs(1,1,miu[i]);
		}
	}
	read(T);
	while(T--)read(n),write(ans[n]);
	return 0;
}
