#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=4005;

struct data{int x,y;}a[maxn],b[maxn];
int n,cnt,x,y;
LL ans; 
char c;

inline void read(int& x)
{
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); 
}
inline bool operator < (data a,data b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
inline bool operator > (data a,data b){return a.y<b.y;}

int main()
{
	read(n);
	for(int i=1,u,v;i<=n;i++)read(u),read(v),a[i].x=min(u,v),a[i].y=max(u,v);
	sort(a+1,a+n+1);
	for(int i=n;i;i--)
	{
		b[++cnt]=a[i],sort(b+1,b+cnt+1,greater<data>());
		for(int j=1;j<=cnt;j++)
		{
			LL tmp=1LL*a[i].x*b[j].y*(cnt-j+1);
			if(tmp>ans)ans=tmp,x=a[i].x,y=b[j].y;
		}
	}
	printf("%lld\n%d %d",ans,x,y);
	return 0;
}
