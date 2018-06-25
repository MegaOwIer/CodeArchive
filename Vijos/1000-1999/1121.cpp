#include<iostream>
using namespace std;

int m,n,x,y,g[20][20];
long long f[20][20];

int main()
{
	cin>>m>>n>>x>>y;
	g[x][y]=g[x-2][y+1]=g[x-2][y-1]=g[x-1][y+2]=g[x-1][y-2]=g[x+1][y+2]=g[x+1][y-2]=g[x+2][y-1]=g[x+2][y+1]=1;
	f[0][0]=1;
	for(int i=1;i<=m;i++)	if(g[i][0]==0)  f[i][0]=f[i-1][0];
	for(int i=1;i<=n;i++)	if(g[0][i]==0)  f[0][i]=f[0][i-1];
	for(int i=1;i<=m;i++)  for(int j=1;j<=n;j++)  if(g[i][j]==0)  f[i][j]=f[i-1][j]+f[i][j-1];
	cout<<f[m][n];
	return 0;
}
