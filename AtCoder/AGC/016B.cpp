#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
 
int n,a[maxn],mx,cnt;
bool fail;
 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1),mx=a[n]; 
	if(a[n]-a[1]>1)return puts("No"),0;
	if(a[1]==a[n])if(mx==n-1||2*mx<=n)return puts("Yes"),0;
	if(a[n]!=a[1])
	{
		for(cnt=1;a[cnt]==a[1];cnt++);cnt--;
		if(cnt>a[1])return puts("No"),0;
		mx-=cnt,n-=cnt;
		if(mx*2<=n)return puts("Yes"),0;
	}
	return puts("No"),0;
}
