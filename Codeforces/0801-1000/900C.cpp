#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[22]; 
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int maxn=1e5+5;

int n,a[maxn],tr[maxn],cnt[maxn],O,ans,ANS=1; 

inline void add(int x,int v){for(;x<=n;x+=x&-x)tr[x]+=v;}
inline int ask(int x){int ans=0;for(;x;x-=x&-x)ans+=tr[x];return ans;}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		cnt[i]=ask(n)-ask(a[i]);
		add(a[i],1);
	}
	memset(tr+1,0,n<<2);
	for(int i=1;i<=n;i++)
	{
		if(!cnt[i])O++;
		if(cnt[i]==1)add(a[i],1);
	}
	for(int i=1,tmp;i<=n;i++)
	{
		if(cnt[i]==1)add(a[i],-1);
		tmp=(cnt[i]==0)?O-1:O;
		tmp+=ask(a[i]);
		if(tmp>ans)ans=tmp,ANS=a[i];
		else if(tmp==ans&&a[i]<ANS)ANS=a[i];
	}
	write(ANS);
	return 0;
}
