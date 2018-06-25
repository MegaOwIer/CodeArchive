#include<cstdio>
#include<algorithm>
using namespace std;

int T,M,f[1005],t[105],m[105];

int main()
{
	scanf("%d%d",&T,&M);
	for(int i=1;i<=M;i++)  scanf("%d%d",t+i,m+i);
	for(int i=1;i<=M;i++)  for(int j=T;j>=t[i];j--)  f[j]=max(f[j],f[j-t[i]]+m[i]);
	printf("%d",f[T]);
	return 0;
}
