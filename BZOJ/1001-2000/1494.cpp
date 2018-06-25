#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=65521,val[]={1,1,1,3,16,125};

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

int k,tot,cnt[6],status[55],hs[1<<15],dp[55],fa[6];
char vis[55];
struct Matrix
{
	LL val[55][55];
	
	Matrix(){memset(val,0,sizeof(val));}
	void init(){for(int i=0;i<tot;i++)val[i][i]=1;}
	LL* operator [] (int u){return val[u];}
	void operator *= (Matrix& a)
	{
		static Matrix ans;
		for(int i=0;i<tot;i++)for(int j=0;j<tot;j++)ans[i][j]=0;
		for(int i=0;i<tot;i++)for(int k=0;k<tot;k++)for(int j=0;j<tot;j++)
			ans[i][j]+=val[i][k]*a[k][j];
		for(int i=0;i<tot;i++)for(int j=0;j<tot;j++)val[i][j]=ans[i][j]%mod;
	}
	void Pow(LL m)
	{
		Matrix ans;
		ans.init();
		for(;m;m>>=1,*this*=*this)if(m&1)ans*=*this;
		*this=ans;
	}
}f;
LL ans,n;

inline void dfs(int sta,int dep)
{
	if(dep==k)
	{
		memset(cnt,0,sizeof(int)*k);
		for(int i=0;i<k;i++)cnt[sta>>(i*3)&7]++;
		dp[tot]=1;
		for(int i=0;i<k;i++)dp[tot]*=val[cnt[i]];
		status[tot]=sta,hs[sta]=tot++;
		return;
	}
	int tmp=-1;
	for(int i=0;i<dep;i++)tmp=max(tmp,sta>>(i*3)&7);
	for(int i=0;i<=tmp+1&&i<k;i++)dfs(sta<<3|i,dep+1);
}
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline int justify()
{
	memset(vis,0,sizeof(char)*k);
	int tot=0,sta=0;
	for(int i=k-1;~i;i--)if(!vis[i])
	{
		vis[i]=1,sta|=tot<<(i*3);
		for(int j=i-1;~j;j--)if(find(i+1)==find(j+1))
			vis[j]=1,sta|=tot<<(j*3);
		tot++;
	}
	return hs[sta];
}
inline void calc(int s,int sta)
{
	int f1,f2;
	for(int i=0;i<=k;i++)fa[i]=i;
	for(int i=0;i<k;i++)for(int j=i+1;j<k;j++)
		if((status[s]>>(i*3)&7)==(status[s]>>(j*3)&7))
			if((f1=find(i))!=(f2=find(j)))fa[f1]=f2;
	f2=find(k);
	for(int i=0;i<k;i++)if((sta>>i)&1)
	{
		if((f1=find(i))==f2)return;
		fa[f1]=f2;
	}
	for(int i=1;i<=k;i++)if(find(i)==find(0))
	{
		f[s][justify()]++;
		return;
	}
}

int main()
{
	read(k),read(n);
	dfs(0,0);
	for(int i=0;i<tot;i++)for(int j=0;j<(1<<k);j++)calc(i,j);
	f.Pow(n-k);
	for(int i=0;i<tot;i++)ans=(ans+dp[i]*f[i][0])%mod;
	write(ans);
	return 0;
}
