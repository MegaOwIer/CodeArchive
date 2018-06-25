#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n,s,l[20005],ans;

int main()
{
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)  scanf("%d",l+i);
	sort(l+1,l+n+1);
	for(int i=1;i<n;i++)  ans+=upper_bound(l+i+1,l+n+1,s-l[i])-l-i-1;
	printf("%d",ans);
	return 0;
}
