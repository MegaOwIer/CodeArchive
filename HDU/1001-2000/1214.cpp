#include<bits/stdc++.h>
using namespace std;

int n,res;

int main()
{
	while(~scanf("%d",&n))
	{
		res=n/2,n-=res;
		printf("%d\n",res*(res-1)/2+n*(n-1)/2);
	}
	return 0;
}
