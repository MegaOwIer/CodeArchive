#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
}
using FastIO::read;
typedef long long LL;

int p,k,a,pr[15],cnt,g,Ia,d,ans[100],tot;
LL Ix,yy;
map<LL,int> pw;

inline void fenjie(int u)
{
	for(int i=2;i*i<=u;i++)if(u%i==0)
	{
		pr[++cnt]=i;
		while(u%i==0)u/=i;
	}
	if(u>1)pr[++cnt]=u;
}
inline LL Pow(LL a,int b)
{
	LL res=1;
	for(;b;b>>=1,a=a*a%p)if(b&1)res=res*a%p;
	return res;
}
inline bool check()
{
	for(int i=1;i<=cnt;i++)
		if(Pow(g,(p-1)/pr[i])==1)return 0;
	return 1;
}
inline int BSGS(const int& g,int val,int p)
{
	LL m=ceil(sqrt(p)),tmp=1,ret;
	for(int i=0;i<m;i++)
		pw[tmp*val%p]=i,tmp=tmp*g%p;
	ret=tmp;
	for(int i=1,cc;i<=m;i++)
	{
		if(cc=pw[ret])return (i*m-cc+p-1)%(p-1);
		ret=ret*tmp%p;
	}
}
inline void exgcd(int a,int b,int& d,LL& x,LL& y)
{
	if(!b){d=a,x=1,y=0;return;}
	exgcd(b,a%b,d,y,x),y-=x*(a/b);
}

int main()
{
	read(p),read(k),read(a),fenjie(p-1);
	if(!a)return puts("1\n0"),0;
	for(g=2;!check();g++);
	Ia=BSGS(g,a,p),exgcd(k,p-1,d,Ix,yy);
	if(Ia%d)return puts("0"),0;
	LL sp=(p-1)/d,tot=0;
	Ix*=Ia/d%sp,Ix=(Ix%sp+sp)%sp;
	if(Ix==0)Ix=sp;
	for(int i=Ix;i<p;i+=sp)ans[++tot]=Pow(g,i);
	sort(ans+1,ans+tot+1);
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)printf("%d\n",ans[i]); 
	return 0;
}
