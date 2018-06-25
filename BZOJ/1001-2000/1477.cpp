#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int f;
LL x,y,m,n,l,r1,r2;
char c;

inline void read(LL& X)
{
	X=0,c=getchar(),f=1;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')X=X*10+c-'0',c=getchar();X*=f;
}
inline LL exgcd(LL a,LL b,LL& x,LL& y)
{
	if(!b){x=1,y=0;return a;}
	LL d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

int main()
{
	read(x),read(y),read(m),read(n),read(l);
	LL d=exgcd((m-n+l)%l,l,r1,r2),del=y-x;
	if(del%d)return puts("Impossible"),0;
	l/=d,del/=d;
	r1=(r1*del%l+l)%l;
	printf("%lld",r1);
	return 0;
}
