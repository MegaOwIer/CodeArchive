#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;

struct Ques{int x,y,k;}q[maxn];
int T,fa[maxn<<1],n,cnt;
char c;
bool fail;
map<int,int> fl;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline bool operator < (Ques a,Ques b){return a.k>b.k;}

int main()
{
	read(T);
	while(T--)
	{
		read(n),fail=0,fl.clear(),cnt=0;
		for(int i=1,u,v,w;i<=n;i++)
		{
			read(u),read(v),read(w);
			u=fl[u]?fl[u]:fl[u]=++cnt;
			v=fl[v]?fl[v]:fl[v]=++cnt;
			q[i]=(Ques){u,v,w};
		}
		sort(q+1,q+n+1);
		for(int i=1;i<=cnt;i++)fa[i]=i;
		for(int i=1;i<=n&&!fail;i++)
		{
			int f1=find(q[i].x),f2=find(q[i].y);
			if(q[i].k)fa[f1]=f2;
			else if(f1==f2)fail=1;
		}
		puts(fail?"NO":"YES");
	}
	return 0;
}
