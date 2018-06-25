#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;

int n,t,ans=1,now,ch=1;
struct line {int l,r;}co[25005];
bool operator < (line u,line v)  {return u.l<v.l||(u.l==v.l&&u.r>v.r);}

int main()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)  scanf("%d%d",&co[i].l,&co[i].r);
	co[n+1].l=0x7fffffff;
	sort(co+1,co+n+1,less<line>());
	if(co[1].l>1)  return puts("-1"),0;
	now=co[1].r+1;
	for(int i=2;i<=n&&now<=t;)
	{
		if(co[i].l>now)  return puts("-1"),0;
		int mx=ch;
		for(;co[i].l<=now;i++)  if(co[i].r>co[mx].r)  mx=i;
		ch=mx;  now=co[ch].r+1;  ans++;
	}
	if(now<=t)  return puts("-1"),0;
	printf("%d",ans);
	return 0;
}
