#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;

int n,k,all[maxn],cnt,ans=0x7fffffff,now,ans0;
char c;
queue<int> pos[65];

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline bool cal(int val)
{
	ans0=0;
	for(int i=1;i<=k;i++)
	{
		if(pos[i].empty())return 0;
		now=pos[i].front();
		while(now<val)
		{
			pos[i].pop();
			if(pos[i].empty())break;
			now=pos[i].front();
		}
		if(now<val)return 0;
		ans0=max(ans0,now-val);
	}
	ans=min(ans,ans0);
	return 1;
}

int main()
{
	read(n),read(k);
	for(int i=1,u,v;i<=k;i++)
	{
		read(u);
		for(int j=1;j<=u;j++)read(v),all[++cnt]=v,pos[i].push(v);
	}
	sort(all+1,all+cnt+1),cnt=unique(all+1,all+cnt+1)-all-1;
	for(int i=1;i<=cnt;i++)if(!cal(all[i]))break;
	printf("%d",ans);
	return 0;
}
