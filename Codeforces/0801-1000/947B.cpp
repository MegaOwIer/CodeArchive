#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=100005;

int N,tr[MX];
LL v[MX],t[MX],tmp[MX];

template<typename T>inline void read(T& x)
{
	static char c;
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void add(int u,int v)
{
	if(!u)return;
	for(;u<=N;u+=u&-u)tr[u]+=v;
}
inline int ask(int u){int ans=0;for(;u;u-=u&-u)ans+=tr[u];return ans;}

int main()
{
	read(N);
	for(int i=1;i<=N;i++)read(v[i]);
	for(int i=1;i<=N;i++)read(t[i]),t[i]+=t[i-1];
	for(int i=2;i<=N;i++)v[i]+=t[i-1];
	t[N+1]=1e18;
	for(int i=1,it;i<=N;i++)
	{
		it=upper_bound(t+1,t+N+1,v[i])-t;
		add(it,-1),add(i,1);
		tmp[it]+=v[i]-t[it-1];
	}
	for(int i=1;i<=N;i++)
		printf("%lld ",(t[i]-t[i-1])*ask(i)+tmp[i]);
	return 0;
}
