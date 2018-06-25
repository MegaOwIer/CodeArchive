#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,0,1,0,-1},dy[]={0,1,0,-1,0};

int h[705][705],f[705][705],n,m,ans;
char ch,opt;
bool fl[705][705];

inline void read(int& x)
{
	ch=getchar(),x=0;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
}
inline void getc(char& c){do c=getchar();while(!isalpha(c));}
inline int dp(int x,int y)
{
	if(fl[x][y])return -1;
	if(~f[x][y])return f[x][y];
	f[x][y]=1;
	for(int i=1;i<5;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(!nx||!ny||nx>n||ny>n)continue;
		if(h[x][y]>h[nx][ny])f[x][y]=max(f[x][y],dp(nx,ny)+1);
	}
	return f[x][y];
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)read(h[i][j]);
	read(m);
	for(int i=1,a,b,c,d;i<=m;i++)
	{
		getc(opt);
		if(opt=='C')read(a),read(b),read(c),h[a][b]=c;
		else if(opt=='S')
		{
			read(a),read(b),read(c),read(d);
			for(int j=a;j<=c;j++)for(int k=b;k<=d;k++)fl[j][k]=1;
		}
		else if(opt=='B')
		{
			read(a),read(b),read(c),read(d);
			for(int j=a;j<=c;j++)for(int k=b;k<=d;k++)fl[j][k]=0;
		}
		else
		{
			memset(f,-1,sizeof(f)),ans=0;
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ans=max(ans,dp(i,j));
			printf("%d\n",ans);
		}
	}
	return 0;
}
