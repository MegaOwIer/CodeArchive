#include<iostream>
using namespace std;

char a[105][105];
int m,n,dx[9]={0,-1,-1,0,1,1,1,0,-1},dy[9]={0,0,1,1,1,0,-1,-1,-1},
    d[105][105],cnt;

int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)  for(int j=1;j<=n;j++)  cin>>a[i][j];
    void dfs(int,int);
	for(int i=1;i<=m;i++)
      for(int j=1;j<=n;j++)
      {
          if(a[i][j]=='W'&&d[i][j]==0)  {dfs(i,j);  cnt++;}
          d[i][j]=1;
      }
    cout<<cnt;
    return 0;
}

void dfs(int e,int f)
{
	int xx,yy; 
	for(int k=1;k<=8;k++)
	{
		xx=e+dx[k];
		yy=f+dy[k];
		if(a[xx][yy]=='W'&&d[xx][yy]==0)  {d[xx][yy]=1;  dfs(xx,yy);}	
	}
}
