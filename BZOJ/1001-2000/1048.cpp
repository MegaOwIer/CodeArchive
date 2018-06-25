#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int a,b,k,s[15][15];
double dp[15][15][15][15][15],ans,arv;

double dfs(int a,int b,int c,int d,int k)
{  
    double tmp=1e9;
    if (dp[a][b][c][d][k]>-1) return dp[a][b][c][d][k];  
    if (k==1)
	{  
        tmp=s[c][d]+s[a-1][b-1]-s[c][b-1]-s[a-1][d]-arv; 
        return dp[a][b][c][d][k]=tmp*tmp;  
    }
    for(int i=a;i<c;i++)  for(int j=1;j<k;j++)  tmp=min(tmp,dfs(a,b,i,d,j)+dfs(i+1,b,c,d,k-j));  
    for(int i=b;i<d;i++)  for(int j=1;j<k;j++)  tmp=min(tmp,dfs(a,b,c,i,j)+dfs(a,i+1,c,d,k-j));  
    return dp[a][b][c][d][k]=tmp;
}  

int main()
{
	scanf("%d%d%d",&a,&b,&k);
	for(int i=1,g;i<=a;i++)  for(int j=1;j<=b;j++)  {scanf("%d",&g);  s[i][j]=g+s[i-1][j]+s[i][j-1]-s[i-1][j-1];}
	memset(dp,-1,sizeof(dp));
	arv=(double)s[a][b]/k;
	ans=dfs(1,1,a,b,k)/k;
	printf("%.2lf",sqrt(ans));
	return 0;
}
