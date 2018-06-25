#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=300005,MV=1e6+5;

int N,M,a[MX],pr[MV],d[MV],f[MV],cnt,nxt[MX];
LL tr[MX];

inline void add(int u,int v){for(;u<=N;u+=u&-u)tr[u]+=v;}
inline int find(int u){return u==nxt[u]?u:nxt[u]=find(nxt[u]);}
inline LL ask(int u){LL ans=0;for(;u;u-=u&-u)ans+=tr[u];return ans;}

int main()
{
	ios::sync_with_stdio(0);
	cin>>N>>M;
	f[1]=d[1]=1;
	for(int i=2,tmp,j;i<=1e6;i++)
	{
		if(!d[i])pr[++cnt]=i,d[i]=i,f[i]=2;
		for(j=1;j<=cnt&&(tmp=i*pr[j])<=1e6;j++)
		{
			if(i%pr[j]==0)
			{
				d[tmp]=pr[j]*d[i];
				f[tmp]=f[i/d[i]]*(f[d[i]]+1);
				break;
			}
			d[tmp]=pr[j],f[tmp]=f[i]<<1;
		}
	}
	for(int i=1;i<=N;i++)
	{
		cin>>a[i];
		add(i,a[i]);
		if(f[a[i]]==a[i])nxt[i]=i+1;
		else nxt[i]=i;
	}
	nxt[N+1]=N+1;
	for(int i=1,op,l,r;i<=M;i++)
	{
		cin>>op>>l>>r;
		if(op&1)for(int j=find(l);j<=r;j=find(j+1))
		{
			add(j,f[a[j]]-a[j]),a[j]=f[a[j]];
			if(a[j]==f[a[j]])nxt[j]=nxt[j]+1;
		}
		else printf("%lld\n",ask(r)-ask(l-1));
	}
	return 0;
}
