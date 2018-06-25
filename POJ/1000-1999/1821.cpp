#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=16005;

struct wker{int l,p,s;}w[105];
int N,K,l[105],r[105],h,t,dp[105][maxn],q[maxn],ans;

bool operator < (wker a,wker b){return a.s<b.s;}
template<typename T>
inline void read(T& x)
{
	x=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c<='9'&&c>='0')x=x*10+c-'0',c=getchar();
}

int main()
{
	read(N),read(K);
	for(int i=1;i<=K;i++)read(w[i].l),read(w[i].p),read(w[i].s);
	sort(w+1,w+K+1);
	for(int i=1;i<=K;i++)
	{
		l[i]=max(0,w[i].s-w[i].l);
		r[i]=min(N,w[i].s+w[i].l-1);
	}
	for(int i=1;i<=K;i++)
	{
		for(int j=0;j<w[i].s;j++)dp[i][j]=dp[i-1][j];
		h=t=0;
		for(int j=l[i],tmp;j<w[i].s;j++)
		{
			tmp=dp[i-1][j]-j*w[i].p;
			while(t>h&&dp[i-1][q[t-1]]-q[t-1]*w[i].p<=tmp)t--;
			q[t++]=j;
		}
		for(int j=w[i].s,tmp;j<=r[i];j++)
		{
			while(t>h&&j-q[h]>w[i].l)h++;
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			dp[i][j]=max(dp[i][j],dp[i-1][q[h]]+(j-q[h])*w[i].p);
		}
		for(int j=r[i]+1;j<=N;j++)dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	}
	for(int i=1;i<=N;i++)ans=max(ans,dp[K][i]);
	printf("%d",ans);
	return 0;
}
