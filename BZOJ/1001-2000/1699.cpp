#include<bits/stdc++.h>
using namespace std;
const int maxn=50005;

int n,q,lg2[maxn],a[maxn],mx[maxn][20],mn[maxn][20],l,r,lth,dep;
char c;

inline void read(int& x)
{
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline void ask(int l,int r)
{
	lth=r-l+1,dep=lg2[lth];
	printf("%d\n",max(mx[l][dep],mx[r-(1<<dep)+1][dep])-min(mn[l][dep],mn[r-(1<<dep)+1][dep]));
}

int main()
{
	read(n),read(q);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;(1<<i)<=n;i++)lg2[1<<i]=i;
	for(int i=3;i<=n;i++)lg2[i]=max(lg2[i],lg2[i-1]);
	for(int i=1;i<=n;i++)mx[i][0]=mn[i][0]=a[i];
	for(int j=1;j<=lg2[n];j++)for(int i=1;i+(1<<j-1)<=n;i++)
		mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]),
		mx[i][j]=max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
	while(q--)read(l),read(r),ask(l,r);
	return 0;
}
