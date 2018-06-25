#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=50005;

namespace FastIO
{
    char c;
    int bf[22],tp;
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

struct Ques
{
	int l,r,id;
	LL ans;
	void print();
	bool operator < (const Ques& b)const{return id<b.id;}
}q[MX];
int N,M,col[MX],pos[MX],B,Num[MX];
LL ans;

inline bool cmpl(const Ques& a,const Ques& b)
{
	if(pos[a.l]==pos[b.l])return a.r<b.r;
	return a.l<b.l;
}
inline LL gcd(LL u,LL v){return v?gcd(v,u%v):u;}
inline void Ques::print()
{
	LL res=(LL)(r-l+1)*(r-l)/2,d;
	d=gcd(res,ans);
	write(ans/d),putchar('/'),write(res/d),putchar('\n');
}

int main()
{
	read(N),read(M),B=1+(int)pow(N,0.5);
	for(int i=1;i<=N;i++)pos[i]=i/B;
	for(int i=1;i<=N;i++)read(col[i]);
	for(int i=1;i<=M;i++)read(q[i].l),read(q[i].r),q[i].id=i;
	sort(q+1,q+M+1,cmpl);
	for(int i=1,l=1,r=0;i<=M;i++)
	{
		while(r<q[i].r)++r,ans+=Num[col[r]],++Num[col[r]];
		while(r>q[i].r)--Num[col[r]],ans-=Num[col[r]],--r;
		while(l<q[i].l)--Num[col[l]],ans-=Num[col[l]],++l;
		while(l>q[i].l)--l,ans+=Num[col[l]],++Num[col[l]];
		q[i].ans=ans;
	}
	sort(q+1,q+M+1);
	for(int i=1;i<=M;i++)q[i].print();
	return 0;
}
