#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL k,n,ans[22],tmp;

LL solve(LL u,LL step,LL st,LL cnt)
{
	if(!u||!cnt)return 0;
	LL used=0,src=0;
	for(int i=0;i<cnt;i++)
	{
		tmp=ans[i]*ans[cnt-1-i]*step;
		if(u>used+tmp) used+=tmp;
		else
		{
			putchar('a'+i+st);
			src=solve(u-used,step*ans[cnt-1-i],st,i);
			return used+src+solve(u-used-src,step,st+i+1,cnt-i-1);
		}
	}
}

int main()
{
	scanf("%lld%lld",&n,&k);
	ans[0]=ans[1]=1LL,ans[2]=2LL;
	for(int i=3;i<=k;i++)for(int j=0;j<i;j++)ans[i]+=ans[j]*ans[i-j-1];
	solve(n,1,0,k);
	return 0;
}
