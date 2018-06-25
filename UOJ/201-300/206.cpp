#include<bits/stdc++.h>
#include"gap.h"
using namespace std;
typedef long long LL;
const LL INF=1LL<<62;

LL solve1(int N)
{
	LL l=0,r=INF,mn,mx,ans=0;
	MinMax(0,INF,&mn,&mx);
	for(int i=N-2;i>0;i-=2)
	{
		l=mn,r=mx;
		MinMax(l+1,r-1,&mn,&mx);
		ans=max(ans,max(mn-l,r-mx));
	}
	ans=max(ans,mx-mn);
	return ans;
}
LL solve2(int N)
{
	LL a1,an,ans=0,B,mn,mx,pre;
	MinMax(0,INF,&a1,&an);
	B=(an-a1)/(N-1)+1,pre=a1;
	for(LL l=a1+1,r=a1+B;l<=an;l+=B,r+=B)
	{
		MinMax(l,r,&mn,&mx);
		if(~mn)ans=max(ans,mn-pre),pre=mx;
	}
	return max(ans,an-pre);
}

LL findGap(int T,int N){return (T==1?solve1:solve2)(N);}
