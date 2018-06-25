#include<bits/stdc++.h>
using namespace std;
const int mod=31011;

struct edge{int u,v,w;}e[1005];
int n,m,head[105],tot,fa[105],res,tmp[105],kd,pans,ans=1;
char c;
map<int,int> cnt;
bool fail;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline bool operator < (edge a,edge b){return a.w<b.w;}
inline int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
inline int digit(int x){pans=0;for(;x;x-=(x&-x),pans++);return pans;}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)read(e[i].u),read(e[i].v),read(e[i].w);
	sort(e+1,e+m+1);
	for(int i=1;i<=m&&res<n-1;i++)
	{
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1!=f2)fa[f1]=f2,cnt[e[i].w]++,res++;
	}
	if(res<n-1)return puts("0"),0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,j;i<=m;i=j+1)
	{
		for(j=i;e[j].w==e[j+1].w;j++);
		if(!cnt[e[i].w])continue;
		memcpy(tmp+1,fa+1,n<<2);
		kd=0;
		for(int S=1;S<(1<<j-i+1);S++)if(digit(S)==cnt[e[i].w])
		{
			memcpy(fa+1,tmp+1,n<<2),fail=0;
			for(int k=i;k<=j;k++)if(S&(1<<k-i))
			{
				int f1=find(e[k].u),f2=find(e[k].v);
				if(f1==f2){fail=1;break;}
				fa[f1]=f2;
			}
			if(!fail)kd++;
		}
		ans=ans*kd%mod;
		memcpy(fa+1,tmp+1,n<<2);
		for(int k=i;k<=j;k++)
		{
			int f1=find(e[k].u),f2=find(e[k].v);
			if(f1!=f2)fa[f1]=f2;
		}
	}
	printf("%d",ans);
	return 0;
}
