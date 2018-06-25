#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=998244353,MX=100050;

namespace FastIO
{
    char c;
    int bf[22],tp;
    template<typename T>inline void read(T& x)
    {
        c=getchar(),x=0;
        while(!isdigit(c))c=getchar();
        while(isdigit(c))x=x*10+c-'0',c=getchar();
    }
    template<typename T>inline void write(T x)
    {
    	tp=0;
    	do bf[++tp]=x%10,x/=10;while(x);
    	while(tp)putchar(48+bf[tp--]);
    	putchar('\n');
    }
}
using FastIO::read;
using FastIO::write;

struct edge{int to,nxt;}e[MX<<1];
int N,K,tot=1,head[MX],val[MX],fa[MX],pre[MX],cnt,Num[1050],xxj[15],shu,hb[1050];
bool vis[MX],vise[MX];
int ans=1;

inline void add(int u,int v)
{
	e[++tot]=(edge){v,head[u]},head[u]=tot;
	e[++tot]=(edge){u,head[v]},head[v]=tot;
}
inline void dfs1(int u)
{
	vis[u]=1;
	for(int i=head[u],j;i;i=e[i].nxt)if(e[i].to!=fa[u]&&!vise[i>>1])
	{
		vise[i>>1]=1;
		if(vis[e[i].to])
		{
			val[i>>1]=1<<cnt;
			for(j=u;j!=e[i].to;j=fa[j])val[pre[j]]^=1<<cnt;
			cnt++;
		}
		else fa[e[i].to]=u,pre[e[i].to]=i>>1,dfs1(e[i].to);
	}
}
inline int insert(int x)
{
	++shu;
	for(int i=1,h1,h2;i<shu;i++)
	{
		h1=hb[x],h2=hb[xxj[i]];
		if(h1==h2)x^=xxj[i];
		else if(h1>h2)
			return memmove(xxj+i+1,xxj+i,sizeof(int)*(shu-i)),xxj[i]=x,i;
	}
	return xxj[shu]=x,shu;
}
inline bool check(int x)
{
	for(int i=1;x&&i<=shu;i++)if(hb[x]==hb[xxj[i]])x^=xxj[i];
	return x;
}
inline void dfs2(int nw,int k)
{
	ans=(ans+k)%mod;
	int pos=insert(val[nw]);
	for(int i=nw+1;i<=cnt;i++)if(check(val[i]))
		dfs2(i,(LL)k*Num[val[i]]%mod);
	memmove(xxj+pos,xxj+pos+1,sizeof(int)*(shu-pos));
	shu--;
}

int main()
{
	read(N),read(K),hb[1]=1;
	for(int i=2;i<1024;i++)hb[i]=hb[i>>1]<<1;
	for(int i=1,u,v;i<N;i++)read(u),read(v),add(u,v);
	for(int i=1,u,v;i<=K;i++)read(u),read(v),add(u,v);
	dfs1(1);
	for(int i=1;i<N+K;i++)if(val[i])Num[val[i]]++;
	sort(val+1,val+N+K,greater<int>());
	cnt=unique(val+1,val+N+K)-val-1;
	if(!val[cnt])cnt--;
	for(int i=1;i<=cnt;i++)dfs2(i,Num[val[i]]);
	write(ans);
	return 0;
}
