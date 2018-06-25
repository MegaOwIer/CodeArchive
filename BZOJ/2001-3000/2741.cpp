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
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int maxn=12005;

int n,m,a[maxn],blc,pos[maxn],root[maxn],son[maxn<<5][2],tot,id[maxn<<5];
unsigned l,r,ans,dp[120][maxn];

inline void insert(int pre,int now,int val)
{
	root[now]=++tot,id[tot]=now,pre=root[pre];
	for(int i=30,j,k=root[now];~i;i--)
	{
		j=(val>>i)&1;
		son[k][j^1]=son[pre][j^1];
		son[k][j]=++tot,id[tot]=now;
		pre=son[pre][j],k=son[k][j];
	}
}
inline unsigned query(int l,int r,int x)
{
	unsigned ans=0,tmp=root[r];
	for(int i=30,j;~i;i--)
	{
		if(id[tmp]<l)break;
		j=(x>>i)&1;
		if(id[son[tmp][j^1]]>=l)ans|=1<<i,j^=1;
		tmp=son[tmp][j];
	}
	return ans;
}

int main()
{
	read(n),read(m),blc=sqrt(n);
	for(int i=1;i<=n;i++)pos[i]=(i-1)/blc+1;
	id[0]=-1,insert(0,0,0);
	for(int i=1;i<=n;i++)read(a[i]),a[i]^=a[i-1],insert(i-1,i,a[i]);
	for(int i=1;i<=pos[n];i++)for(int j=(i-1)*blc+1;j<=n;j++)
		dp[i][j]=max(dp[i][j-1],query((i-1)*blc+1,j,a[j]));
	while(m--)
	{
		read(l),read(r),l=(l+ans)%n+1,r=(r+ans)%n+1;
		if(l>r)swap(l,r);
		ans=0,l--;
		if(pos[l]==pos[r])for(int i=l;i<=r;i++)ans=max(ans,query(l,r,a[i]));
		else
		{
			ans=dp[pos[l]+1][r];
			for(int i=l;pos[i]==pos[l];i++)ans=max(ans,query(l,r,a[i]));
		}
		write(ans);
	}
	return 0;
}
