#include<bits/stdc++.h>
using namespace std;

int f,T,n,m,fa[105],delta[105];
char c;
bool fail;

inline void read(int& x)
{
	x=0,c=getchar(),f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
}
inline int find(int x)
{
	if(fa[x]==x)return x;
	int ans=find(fa[x]);
	delta[x]+=delta[fa[x]];
	return fa[x]=ans;
}

int main()
{
	read(T);
	while(T--)
	{
		read(n),read(m),fail=0;
		memset(delta,0,n+1<<2);
		for(int i=0;i<=n;i++)fa[i]=i;
		for(int i=1,s,t,v;i<=m;i++)
		{
			read(s),read(t),read(v);
			if(fail)continue;
			int f1=find(s-1),f2=find(t);
			if(f1!=f2)fa[f1]=f2,delta[f1]=delta[t]-delta[s-1]-v;
			else if(delta[t]-delta[s-1]!=v)fail=1;
		}
		puts(fail?"false":"true");
	}
	return 0;
}
