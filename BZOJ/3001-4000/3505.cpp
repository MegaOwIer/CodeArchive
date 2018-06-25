#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n,m;
LL ans,tot;

inline int gcd(int x,int y){return y?gcd(y,x%y):x;}

int main()
{
	scanf("%d%d",&n,&m),n++,m++,tot=1LL*n*m;
	ans=tot*(tot-1)*(tot-2)/6-(LL)m*n*(n-1)*(n-2)/6-(LL)m*n*(m-1)*(m-2)/6;
	for(int i=1;i<n;i++)for(int j=1;j<m;j++)
	{
		int tmp=gcd(i,j)-1;
		if(tmp>0)ans-=2LL*tmp*(n-i)*(m-j);
	}
	printf("%lld",ans);
	return 0;
}
