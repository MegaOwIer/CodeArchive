#include<bits/stdc++.h>
using namespace std;
const int MX=10050;
typedef int Array[MX];

namespace FastIO
{
	char c;
	int tp,bf[22];
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		tp=0;
		do bf[++tp]=x%10,x/=10;while(x);
		while(tp)putchar(48+bf[tp--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;

int n=1,m=27,T,L,R,mid,ans,flag[6];
Array rk,tx,tp,SA,Height,pos;
char s[MX];

inline void Radix_Sort()
{
	memset(tx+1,0,sizeof(int)*m);
	for(int i=1;i<=n;i++)tx[rk[tp[i]]]++;
	for(int i=2;i<=m;i++)tx[i]+=tx[i-1];
	for(int i=n;i;i--)SA[tx[rk[tp[i]]]--]=tp[i];
}
inline bool check(int mid)
{
	int kase=0,cnt=1;
	memset(flag+1,0,sizeof(int)*T);
	for(int i=2;i<=n;i++)
	{
		if(Height[i]<mid)
			cnt=1,flag[pos[SA[i]]]=++kase;
		else
		{
			if(flag[pos[SA[i]]]!=kase)cnt++,flag[pos[SA[i]]]=kase;
			if(cnt==T)return 1;
		}
	}
	return 0;
}

int main()
{
	read(T);
	for(int i=1;i<=T;i++)
	{
		scanf("%s",s+n);
		while(s[n])pos[n++]=i;
		s[n]='a'-1,pos[n++]=i;
	}
	n--,s[n]=pos[n]=0,n--;
	for(int i=1;i<=n;i++)rk[i]=s[i]-'a'+2,tp[i]=i;
	Radix_Sort();
	for(int w=1,p=0,i;p!=n;w<<=1,m=p)
	{
		for(i=n-w+1,p=0;i<=n;i++)tp[++p]=i;
		for(i=1;i<=n;i++)if(SA[i]>w)tp[++p]=SA[i]-w;
		Radix_Sort(),memcpy(tp+1,rk+1,sizeof(int)*n),rk[SA[1]]=p=1;
		for(i=2;i<=n;i++)
			rk[SA[i]]=(tp[SA[i]]==tp[SA[i-1]]&&tp[SA[i]+w]==tp[SA[i-1]+w])?p:++p;
	}
	for(int k=0,i=1,j;i<=n;Height[rk[i++]]=k)
		for(k=k?k-1:0,j=SA[rk[i]-1];s[i+k]==s[j+k];k++);
	L=1,R=n;
	while(L<=R)
	{
		mid=L+R>>1;
		if(check(mid))ans=mid,L=mid+1;
		else R=mid-1;
	}
	write(ans);
	return 0;
}
