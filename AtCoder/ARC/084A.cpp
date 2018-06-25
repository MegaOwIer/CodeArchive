#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;

int n,a[maxn],b[maxn],c[maxn];
LL res,ans[maxn];
char ch;

inline void read(int& x)
{
	x=0,ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++)read(b[i]);sort(b+1,b+n+1,greater<int>());
	for(int i=1;i<=n;i++)read(c[i]);sort(c+1,c+n+1,greater<int>());
	c[0]=b[0]=1e9+5;
	for(int i=1,it=0;i<=n;i++)
	{
		while(c[it]>b[i]&&it<=n)it++;
		ans[i]=it-1;
	}
	for(int i=1;i<=n;i++)ans[i]+=ans[i-1];
	for(int i=1,it=0;i<=n;i++)
	{
		while(b[it]>a[i]&&it<=n)++it;
		res+=ans[it-1];
	}
	printf("%lld",res);
	return 0;
}
