#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,0,-1,1},dy[]={1,-1,0,0};

struct node {int x,y,sta,cost;}p,now;
int n,m,k,a[105][105],dp[105][105][135],c[105][105],ans=0x7fffffff;
bool inq[105][105][135],use[105][105];
priority_queue<node> q;
vector<node> way[105][105][135];
queue<node> tmp;

bool operator < (node a,node b) {return a.cost>b.cost;}
template<typename T>
inline void read(T& x)
{
	x=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}

int main()
{
	read(n),read(m),read(k);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)read(a[i][j]);
	memset(dp,0x3f,sizeof(dp));
	for(int i=0,x,y;i<k;i++)
	{
		read(x),read(y);
		c[x][y]=1<<i;
		dp[x][y][c[x][y]]=a[x][y];
		q.push((node){x,y,c[x][y],a[x][y]});
	}
	while(!q.empty())
	{
		now=q.top();  q.pop();
		if(inq[now.x][now.y][now.sta])continue;
		inq[now.x][now.y][now.sta]=1;
		for(int i=0;i<4;i++)
		{
			int xx=now.x+dx[i],yy=now.y+dy[i],sta;
			if(xx<1||xx>n||yy<1||yy>m)continue;
			sta=now.sta|c[xx][yy];
			if(dp[xx][yy][sta]>now.cost+a[xx][yy])
			{
				dp[xx][yy][sta]=now.cost+a[xx][yy];
				way[xx][yy][sta].clear();
				way[xx][yy][sta].push_back(now);
				q.push((node){xx,yy,sta,dp[xx][yy][sta]});
			}
		}
		int cf=((1<<k)-1)&(~now.sta);
		for(int i=cf;i;i=(i-1)&cf)
		{
			int xx=now.x,yy=now.y,sta=now.sta|i;
			if(dp[xx][yy][i]==0x3f3f3f3f)continue;
			if(dp[xx][yy][sta]>dp[xx][yy][i]+now.cost-a[xx][yy])
			{
				dp[xx][yy][sta]=dp[xx][yy][i]+now.cost-a[xx][yy];
				way[xx][yy][sta].clear();
				way[xx][yy][sta].push_back((node){xx,yy,i});
				way[xx][yy][sta].push_back((node){xx,yy,now.sta});
				q.push((node){xx,yy,sta,dp[xx][yy][sta]});
			}
		}
	}
	for(int i=1;i<=n;i++)  for(int j=1;j<=m;j++)  if(ans>dp[i][j][(1<<k)-1])  ans=dp[i][j][(1<<k)-1],p=(node){i,j,(1<<k)-1};
	printf("%d\n",ans);  tmp.push(p);
	while(!tmp.empty())
	{
		p=tmp.front();tmp.pop();
		use[p.x][p.y]=1;
		for(int i=0;i<way[p.x][p.y][p.sta].size();i++)  tmp.push(way[p.x][p.y][p.sta][i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)  putchar(use[i][j]?'X':'.');
		putchar('\n');
	}
	return 0;
}

