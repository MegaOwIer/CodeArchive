#include<bits/stdc++.h>
using namespace std;
const int MX=50005;
typedef int Array[MX];
typedef long long LL;

namespace FastIO
{
	char c;
	int tp,bf[22];
	template<typename T>inline void read(T& x)
	{
		c=getchar(),x=0;
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		tp=0;
		do bf[++tp]=x%10,x/=10;while(x);
		while(tp)putchar(48+bf[tp--]);
	}
}
using FastIO::read;
using FastIO::write;

int n,L,pw2[22];
Array tx,tp;
struct Suffix_Array
{
	int m;
	Array rk,SA,Hgt,ST[22];
	char s[MX];

	Suffix_Array():m(127){}
	void Radix_Sort()
	{
		memset(tx+1,0,sizeof(int)*m);
		for(int i=1;i<=n;i++)tx[rk[tp[i]]]++;
		for(int i=2;i<=m;i++)tx[i]+=tx[i-1];
		for(int i=n;i;i--)SA[tx[rk[tp[i]]]--]=tp[i];
	}
	void init()
	{
		for(int i=1;i<=n;i++)tp[i]=i,rk[i]=s[i];
		Radix_Sort();
		for(int w=1,p=0,i;p<n&&w<=n;w<<=1,m=p)
		{
			for(i=n-w+1,p=0;i<=n;i++)tp[++p]=i;
			for(i=1;i<=n;i++)if(SA[i]>w)tp[++p]=SA[i]-w;
			Radix_Sort(),memcpy(tp+1,rk+1,sizeof(int)*n),rk[SA[1]]=p=1;
			for(i=2;i<=n;i++)
				rk[SA[i]]=(tp[SA[i]]==tp[SA[i-1]]&&tp[SA[i]+w]==tp[SA[i-1]+w])?p:++p;
		}
		for(int i=1,k=0,j;i<=n;Hgt[rk[i++]]=k)
			for(k=k?k-1:0,j=SA[rk[i]-1];s[i+k]==s[j+k];k++);
		for(int i=1;i<=n;i++)ST[0][i]=Hgt[i];
		for(int j=1;j<=17;j++)for(int i=1;i+(1<<j-1)<=n;i++)
			ST[j][i]=min(ST[j-1][i],ST[j-1][i+(1<<j-1)]);
	}
	inline int ask(int l,int r)
	{
		if(l>r)swap(l,r);
		l++;
		int k=upper_bound(pw2,pw2+20,r-l+1)-pw2-1;
		return min(ST[k][l],ST[k][r-(1<<k)+1]);
	}
}lcp,lcs;
char s[MX];
LL ans;

int main()
{
	read(L),scanf("%s",s+1);
	n=strlen(s+1);
	pw2[0]=1;
	for(int i=1;i<=20;i++)pw2[i]=pw2[i-1]<<1;
	memcpy(lcp.s+1,s+1,sizeof(char)*n);
	reverse(s+1,s+n+1);
	memcpy(lcs.s+1,s+1,sizeof(char)*n);
	lcp.init(),lcs.init();
	for(int i=1,t,t1,len;i+i+L<=n;i++)for(int l=1,r=i+L+1;r<=n;l+=i,r+=i)
	{
		t=min(i,lcp.ask(lcp.rk[l],lcp.rk[r]));
		t1=min(i,lcs.ask(lcs.rk[n-l+1],lcs.rk[n-r+1]));
		len=t+t1;
		if(t&&t1)len--;
		if(len>=i)ans+=len-i+1;
	}
	write(ans);
	return 0;
}
