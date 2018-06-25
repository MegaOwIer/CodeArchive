#include<bits/stdc++.h>
using namespace std;

int n,a[100005],mx,mn,mid,pos,cnt,C;
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}
inline bool check(int u)
{
	for(int i=(cnt=0)+1;cnt<C&&i<=n;i=lower_bound(a+1,a+n+1,a[i]+u)-a,cnt++);
	return cnt==C;
}

int main()
{
	read(n),read(C);
	for(int i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+n+1);
	mx=(a[n]-a[1])/(C-1)+5;
	while(mn<mx)
	{
		mid=mn+mx>>1;
		if(check(mid))mn=mid+1;
		else mx=mid;
	}
	printf("%d",mx-1);
	return 0;
}
