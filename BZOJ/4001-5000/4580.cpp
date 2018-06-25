#include<bits/stdc++.h>
using namespace std;
const int maxn=250;

int n,a[50][maxn],ans,it;
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}
inline void dfs(int mn,int lth)
{
	if(!lth)return;
	int len=0,it=0;
	for(int i=1;i<=lth;i++)
	{
		ans=max(ans,a[mn][i]);
		if(a[mn][i]!=mn) a[mn+1][++it]=a[mn][i],len=0;
		else if(a[mn][i+1]!=mn||i==lth)
		{
			dfs(mn+1,it);
			for(it=0;it<len;)a[mn+1][++it]=mn+1;
		}
		else a[mn+1][++it]=mn+1,i++,len++;
	}
	dfs(mn+1,it);
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a[1][i]);
	dfs(1,n);
	printf("%d",ans);
	return 0;
}
