#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

namespace FastIO
{
	const int MXL=200000;
	class FastIn
	{
	private:
		char BF[MXL],*p1,*p2,c;
		char getchar(){return p1==p2?p2=(p1=BF)+fread(BF,1,MXL,stdin),p1==p2?EOF:*p1++:*p1++;}
	public:
		FastIn():p1(BF),p2(BF){}
		template<typename T>void operator()(T& x)
		{
			x=0,c=getchar();
			while(!isdigit(c))c=getchar();
			while(isdigit(c))x=x*10+c-'0',c=getchar();
		}
	};
	class FastOut
	{
	private:
		char BF[MXL],*p1,*const p2;
		int bf[12],tp;
		void putchar(char c){if(p1==p2)flush();*p1++=c;}
		void flush(){fwrite(BF,1,p1-BF,stdout),p1=BF;}
	public:
		FastOut():p1(BF),p2(BF+MXL){}
		~FastOut(){flush();}
		template<typename T>void operator()(T x)
		{
			bf[tp=1]='\n'-48;
			do bf[++tp]=x%10,x/=10;while(x);
			while(tp)putchar(48+bf[tp--]);
		}
	};
}

struct Change{int pos,val;}ch[MX];
struct Ques{int l,r,t,id;}q[MX];
int N,Q,a[MX],pos[MX],cntc,cntq,ls[MX<<1],tot,cnt,B,num[MX<<1],numnum[MX<<1],ans[MX];
FastIO::FastIn IN;
FastIO::FastOut OUT;

inline bool cmp1(Ques& a,Ques& b)
{
	if(pos[a.l]!=pos[b.l])return pos[a.l]<pos[b.l];
	if(pos[a.r]!=pos[b.r])return pos[a.r]<pos[b.r];
	return a.t<b.t;
}
inline void dec(int u){numnum[num[u]]--,num[u]--,numnum[num[u]]++;}
inline void inc(int u){numnum[num[u]]--,num[u]++,numnum[num[u]]++;}
inline void change(int u,int l,int r)
{
	if(l<=ch[u].pos&&ch[u].pos<=r)dec(a[ch[u].pos]);
	swap(a[ch[u].pos],ch[u].val);
	if(l<=ch[u].pos&&ch[u].pos<=r)inc(a[ch[u].pos]);
}
inline int get()
{
	int ans=1;
	while(numnum[ans])ans++;
	return ans;
}

int main()
{
	IN(N),IN(Q),B=pow(N,0.66)+1;
	for(int i=1;i<=N;i++)pos[i]=i/B;
	for(int i=1;i<=N;i++)IN(a[i]),ls[++cnt]=a[i];
	for(int i=1,op,l,r;i<=Q;i++)
	{
		IN(op),IN(l),IN(r);
		if(op&1)q[++cntq]=(Ques){l,r,cntc,cntq};
		else ch[++cntc]=(Change){l,r},ls[++cnt]=r;
	}
	sort(ls+1,ls+cnt+1),tot=unique(ls+1,ls+cnt+1)-ls-1;
	for(int i=1;i<=N;i++)a[i]=lower_bound(ls+1,ls+tot+1,a[i])-ls;
	for(int i=1;i<=cntc;i++)ch[i].val=lower_bound(ls+1,ls+tot+1,ch[i].val)-ls;
	sort(q+1,q+cntq+1,cmp1);
	for(int i=1,l=1,r=0,t=0;i<=cntq;i++)
	{
		while(t<q[i].t)change(++t,l,r);
		while(t>q[i].t)change(t--,l,r);
		while(r<q[i].r)inc(a[++r]);
		while(r>q[i].r)dec(a[r--]);
		while(l<q[i].l)dec(a[l++]);
		while(l>q[i].l)inc(a[--l]);
		ans[q[i].id]=get();
	}
	for(int i=1;i<=cntq;i++)OUT(ans[i]);
	return 0;
}
