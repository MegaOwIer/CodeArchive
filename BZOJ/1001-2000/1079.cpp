#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=1e9+7;

int k,x[6];
LL ans[16][16][16][16][16][6];
bool vis[16][16][16][16][16][6];

inline LL dp(int a,int b,int c,int d,int e,int f)
{
	if(vis[a][b][c][d][e][f])return ans[a][b][c][d][e][f];
	if(a+b+c+d+e==0)return 1;
	LL t=0;
	if(a)t+=dp(a-1,b,c,d,e,1)*(a-(f==2));
	if(b)t+=dp(a+1,b-1,c,d,e,2)*(b-(f==3));
	if(c)t+=dp(a,b+1,c-1,d,e,3)*(c-(f==4));
	if(d)t+=dp(a,b,c+1,d-1,e,4)*(d-(f==5));
	if(e)t+=dp(a,b,c,d+1,e-1,5)*e;
	vis[a][b][c][d][e][f]=1;
	return ans[a][b][c][d][e][f]=t%mod;
}

int main()
{
	scanf("%d",&k);
	for(int i=1,u;i<=k;i++)scanf("%d",&u),x[u]++;
	printf("%lld",dp(x[1],x[2],x[3],x[4],x[5],0));
	return 0;
}
