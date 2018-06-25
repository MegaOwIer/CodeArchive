#include<bits/stdc++.h>
using namespace std;
#define sqr(x) x*x

int n,m,s[2005][2005],ans1,ans2,sta[2005],top,l[2005],r[2005];
bool g[2005][2005];
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void work()
{
	for(int j=1;j<=m;j++)
	{
		top=0;
		for(int i=1;i<=n+1;i++)
		{
			while(top&&s[sta[top]][j]>s[i][j])r[sta[top--]]=i-1;
			sta[++top]=i;
		}
		top=0;
		for(int i=n;~i;i--)
		{
			while(top&&s[sta[top]][j]>s[i][j])l[sta[top--]]=i+1;
			sta[++top]=i;
		}
		for(int i=1;i<=n;i++)
			ans1=max(ans1,sqr(min(s[i][j],r[i]-l[i]+1))),
			ans2=max(ans2,s[i][j]*(r[i]-l[i]+1));
	}
}

int main()
{
	read(n),read(m);
	for(int i=1,u;i<=n;i++)for(int j=1;j<=m;j++)read(u),g[i][j]=u^((i^j)&1);
	for(int i=1;i<=n;i++)for(int j=m;j;j--)s[i][j]=g[i][j]?s[i][j+1]+1:0;work();
	for(int i=1;i<=n;i++)for(int j=m;j;j--)s[i][j]=g[i][j]?0:s[i][j+1]+1;work();
	printf("%d\n%d",ans1,ans2);
	return 0;
}
