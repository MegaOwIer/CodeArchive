#include<bits/stdc++.h>
using namespace std;
const int MX=500005;
typedef int Array[MX];
typedef long long LL;

namespace FastIO
{
	int top,bf[22];
	template<typename T>inline void write(T x)
	{
		top=0;
		do bf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+bf[top--]);
	}
}
using FastIO::write;

int n,m=26,top;
Array rk,SA,Height,tp,tax,l,r,stk;
LL ans;
char s[MX];

inline void Radix_Sort()
{
	memset(tax+1,0,sizeof(int)*m);
	for(int i=1;i<=n;i++)tax[rk[tp[i]]]++;
	for(int i=2;i<=m;i++)tax[i]+=tax[i-1];
	for(int i=n;i;i--)SA[tax[rk[tp[i]]]--]=tp[i];
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)rk[i]=s[i]-'a'+1,tp[i]=i;
	Radix_Sort();
	for(int w=1,p=0,i;p!=n;w<<=1,m=p)
	{
		for(p=0,i=n-w+1;i<=n;i++)tp[++p]=i;
		for(i=1;i<=n;i++)if(SA[i]>w)tp[++p]=SA[i]-w;
		Radix_Sort(),memcpy(tp+1,rk+1,sizeof(int)*n),rk[SA[1]]=p=1;
		for(i=2;i<=n;i++)
			rk[SA[i]]=(tp[SA[i]]==tp[SA[i-1]]&&tp[SA[i]+w]==tp[SA[i-1]+w])?p:++p;
	}
	for(int i=1,j,k=0;i<=n;Height[rk[i++]]=k)
		for(k=k?k-1:0,j=SA[rk[i]-1];s[j+k]==s[i+k];k++);
	for(int i=2;i<=n;i++)
	{
		while(top&&Height[i]<Height[stk[top]])r[stk[top--]]=i-1;
		stk[++top]=i;
	}
	while(top)r[stk[top--]]=n;
	for(int i=n;i>1;i--)
	{
		while(top&&Height[i]<=Height[stk[top]])l[stk[top--]]=i+1;
		stk[++top]=i;
	}
	while(top)l[stk[top--]]=2;
	for(int i=1;i<=n;i++)ans+=2LL*Height[i]*(r[i]-i+1)*(i-l[i]+1);
	write((LL)(n-1)*n*(n+1)/2-ans);
	return 0;
}