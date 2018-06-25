#include<bits/stdc++.h>
using namespace std;
const int MX=1005;

int T,n,a[MX];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)printf(i==n?"%d\n":"%d ",a[i]);
	}
	return 0;
}
