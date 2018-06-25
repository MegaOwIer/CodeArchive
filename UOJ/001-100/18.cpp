#include<cstdio>
using namespace std;

int g[135][135],n,d,x,y,nu,sum,mx,cnt;

int main()
{
	scanf("%d%d",&d,&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&x,&y,&nu),g[x][y]=nu;
	for(int i=0;i<=128;i++)for(int j=0;j<=128;j++)
	{
	    sum=0;
		for(int k=i-d;k<=i+d;k++)for(int l=j-d;l<=j+d;l++)
		{
		    if(k<0||l<0||k>128||l>128)continue;
			sum+=g[k][l];
		}
		if(sum>mx){mx=sum,cnt=1;continue;}
		if(sum==mx)cnt++;
	}
	printf("%d %d",cnt,mx);
	return 0;
}
