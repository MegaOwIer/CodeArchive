#include<bits/stdc++.h>
using namespace std;

int n,ans;

int main()
{
	scanf("%d",&n);
	while(n!=1)
	{
		if(n&1)n=n*3+1;
		else n>>=1;
		ans++;
	}
	printf("%d",ans);
	return 0;
}
