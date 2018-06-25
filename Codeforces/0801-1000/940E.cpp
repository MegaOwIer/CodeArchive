#include<bits/stdc++.h>
using namespace std;
const int MX=100005;
typedef long long LL;

int N,c,a[MX<<2];
LL ans,dp[MX],tmp;

inline void build(int l,int r,int id)
{
	if(l==r)
	{
		scanf("%d",a+id);
		ans+=a[id];
		return;
	}
	int mid=l+r>>1;
	build(l,mid,id<<1),build(mid+1,r,id<<1|1);
	a[id]=min(a[id<<1],a[id<<1|1]);
}
inline int query(int l,int r,int id,int L,int R)
{
	if(l<=L&&R<=r)return a[id];
	int mid=L+R>>1,ans=1e9;
	if(l<=mid)ans=min(ans,query(l,r,id<<1,L,mid));
	if(r>mid)ans=min(ans,query(l,r,id<<1|1,mid+1,R));
	return ans;
}

int main()
{
	scanf("%d%d",&N,&c);
	build(1,N,1);
	if(N<c)return printf("%lld\n",ans),0;
	for(int i=1,j=c;j<=N;i++,j++)dp[i]=query(i,j,1,1,N);
	for(int i=c+1;i<=N-c+1;i++)
		dp[i-c]=max(dp[i-c],dp[i-c-1]),dp[i]+=dp[i-c];
	for(int i=1;i<=N-c+1;i++)tmp=max(tmp,dp[i]);
	printf("%lld\n",ans-tmp);
	return 0;
}
