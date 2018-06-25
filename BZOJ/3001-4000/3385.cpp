#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,-1,-1,0,1,1,1,0,-1},dy[]={0,0,1,1,1,0,-1,-1,-1};

char c;
int m,n,cnt;
bool a[105][105],d[105][105];

inline void read(char& x){do x=getchar();while(x!='W'&&x!='.');}
void dfs(int x,int y)
{
	d[x][y]=1;
	int xx,yy;
	for(int k=1;k<=8;k++)
	{
		xx=x+dx[k],yy=y+dy[k];
		if(a[xx][yy]&&!d[xx][yy])dfs(xx,yy);	
	}
}

int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)read(c),a[i][j]=(c=='W');
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)if(a[i][j]&&!d[i][j])dfs(i,j),cnt++;
    printf("%d",cnt);
    return 0;
}
