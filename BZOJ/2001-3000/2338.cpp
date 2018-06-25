#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c,buf[22];
	static int top,f;
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar(),f=1;
		while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
		while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
	}
	template<typename T>
	inline void write(T x,int fl=0)
	{
		top=0;
		do buf[top++]=x%10,x/=10;while(x);
		for(int i=top-1;~i;i--)putchar('0'+buf[i]);
		if(fl)putchar(fl&1?' ':'\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;

struct point
{
	LL x,y;
	point(LL x=0,LL y=0):x(x),y(y){}
	inline const bool operator < (point a)const{return x<a.x||(x==a.x&&y<a.y);}
	inline const bool operator == (point a)const{return x==a.x&&y==a.y;}
	inline const point operator + (point a)const{return point(x+a.x,y+a.y);}
}p[1505];
struct seg
{
	LL lth;
	point p1,p2,mid;
	inline const bool operator < (seg a)const{return lth<a.lth||(lth==a.lth&&mid<a.mid);}
	inline const bool operator == (seg a)const{return a.lth==lth&&a.mid==mid;}
}s[1124300],res;
int n,cnt;
LL ans;

inline seg mk(point a,point b)
{
	res.lth=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
	res.mid=a+b,res.p1=a+a,res.p2=b+b;
	return res;
}
inline LL cal(point a,point b,point c){return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(p[i].x),read(p[i].y);
	for(int i=1;i<=n;i++)for(int j=1;j<i;j++)s[++cnt]=mk(p[i],p[j]);
	sort(s+1,s+cnt+1);
	for(int i=1;i<=cnt;i++)for(int j=i-1;s[j]==s[i]&&j;j--)
		ans=max(ans,abs(cal(s[i].mid,s[i].p1,s[j].p1)));
	write(ans>>1);
	return 0;
}
