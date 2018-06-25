#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=200005,MN=6000000;
#define inline __attribute__((always_inline))

namespace FastIO
{
    const int MXL=1000000;
    struct FastIn
    {
        char BF[MXL],*p1,*p2,c;
        FastIn():p1(BF),p2(BF){}
        inline char getchar(){return p1==p2?p2=(p1=BF)+fread(BF,1,MXL,stdin),p1==p2?EOF:*p1++:*p1++;}
        template<typename T>inline void operator()(T& x)
        {
            x=0,c=getchar();
            while(!isdigit(c))c=getchar();
            while(isdigit(c))x=x*10+c-'0',c=getchar();
        }
        inline void getstr(char *s)
        {
            while(!isdigit(*s=getchar()));
            while((*++s=getchar())!=' ');
            *s=0;
        }
    };
    struct FastOut
    {
        char BF[MXL],*p1,*const p2;
        int bf[22],tp;
        FastOut():p1(BF),p2(BF+MXL){}
        ~FastOut(){flush();}
        inline void putchar(char c){if(p1==p2)flush();*p1++=c;}
        inline void flush(){fwrite(BF,1,p1-BF,stdout),p1=BF;}
        template<typename T>inline void operator()(T x)
        {
            bf[tp=1]='\n'-48;
            do bf[++tp]=x%10,x/=10;while(x);
            while(tp)putchar(48+bf[tp--]);
        }
    };
}
FastIO::FastIn IN;
FastIO::FastOut OUT;

int N,M,a[MX],nxt[MX],pre[MX],s[105],mid,tot;
char ch[10000005];
struct Trie
{
	int num,cnt[MN],son[MN][6],fail[MN],rtt[55];

    Trie():num(1){}
    inline void insert(int u)
    {
    	if(!son[1][u])son[1][u]=++num,fail[num]=1;
    	cnt[son[1][u]]++;
    }
	inline void modify(int sig)
	{
		register int rt=1,_rt;
		for(register int i=1;i<=mid;i++)rt=son[rt][s[i]];
		for(register int i=1;i<mid;i++,rt=fail[rt])
		{
		    _rt=rt;
		    for(register int l=mid-i+2,j=mid+1;l<=50&&j<=tot;j++,l++)
		    {
		        if(!son[_rt][s[j]])son[_rt][s[j]]=++num;
		        _rt=son[_rt][s[j]],cnt[_rt]+=sig;
		        if(~sig)
		        {
		            if(i>1)fail[rtt[l+1]]=_rt;
		            rtt[l]=_rt;
		        }
		    }
		}
		_rt=1;
		for(register int l=2,i=mid+1;l<=50&&i<=tot;i++,l++)
		{
		    _rt=son[_rt][s[i]];
		    if(!son[rt][s[i]])son[rt][s[i]]=++num;
		    rt=son[rt][s[i]],cnt[rt]+=sig;
		    if(~sig)
		    {
		        if(mid>1)fail[rtt[l+1]]=rt;
		        fail[rt]=_rt;
		    }
		}
	}
	inline int query(int l)
	{
		register int ret=1,rt=1;
		for(register int i=1;i<l;i++)rt=son[rt][ch[i]-49];
		for(register int i=l;ch[i]&&ret;rt=fail[rt],i++)
		    rt=son[rt][ch[i]-49],ret=(LL)ret*cnt[rt]%998244353;
		return ret;
	}
}T;

int main()
{
    IN(N),IN(M);
    for(int i=1;i<=N;i++)IN(a[i]),T.insert(--a[i]);
    for(register int op,x,y,i,j;M--;)
    {
        IN(op);
        if(op==1)
        {
            IN(x),IN(y);
            pre[y]=x,nxt[x]=y;
            for(i=1;x&&i<50;x=pre[x],i++)s[i]=a[x];
            reverse(s+1,s+i);
            for(j=0;y&&j<49;y=nxt[y],j++)s[i+j]=a[y];
            mid=i-1,tot=i+j-1,T.modify(1);
        }
        else if(op==2)
        {
            IN(x),y=nxt[x];
            pre[y]=nxt[x]=0;
            for(i=1;x&&i<50;x=pre[x],i++)s[i]=a[x];
            reverse(s+1,s+i);
            for(j=0;y&&j<49;y=nxt[y],j++)s[i+j]=a[y];
            mid=i-1,tot=i+j-1,T.modify(-1);
        }
        else IN.getstr(ch+1),IN(x),OUT(T.query(x));
    }
    return 0;
}
