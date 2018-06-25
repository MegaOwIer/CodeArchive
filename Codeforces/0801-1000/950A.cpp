#include<bits/stdc++.h>
using namespace std;

int l,r,a,ans;

int main()
{
	scanf("%d%d%d",&l,&r,&a);
	if(l<r)swap(l,r);
	ans=2*r,l-=r;
	if(l<a)ans+=(l+a)/2*2;
	else ans+=a*2;
	printf("%d",ans);
	return 0;
}
