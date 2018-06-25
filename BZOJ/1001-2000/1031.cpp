#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int N,a[MX<<1],sa[MX<<1],rk[MX<<1],tp[MX<<1],m=127,tax[MX<<1],n;
char s[MX];

inline void Radix_Sort()
{
	memset(tax+1,0,sizeof(int)*m);
	for(int i=1;i<=N;i++)tax[rk[tp[i]]]++;
	for(int i=1;i<=m;i++)tax[i]+=tax[i-1];
	for(int i=N;i;i--)sa[tax[rk[tp[i]]]--]=tp[i];
}

int main()
{
	scanf("%s",s+1),n=strlen(s+1),N=n<<1;
	for(int i=1;i<=n;i++)rk[i]=a[i]=s[i];
	for(int i=1;i<=n;i++)rk[i+n]=a[i+n]=s[i];
	for(int i=1;i<=N;i++)tp[i]=i;
	Radix_Sort();
	for(int w=1,p=0,i;w<=N&&p<N;w<<=1,m=p)
	{
		for(p=0,i=N-w+1;i<=N;i++)tp[++p]=i;
		for(i=1;i<=N;i++)if(sa[i]>w)tp[++p]=sa[i]-w;
		Radix_Sort(),swap(rk,tp),rk[sa[1]]=p=1;
		for(i=2;i<=N;i++)
			rk[sa[i]]=(tp[sa[i]]==tp[sa[i-1]]&&tp[sa[i]+w]==tp[sa[i-1]+w])?p:++p;
	}
	for(int i=1;i<=N;i++)if(sa[i]<=n)putchar(a[sa[i]+n-1]);
	return 0;
}
