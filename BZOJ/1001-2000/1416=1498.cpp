#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=1005;

namespace FastIO
{
    char c;
    template<typename T>inline void read(T& x)
    {
        c=getchar(),x=0;
        while(!isdigit(c))c=getchar();
        while(isdigit(c))x=x*10+c-'0',c=getchar();
    }
}
using FastIO::read;

int t,n,d,pr[2265],cnt,a[MX],tot,pw1[2265],pw2[2265],Big[10000];
bool vis[20010];

inline void wk(int x,int *A)
{
	for(int i=1;i<=cnt;i++)if(x%pr[i]==0)
		while(x%pr[i]==0)A[i]++,x/=pr[i];
}
inline void print(int* A)
{
	int L=1;
	memset(Big,0,sizeof(Big)),Big[0]=1;
	for(int i=1,k;i<=cnt;i++)while(A[i]--)
	{
		for(k=0;k<L;k++)Big[k]*=pr[i];
		for(k=0;k<L;k++)if(Big[k]>9)
			Big[k+1]+=Big[k]/10,Big[k]%=10;
		while(Big[L])Big[L+1]=Big[L]/10,Big[L++]%=10;
	}
	while(L--)putchar(Big[L]+48);
}

int main()
{
	for(int i=2,tmp;i<=2e4;i++)
	{
		if(!vis[i])pr[++cnt]=i;
		for(int j=1;j<=cnt&&(tmp=i*pr[j])<=2e4;j++)
		{
			vis[tmp]=1;
			if(i%pr[j]==0)break;
		}
	}
	read(t),read(n),read(d);
	for(int i=1;i<=t;i++)read(a[i]),tot+=a[i];
	for(int i=1,x,y;i<=n;i++)
		read(x),read(y),wk(a[y],pw1),wk(tot,pw2),tot+=d,a[y]+=d;
	for(int i=1;i<=cnt;i++)
		if(pw1[i]>=pw2[i])pw1[i]-=pw2[i],pw2[i]=0;
		else pw2[i]-=pw1[i],pw1[i]=0;
	print(pw1),putchar('/'),print(pw2);
	return 0;
}
