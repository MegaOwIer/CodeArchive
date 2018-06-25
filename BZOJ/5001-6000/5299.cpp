#include<bits/stdc++.h>
using namespace std;
const int mod=100000007;
typedef pair<int,int> pii;

int N,dp[1<<20|15][22],a[25][25],ans,S;

struct Point
{
	int x,y;
	Point(){}
	Point(int x,int y):x(x),y(y){}
	Point operator - (Point& a){return Point(x-a.x,y-a.y);}
	int operator * (Point a){return x*a.y-y*a.x;}
	int operator / (Point a){return x*a.x+y*a.y;}
}P[25];

inline void read(int& x)
{
	static char c,f=0;
	c=getchar(),x=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	if(f)x=-x,f=0;
}
inline int prework(int u,int v)
{
	int S=0;
	for(int i=0;i<N;i++)if(u!=i&&v!=i)
		if((P[i]-P[u])*(P[i]-P[v])==0&&(P[i]-P[u])/(P[i]-P[v])<0)
			S|=1<<i;
	return S;
}
inline void update(int& a,int b){a+=b;if(a>=mod)a-=mod;}

int main()
{
	register int i,sta,j,tmp;
	read(N),S=1<<N;
	for(i=0;i<N;i++)read(P[i].x),read(P[i].y);
	for(i=0;i<N;i++)for(j=i+1;j<N;j++)a[i][j]=a[j][i]=prework(i,j);
	for(i=0;i<N;i++)dp[1<<i][i]=1;
	for(sta=1;sta<S;sta++)
	{
		tmp=0;
		for(i=0;i<N;i++)if(dp[sta][i])
		{
			update(tmp,dp[sta][i]);
			for(j=0;j<N;j++)if(!((sta>>j)&1)&&(a[i][j]&sta)==a[i][j])
				update(dp[sta|(1<<j)][j],dp[sta][i]);
		}
		if(__builtin_popcount(sta)>=4)update(ans,tmp);
	}
	printf("%d",ans);
	return 0;
}