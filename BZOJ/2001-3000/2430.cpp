#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=10005;

int f,n,m,x[maxn],y[maxn];
LL ans;
char c;

inline void read(int& x)
{
	c=getchar(),f=1,x=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();x*=f;
}

int main()
{
	read(n),read(m);
	for(int i=1;i<n;i++)read(x[i]),ans+=x[i]*m;
	for(int i=1;i<m;i++)read(y[i]),ans+=y[i]*n;
	for(int i=1;i<m;i++)for(int j=1;j<n;j++)ans-=max(x[j],y[i]);
	printf("%lld",ans);
	return 0;
}
