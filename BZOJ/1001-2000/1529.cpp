#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;

int n,a[maxn],ans,fa[maxn];
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}
inline int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,s;i<=n;i++)
	{
		read(s);
		int f1=find(i),f2=find(s);
		if(f1==f2)continue;
		fa[f1]=f2;
	}
	for(int i=1;i<=n;i++)if(fa[i]==i)ans++;
	printf("%d",ans);	
	return 0;
}
