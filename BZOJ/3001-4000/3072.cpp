#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;

int n,a[maxn],b[maxn],pos[maxn],dp[maxn];
char c;
vector<int> dif[maxn<<1];

inline void read(int& x)
{
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline int find(int id,int x)
{
	int l=0,r=dif[id].size()-1,res=-1,mid;
	while(l<=r)
	{
		mid=l+r>>1;
		if(dif[id][mid]<=x)res=mid,l=mid+1;
		else r=mid-1;
	}
	return ~res?dif[id][res]:0;
}
inline int Dp(int x,int y)
{
	if(!x||!y)return x+y;
	if(a[x]==b[y])return dp[x]?dp[x]:dp[x]=min(Dp(x-1,y),Dp(x,y-1))+1;
	int t=find(x-y+n,x);
	return t?Dp(t,y-x+t)+x-t:max(x,y);
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)read(b[i]),pos[b[i]]=i;
	for(int i=1;i<=n;i++)dif[n+i-pos[a[i]]].push_back(i);
	printf("%d",Dp(n,n));
	return 0;
}
