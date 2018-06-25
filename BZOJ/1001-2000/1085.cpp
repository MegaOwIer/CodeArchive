#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,-2,-1,1,2,2,1,-1,-2},dy[]={0,1,2,2,1,-1,-2,-2,-1},
		  ans[5][5]={{1,1,1,1,1},{0,1,1,1,1},{0,0,2,1,1},{0,0,0,0,1}};

int T,k,a[5][5],x,y;
char c;

inline void getnum(int& x)
{
	do c=getchar();while(!isdigit(c)&&c!='*');
	if(c=='*')x=2;else x=c-48;
}
inline bool judge(int a[5][5])
{
	for(int i=0;i<5;i++)for(int j=0;j<5;j++)if(a[i][j]!=ans[i][j])return 0;
	return 1;
}
inline bool eva(int a[5][5],int r)
{
	int del=0;
	for(int i=0;i<5;i++)for(int j=0;j<5;j++)
		if(a[i][j]!=ans[i][j]){del++;if(del>r)return 0;}
	return 1;
}
inline void dfs(int step,int a[5][5],int x,int y)
{
	if(step>=k)return;
	if(judge(a)){k=step;return;}
	for(int i=1;i<9;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0||nx>4||ny<0||ny>4)continue;
		swap(a[x][y],a[nx][ny]);
		if(eva(a,k-step))dfs(step+1,a,nx,ny);
		swap(a[x][y],a[nx][ny]);
	}
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		k=16;
		for(int i=0;i<5;i++)for(int j=0;j<5;j++)
		{
			getnum(a[i][j]);
			if(a[i][j]==2)x=i,y=j;
		}
		dfs(0,a,x,y);
		printf("%d\n",k>15?-1:k);
	}
	return 0;
}
