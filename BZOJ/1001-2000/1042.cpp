#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100005;

int c[5],tot,d[5],s;
LL ans,dp[maxn];
char ch;

inline void read(int& x)
{
	ch=getchar(),x=0;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
}
inline void dfs(int x,bool k,int val)
{
	if(val<0)return;
	if(x>4){ans-=(k?dp[val]:-dp[val]);return;}
	dfs(x+1,k^1,val-c[x]*(d[x]+1)),dfs(x+1,k,val);
}

int main()
{
	for(int i=1;i<5;i++)read(c[i]);read(tot),dp[0]=1;
	for(int i=1;i<5;i++)for(int j=c[i];j<=100000;j++)dp[j]+=dp[j-c[i]];
	while(tot--)
	{
		for(int i=1;i<5;i++)read(d[i]);read(s);
		ans=0,dfs(1,0,s),printf("%lld\n",ans);
	}
	return 0;
}
