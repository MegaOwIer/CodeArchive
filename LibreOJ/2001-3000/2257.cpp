#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
const int mod=1000000007;

int N,G,L,Q,X,pr[12],pw[12],S,tot,dp[260][260],M;
map<int,pii> sta;
map<int,int> ans;

inline void read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void divide(int u)
{
	for(int i=2;i*i<=u;i++)if(u%i==0)
	{
		pr[tot]=i;
		while(u%i==0)u/=i,pw[tot]++;
		tot++;
	}
	if(u!=1)pr[tot]=u,pw[tot]=1,tot++;
	S=(1<<tot)-1;
}
void dfs(int pos,int now,int S1,int S2)
{
	if(now>N)return;
	if(pos==tot){sta[now]=make_pair(S1,S2);return;}
	int tmp=pr[pos];
	dfs(pos+1,now,S1|(1<<pos),S2);
	for(int i=1;i<pw[pos];i++,tmp*=pr[pos])
		dfs(pos+1,now*tmp,S1,S2);
	dfs(pos+1,now*tmp,S1,S2|(1<<pos));
}
inline void update(int& a,int b){a+=b;if(a>=mod)a-=mod;}

int main()
{
	read(N),read(G),read(L),read(Q);
	if(L%G)
	{
		while(Q--)puts("0");
		return 0;
	}
	N/=G,L/=G,divide(L),dfs(0,1,0,0);
	M=sta.size(),dp[0][0]=1;
	for(map<int,pii>::iterator i=sta.begin();i!=sta.end();++i)
		for(int S1=S;~S1;S1--)for(int S2=S;~S2;S2--)
			update(dp[S1|i->second.first][S2|i->second.second],dp[S1][S2]);
	for(map<int,pii>::iterator i=sta.begin();i!=sta.end();++i)
	{
		for(int S1=S;~S1;S1--)for(int S2=S;~S2;S2--)
			if((S1|i->second.first)==S&&(S2|i->second.second)==S)
				update(ans[i->first],dp[S1][S2]);
		ans[i->first]=(LL)ans[i->first]*500000004%mod;
	}
	for(int i=1;i<=Q;i++)
	{
		read(X);
		if(X%G||L%(X/G)){puts("0");continue;}
		printf("%d\n",ans[X/G]);
	}
	return 0;
}