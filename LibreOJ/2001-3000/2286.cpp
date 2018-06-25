#include<bits/stdc++.h>
using namespace std;
typedef unsigned U;
typedef unsigned long long ULL;

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
	}
	inline void output_arr(U *A,U ret)
	{
	    U blocks=ret>>2,x=23333333;
	    for(U i=0;i<blocks;++i)ret=ret^(A[i]+x),x^=x<<13,x^=x>>17,x^=x<<5;
	    write(ret);
	}
}
using FastIO::read;
using FastIO::write;

U a[200000000],b[200000000];

namespace Sorting
{
	int n,sum[259],i;
	U x;
	
	void main()
	{
		read(n),read(x);
		for(i=0;i<n;i++)a[i]=(x^=x<<13,x^=x>>17,x^=x<<5);
#define add(i) sum[a[i]&255]++
#define add1(i,j) sum[a[i]>>j&255]++
#define add2(i,j) sum[b[i]>>j&255]++
#define add3(i) sum[b[i]>>24]++
#define set(i) b[--sum[a[i]&255]]=a[i]
#define set1(i,j) b[--sum[a[i]>>j&255]]=a[i]
#define set2(i,j) a[--sum[b[i]>>j&255]]=b[i]
#define set3(i) a[--sum[b[i]>>24]]=b[i]
	    memset(sum,0,sizeof(int)<<8);
	    for(i=0;i<n;i+=4)add(i),add(i+1),add(i+2),add(i+3);
	    for(i=1;i<256;++i)sum[i]+=sum[i-1];
	    for(i=n-4;i>=0;i-=4)set(i+3),set(i+2),set(i+1),set(i);
	    memset(sum,0,sizeof(int)<<8);
	    for(i=0;i<n;i+=4)add2(i,8),add2(i+1,8),add2(i+2,8),add2(i+3,8);
	    for(i=1;i<256;++i)sum[i]+=sum[i-1];
	    for(i=n-4;i>=0;i-=4)set2(i+3,8),set2(i+2,8),set2(i+1,8),set2(i,8);
	    memset(sum,0,sizeof(int)<<8);
	    for(i=0;i<n;i+=4)add1(i,16),add1(i+1,16),add1(i+2,16),add1(i+3,16);
	    for(i=1;i<256;++i)sum[i]+=sum[i-1];
	    for(i=n-4;i>=0;i-=4)set1(i+3,16),set1(i+2,16),set1(i+1,16),set1(i,16);
	    memset(sum,0,sizeof(int)<<8);
	    for(i=0;i<n;i+=4)add3(i),add3(i+1),add3(i+2),add3(i+3);
	    for(i=1;i<256;++i)sum[i]+=sum[i-1];
	    for(i=n-4;i>=0;i-=4)set3(i+3),set3(i+2),set3(i+1),set3(i);
	    FastIO::output_arr(a,sizeof(U)*n);
#undef add
#undef add1
#undef add2
#undef add3
#undef set
#undef set1
#undef set2
#undef set3
	}
}

namespace Game
{
	const int MX=300005;

	int n,q,i,cnt[1<<16|1],j,p,lim;
	U b1[32][30005],b2[32][30005],*f1,*f2,ans;
	char s1[MX],s2[MX];
	
#define set(s,pos) s[(pos)>>5]|=1U<<((pos)&31)
#define modify(x,p) for(j=0;j<32&&j<=(p);j++)set(b##x[j],(p)-j)
#define wk(k) ans+=popcount(f1[i+k]&f2[j+k])
	inline int popcount(U x){return cnt[x&65535]+cnt[x>>16];}
	void main()
	{
		read(n),read(q),scanf("%s%s",s1,s2);
		for(int i=1;i<65536;i++)cnt[i]=cnt[i>>1]+(i&1);
		for(i=0;i<n;i++)
			if(s1[i]=='0')modify(1,3*i);
			else if(s1[i]=='1')modify(1,3*i+1);
			else modify(1,3*i+2);
		for(i=0;i<n;i++)
			if(s2[i]=='1')modify(2,3*i);
			else if(s2[i]=='2')modify(2,3*i+1);
			else modify(2,3*i+2);
		for(int Q=0,x,y,l;Q<q;Q++)
		{
			read(x),read(y),read(l);
			x*=3,y*=3,l*=3;
			f1=b1[x&31],f2=b2[y&31],ans=0;
			for(i=x>>5,j=y>>5,p=0,lim=l>>5;p+4<lim;p+=4,i+=4,j+=4)
				wk(0),wk(1),wk(2),wk(3);
			for(;p<lim;p++,i++,j++)ans+=popcount(f1[i]&f2[j]);
			ans+=popcount(f1[i]&f2[j]&((1U<<(l&31))-1));
			a[Q]=ans;
		}
		FastIO::output_arr(a,sizeof(U)*q);
	}
#undef set
#undef modify
#undef wk
}

namespace Parentheses
{
	const int MX=266670;
	
	int n,siz;
	char s[MX];
	U f[600010],*dp=f+300000;

#define wk(x,y) dp[j+x]+=dp[j+y]
	void main()
	{
		read(n),scanf("%s",s+1);
		dp[0]=1;
		for(int i=1,j,lim;i<=n;i++)
		{
			if(s[i]=='(')*--dp=0;
			else if(s[i]==')')*dp++=0;
			else
			{
				*--dp=0,lim=min(i,n-i)+2;
				for(j=i&1;j<lim;j+=8)
					wk(0,2),wk(2,4),wk(4,6),wk(6,8);
				for(j-=2;j>=lim;j-=2)dp[j]-=dp[j+2];
			}
		}
		write(dp[0]);
	}
#undef wk
}

int id;

int main()
{
    read(id);
    if(id==1)Sorting::main();
    else if(id==2)Game::main();
    else Parentheses::main();
    return 0;
}
