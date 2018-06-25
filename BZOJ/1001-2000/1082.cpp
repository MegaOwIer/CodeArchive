#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int m,a[55],n,b[1005],tot=0,l,r,mid,bl[1005];
LL suma,sumb[1005];
bool flag;
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}
inline void dfs(int ak,int bk,int w)
{
	if(!bk)flag=1;
	while(ak<=m&&a[ak]<b[1])w+=a[ak++];
	if(flag||ak>m)return;
	if(w+sumb[mid]>suma)return;
	int t=ak,t1=ak,t2=bk,t3=w;
	if(b[bk]==b[bk+1]&&bk!=mid)t=bl[bk+1];
	for(int i=t;i<=m;i++)if(a[i]>=b[bk])
	{
		bl[bk]=i,a[i]-=b[bk],bk--;
		dfs(ak,bk,w);
		ak=t1,bk=t2,w=t3,a[i]+=b[t2];
	}
}

int main()
{
	read(m);for(int i=1;i<=m;i++)read(a[i]);sort(a+1,a+m+1);
	read(n);for(int i=1;i<=n;i++)read(b[i]);sort(b+1,b+n+1);
	while(b[n]>a[m])n--;
	for(int i=1;i<=m;i++)if(a[i]>b[1])a[++tot]=a[i];m=tot;
	for(int i=1;i<=m;i++)suma+=a[i];
	for(int i=1;i<=n;i++)sumb[i]=sumb[i-1]+b[i];
	l=1,r=n+1;
	while(l<r)
	{
		mid=l+r>>1;
		flag=0,dfs(1,mid,0);
		if(flag)l=mid+1;
		else r=mid;
	}
	printf("%d",l-1);
	return 0;
}
