#include<bits/stdc++.h>
using namespace std;
const int MX=1000005;

int ans,N,M,sum;
char vis[MX];

int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1,u;i<=N;i++)
		scanf("%d",&u),sum+=u,vis[sum]=1;
	sum=0;
	for(int i=1,u;i<=M;i++)
		scanf("%d",&u),sum+=u,ans+=vis[sum];
	printf("%d",ans);
	return 0;
}
