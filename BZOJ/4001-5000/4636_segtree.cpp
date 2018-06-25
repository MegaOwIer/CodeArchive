#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e7;

int n,a,b,k,val[maxn],son[maxn][2],cnt=1;
LL ans;
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline void insert(int l,int r,int x,int y,int k,int id)
{
	if(x>y)return;
	if(l==x&&r==y){val[id]=max(val[id],k);return;}
	int mid=l+r>>1;
	if(mid<x){if(!son[id][1])son[id][1]=++cnt;insert(mid+1,r,x,y,k,son[id][1]);}
	else if(mid>=y){if(!son[id][0])son[id][0]=++cnt;insert(l,mid,x,y,k,son[id][0]);}
	else
	{
		if(!son[id][0])son[id][0]=++cnt;insert(l,mid,x,mid,k,son[id][0]);
		if(!son[id][1])son[id][1]=++cnt;insert(mid+1,r,mid+1,y,k,son[id][1]);
	}
}
inline void dfs(int l,int r,int now,int id)
{
	now=max(now,val[id]);
	if(!son[id][0]&&!son[id][1]){ans+=(LL)(r-l+1)*now;return;}
	int mid=l+r>>1;
	if(son[id][0])dfs(l,mid,now,son[id][0]);
	else ans+=(LL)(mid-l+1)*now;
	if(son[id][1])dfs(mid+1,r,now,son[id][1]);
	else ans+=(LL)(r-mid)*now;
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a),read(b),read(k);
		insert(1,1e9,a,b-1,k,1);
	}
	dfs(1,1e9,0,1),printf("%lld",ans);
	return 0;
}
