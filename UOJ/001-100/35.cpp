#include<bits/stdc++.h>
using namespace std;
const int MX=100005;
typedef int Array[MX];

int n,m=26;
Array SA,rank,Height,tax,tp,a;
char s[MX];

namespace FastIO
{
	int top,bf[22];
	template<typename T>inline void write(T x)
	{
		top=0;
		do bf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+bf[top--]);
		putchar(' ');
	}
}
using FastIO::write;

inline void Radix_Sort()
{
	memset(tax+1,0,sizeof(int)*m);
	for(int i=1;i<=n;i++)tax[rank[tp[i]]]++;
	for(int i=1;i<=m;i++)tax[i]+=tax[i-1];
	for(int i=n;i;i--)SA[tax[rank[tp[i]]]--]=tp[i];
}

int main()
{
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=n;i++)rank[i]=a[i]=s[i]-'a'+1,tp[i]=i;
	Radix_Sort();
	for(int w=1,p=0,i;p<n&&w<=n;w<<=1,m=p)
	{
		for(p=0,i=n-w+1;i<=n;i++)tp[++p]=i;
		for(i=1;i<=n;i++)if(SA[i]>w)tp[++p]=SA[i]-w;
		Radix_Sort(),memcpy(tp+1,rank+1,sizeof(int)*n),rank[SA[1]]=p=1;
		for(i=2;i<=n;i++)
			rank[SA[i]]=(tp[SA[i]]==tp[SA[i-1]]&&tp[SA[i]+w]==tp[SA[i-1]+w])?p:++p;
	}
	for(int i=1;i<=n;i++)write(SA[i]);
	putchar('\n');
	for(int i=1,j,k=0;i<=n;Height[rank[i++]]=k)
		for(k=k?k-1:k,j=SA[rank[i]-1];a[i+k]==a[j+k];++k);
	for(int i=2;i<=n;i++)write(Height[i]);
	return 0;
}