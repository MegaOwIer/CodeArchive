#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[22];
	template<typename T>inline void IN(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void OUT(T x,int f=0)
	{
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar(f?'\n':' ');
	}
}
using FastIO::IN;
using FastIO::OUT;
typedef long long LL;
const int N=405;

int m,n,e,g[N][N],x,y,z,Lx[N],Ly[N],L[N],R[N],h,t,q[N],slk[N],pre[N];
bool S[N],T[N];
LL ans;

inline void calc(int x){for(;x;swap(x,L[pre[x]]))R[x]=pre[x];}
inline void work(int u)
{
	int tmp;
	for(int i=1;i<=n;i++)S[i]=T[i]=0,slk[i]=2147483647;
	S[u]=1,q[h=t=1]=u;
	while(1)
	{
		while(h<=t)
		{
			x=q[h++];
			for(y=1;y<=n;y++)if(!T[y])
				if(g[x][y]==Lx[x]+Ly[y])
				{
					T[y]=1,pre[y]=x;
					if(!R[y])return calc(y);
					q[++t]=R[y],S[R[y]]=1;
				}
				else if(Lx[x]+Ly[y]-g[x][y]<slk[y])
					pre[y]=x,slk[y]=Lx[x]+Ly[y]-g[x][y];
		}
		tmp=2147483647;
		for(int i=1;i<=n;i++)if(!T[i])tmp=min(tmp,slk[i]);
		for(int i=1;i<=n;i++)
		{
			if(S[i])Lx[i]-=tmp;
			if(T[i])Ly[i]+=tmp;else slk[i]-=tmp;
		}
		for(int i=1;i<=n;i++)if(!T[i]&&!slk[i])
		{
			T[i]=1;
			if(!R[i])return calc(i);
			q[++t]=R[i],S[R[i]]=1;
		}
	}
}

int main()
{
	IN(m),IN(n),IN(e),n=max(n,m);
	while(e--)IN(x),IN(y),IN(z),g[x][y]=z;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		Lx[i]=max(Lx[i],g[i][j]);
	for(int i=1;i<=n;i++)work(i);
	for(int i=1;i<=n;i++)ans+=Lx[i]+Ly[i];
	OUT(ans,1);
	for(int i=1;i<=m;i++)OUT(g[i][L[i]]?L[i]:0);
	return 0;
}
