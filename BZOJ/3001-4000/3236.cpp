#include<bits/stdc++.h>
using namespace std;
const int MX=100005;
 
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
    template<typename T>inline void write(T x,int f=0)
    {
        tp=0;
        do bf[++tp]=x%10,x/=10;while(x);
        while(tp)putchar(48+bf[tp--]);
        putchar(f?' ':'\n');
    }
}
using FastIO::read;
using FastIO::write;
 
struct Ques{int l,r,id,a,b;}q[MX*10];
int N,M,a[MX],ans1[MX*10],ans2[MX*10],pos[MX],B,TR1[MX],TR2[MX],Num[MX];
 
inline bool cmpl(const Ques& a,const Ques& b)
{
    if(pos[a.l]==pos[b.l])return a.r<b.r;
    return a.l<b.l;
}
inline void add(int *A,int x,int f){for(;x<=N;x+=x&-x)A[x]+=f;}
inline int ask(int *A,int x){int ans=0;for(;x;x-=x&-x)ans+=A[x];return ans;}
inline void upd(int pos,int f)
{
    add(TR1,a[pos],f);
    Num[a[pos]]+=f;
    if(f==1&&Num[a[pos]]==1)add(TR2,a[pos],1);
    if(!~f&&!Num[a[pos]])add(TR2,a[pos],-1);
}
 
int main()
{
    read(N),read(M),B=(int)pow(N,0.5)+1;
    for(int i=1;i<=N;i++)read(a[i]),pos[i]=i/B;
    for(int i=1;i<=M;i++)
    	read(q[i].l),read(q[i].r),read(q[i].a),read(q[i].b);
    sort(q+1,q+M+1,cmpl);
    for(int i=1,l=1,r=0;i<=M;i++)
    {
        while(r<q[i].r)upd(++r,1);
        while(r>q[i].r)upd(r--,-1);
        while(l<q[i].l)upd(l++,-1);
        while(l>q[i].l)upd(--l,1);
        ans1[q[i].id]=ask(TR1,q[i].b)-ask(TR1,q[i].a-1);
        ans2[q[i].id]=ask(TR2,q[i].b)-ask(TR2,q[i].a-1);
    }
    for(int i=1;i<=M;i++)write(ans1[i],1),write(ans2[i]);
    return 0;
}
