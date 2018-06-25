#include<cstdio>
#include<algorithm>
using namespace std;

int n,x[205],y[205],tot,ans=1;
float k[20000];
bool fl;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)  scanf("%d%d",x+i,y+i);
	for(int i=1;i<n;i++)  for(int j=i+1;j<=n;j++)  x[i]==x[j]?fl=1:k[tot++]=(float)(y[i]-y[j])/(x[i]-x[j]);
	sort(k,k+tot);
	for(int i=1;i<tot;i++)  if(k[i]!=k[i-1])  ans++;
	printf("%d",ans+fl);
	return 0;
}
