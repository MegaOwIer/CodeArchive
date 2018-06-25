#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,mo[100001],mn,mx,ans,cnt,lft;
bool divide(int);

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)  {scanf("%d",&mo[i]);  mn=max(mn,mo[i]);  mx+=mo[i];}
	while(mx!=mn)
	{
		ans=(mn+mx)/2;
		if(divide(ans))  mx=ans;  else  mn=ans+1;
	}
	while(divide(ans))  ans--;
	printf("%d",ans+1);
	return 0;
}
bool divide(int ans)
{
	cnt=1;  lft=ans;
	for(int i=1;i<=n;i++)
	{
		if(mo[i]<=lft)  lft-=mo[i];
		else  {cnt++;  lft=ans-mo[i];}
		if(lft<0)  return 0;
	}
	if(cnt>m)  return 0;
	return 1;
}
