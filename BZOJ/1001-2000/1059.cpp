#include<bits/stdc++.h>
using namespace std;

int T,n,u,lk[205];
bool g[205][205],visr[205],fail;

inline bool find(int u)
{
	for(int i=1;i<=n;i++)if(!visr[i]&&g[u][i])
	{
		visr[i]=1;
		if(!lk[i]||find(lk[i])){lk[i]=u;return 1;}
	}
	return 0;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n),fail=0;
		memset(lk+1,0,n<<2);
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&u),g[i][j]=u;
		for(int i=1;i<=n&&!fail;i++)
		{
			memset(visr+1,0,n);
			if(!find(i))fail=1;
		}
		puts(fail?"No":"Yes");
	}
	return 0;
}
