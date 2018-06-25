#include<bits/stdc++.h>
using namespace std;

int n,a,b,l,r,ans,mid;

int main()
{
	scanf("%d%d%d",&n,&a,&b);
	l=1,r=min(a,b);
	while(l<=r)
	{
		mid=l+r>>1;
		if((a/mid)+(b/mid)>=n)ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}
