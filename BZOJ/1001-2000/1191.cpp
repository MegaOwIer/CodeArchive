#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;

int n,m,lft[maxn],ans;
bool g[maxn][maxn],fl[maxn];

inline int read()
{
	int ans=0;  char ch=getchar();
	while(ch<'0'||ch>'9')  ch=getchar();
	while(ch>='0'&&ch<='9')  ans=ans*10+ch-'0',ch=getchar();
	return ans;
}
inline bool path(int u)
{
	for(int i=1;i<=n;i++)  if(!fl[i]&&g[u][i])
	{
		fl[i]=1;
		if(!lft[i]||path(lft[i]))  {lft[i]=u;  return 1;}
	}
	return 0;
}

int main()
{
	n=read(),m=read();
	for(int i=1,a,b;i<=m;i++)
	{
		a=read()+1,b=read()+1;
		g[i][a]=g[i][b]=1;
	}
	for(int i=1;i<=n;i++)
	{
		memset(fl,0,sizeof(fl));
		if(path(i))  ++ans;
		else  break;
	}
	printf("%d",ans);
	return 0;
}
