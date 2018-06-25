#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
}
using FastIO::read;

int n,cnt[105],mx;

int main()
{
	read(n);
	for(int i=1,a;i<=n;i++)read(a),cnt[a]++,mx=max(mx,a);
	mx++;
	if(mx&1)
	{
		if(!cnt[mx/2])return puts("Impossible"),0;cnt[mx/2]--;
		for(int i=mx/2+1;i<mx;i++)
		{
			if(cnt[i]<2)return puts("Impossible"),0;
			cnt[i]-=2;
		}
	}
	else for(int i=mx/2;i<mx;i++)
	{
		if(cnt[i]<2)return puts("Impossible"),0;
		cnt[i]-=2;
	}
	mx--;
	if(mx&1)mx=mx/2+2;else mx=mx/2+1;
	for(int i=1;i<mx;i++)if(cnt[i])return puts("Impossible"),0;
	return puts("Possible"),0;
}
