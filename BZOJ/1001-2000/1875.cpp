#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=45989;

struct edge {int to,next;}e[125];
struct matrix {LL a[125][125];}G,ans,mans;
int n,m,t,a,b,tot=1,head[21];
LL fin;
char c;

inline void add(int u,int v)
{
	e[++tot]=(edge){v,head[u]},head[u]=tot;
	e[++tot]=(edge){u,head[v]},head[v]=tot;
}
inline void read(int& x)
{
	x=0,c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}
inline matrix operator * (matrix a,matrix b)
{
	for(int i=1;i<=tot;i++)for(int j=1;j<=tot;j++)
	{
		mans.a[i][j]=0;
		for(int k=1;k<=tot;k++)mans.a[i][j]+=a.a[i][k]*b.a[k][j];
		mans.a[i][j]%=mod;
	}
	return mans;
}

int main()
{
	read(n),read(m),read(t),read(a),read(b),t--;
	for(int i=1,u,v;i<=m;i++)read(u),read(v),add(u,v);
	for(int i=1;i<=tot;i++)ans.a[i][i]=1;
	for(int i=2;i<=tot;i++)for(int j=head[e[i].to];j;j=e[j].next)if(j!=(i^1))G.a[i][j]=1;
	while(t)
	{
		if(t&1)ans=ans*G;
		G=G*G;
		t>>=1;
	}
	memset(G.a,0,sizeof(G.a));
	for(int i=head[a];i;i=e[i].next)G.a[1][i]=1;
	G=G*ans;
	for(int i=1;i<=tot;i++)if(e[i].to==b)fin=(fin+G.a[1][i])%mod;
	printf("%lld",fin);
	return 0;
}
