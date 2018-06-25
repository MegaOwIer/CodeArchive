#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int buf[22],top;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do buf[top++]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[--top]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int maxn=1000005,mod=1e9+7;

int T,next[maxn],cnt[maxn],it1,it2;
LL ans;
char s[maxn];

int main()
{
	read(T);
	while(T--)
	{
		scanf("%s",s+1);
		cnt[1]=1,ans=1,it1=it2=0;
		for(int i=2;s[i];i++)
		{
			while(it1&&s[i]!=s[it1+1])it1=next[it1];
			if(s[i]==s[it1+1])++it1;
			next[i]=it1,cnt[i]=cnt[it1]+1;
			while(it2&&s[i]!=s[it2+1])it2=next[it2];
			if(s[i]==s[it2+1])++it2;
			while(it2>(i>>1))it2=next[it2];
			ans*=cnt[it2]+1,ans%=mod;
		}
		write(ans);
	}
	return 0;
}
