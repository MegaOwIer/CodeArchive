#include<bits/stdc++.h>
using namespace std;

int n,a,odd=20000,sum;

inline int read()
{
	int ans=0;  char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch<='9'&&ch>='0')ans=ans*10+ch-'0',ch=getchar();
	return ans;
}

int main()
{
	n=read();
	if(n==1)
	{
		a=read();
		if(a&1)puts("NIESTETY");
		else printf("%d",a);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			a=read();
			if((a&1)&&a<odd)odd=a;
			sum+=a;
		}
		if(sum&1)sum-=odd;
		printf("%d",sum);
	}
	return 0;
}
