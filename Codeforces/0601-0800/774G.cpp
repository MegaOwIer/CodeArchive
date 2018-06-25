#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

bool fail;
LL a,h,w,tmp,H,W,d,S,T;

inline LL exgcd(LL a,LL b,LL& x,LL& y,LL val)
{
	if(!b)
	{
		if(val%a!=0)fail=1;
		x=val/a,y=0;
		return a;
	}
	int k=exgcd(b,a%b,y,x,val);
	y-=a/b*x;
	return k;
}

int main()
{
	cin>>a>>h>>w;
	if(a>h||a>w)return puts("-1"),0;
	if(h==w)
	{
		tmp=floor((double)(h+a)/a);
		printf("%.8lf",(double)(h+a)/(tmp)-a);
		return 0;
	}
	H=h+a,W=w+a;
	d=exgcd(H,W,T,S,W-H),S=-S;
	if(fail)puts("-1");
	h=H/d,w=W/d;
	if(T>0)S-=h*(T/w),T%=w;
	if(S>0)T-=w*(S/h),S%=h;
	if(T<=0)S+=h*(1-T/w),T+=w*(1-T/w);
	if(S<=0)T+=w*(1-S/h),S+=h*(1-S/h);
	if((S+1)*a>H||(T+1)*a>W)return puts("-1"),0;
	tmp=min((H/a-1-S)/h,(W/a-1-T)/w);
	printf("%.8lf",(double)H/(S+1+tmp*h)-a);
	return 0;
}
