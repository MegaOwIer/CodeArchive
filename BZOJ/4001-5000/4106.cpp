#include<bits/stdc++.h>
using namespace std;
const int MX=1000005;

int p,a,b,c,d,n;
double pr[MX],mx[MX],mn[MX],ans;

int main()
{
	scanf("%d%d%d%d%d%d",&p,&a,&b,&c,&d,&n);
	for(int i=1;i<=n;i++)
		pr[i]=p*(sin(1.0*a*i+b)+cos(1.0*c*i+d)+2);
	mx[1]=pr[1],mn[n]=pr[n];
	for(int i=2;i<=n;i++)mx[i]=max(mx[i-1],pr[i]);
	for(int i=n-1;i;i--)mn[i]=min(mn[i+1],pr[i]);
	for(int i=1;i<=n;i++)ans=max(ans,mx[i]-mn[i]);
	printf("%.6lf\n",ans);
	return 0;
}