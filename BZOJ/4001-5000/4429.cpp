#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int f,top,buf[22]; 
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar(),f=1;
		while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
		while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
	}
	template<typename T>inline void write(T x,int f=0)
	{
		if(x<0)putchar('-'),x=-x;
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar(f?'\n':' ');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int maxn=2505;

int a[maxn],b[maxn],n,cnt,ans,vis[maxn],T,lt[maxn];
LL res[maxn*3];
vector<int> g[maxn*3];

inline bool find(int x)
{
	for(vector<int>::iterator it=g[x].begin();it!=g[x].end();++it)if(vis[*it]!=T)
	{
		vis[*it]=T;
		if(!lt[*it]||find(lt[*it]))return lt[*it]=x,1;
	}
	return 0;
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i]),read(b[i]);
		res[++cnt]=a[i]+b[i];
		res[++cnt]=a[i]-b[i];
		res[++cnt]=(LL)a[i]*b[i];
	}
	sort(res+1,res+cnt+1),cnt=unique(res+1,res+cnt+1)-res-1;
	for(int i=1;i<=n;i++)
	{
		g[lower_bound(res+1,res+cnt+1,a[i]+b[i])-res].push_back(i);
		g[lower_bound(res+1,res+cnt+1,a[i]-b[i])-res].push_back(i);
		g[lower_bound(res+1,res+cnt+1,(LL)a[i]*b[i])-res].push_back(i);
	}
	for(int i=1;i<=cnt;i++)if(++T,find(i))ans++;
	if(ans<n)return puts("impossible"),0;
	for(int i=1;i<=n;i++)
	{
		write(a[i]);
		if(a[i]+b[i]==res[lt[i]])putchar('+');
		else if(a[i]-b[i]==res[lt[i]])putchar('-');
		else if((LL)a[i]*b[i]==res[lt[i]])putchar('*');
		putchar(' '),write(b[i]),putchar('='),putchar(' '),write(res[lt[i]],1);
	}
	return 0;
}
