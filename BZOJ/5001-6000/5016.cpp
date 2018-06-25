#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=50005;

int B,pos[MX],N,a[MX],cntl[MX],cntr[MX],Q,cnt;
LL ans[MX],res;
struct Ques
{
    int l,r,id,f;
    Ques(){}
    Ques(int _l,int _r,int id,int f):id(id),f(f)
    {
        if(l>r)swap(l,r);
        l=_l,r=_r;
    }
    bool operator<(const Ques& a)const{return pos[a.l]==pos[l]?r<a.r:pos[l]<pos[a.l];}
}q[MX<<2];

inline void read(int& x)
{
    static char c;
    c=getchar(),x=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
    read(N),B=pow(N,0.5);
    for(int i=1;i<=N;i++)read(a[i]);
    for(int i=1;i<=N;i++)pos[i]=i/B;
    read(Q);
    for(int i=1,l1,l2,r1,r2;i<=Q;i++)
    {
        read(l1),read(r1),read(l2),read(r2);
        q[++cnt]=Ques(r1,r2,i,1);
        q[++cnt]=Ques(l1-1,l2-1,i,1);
        q[++cnt]=Ques(l1-1,r2,i,-1);
        q[++cnt]=Ques(r1,l2-1,i,-1);
    }
    sort(q+1,q+cnt+1);
    for(int i=1,l=0,r=0;i<=cnt;i++)
    {
        while(q[i].r>r)r++,cntr[a[r]]++,res+=cntl[a[r]];
        while(q[i].r<r)cntr[a[r]]--,res-=cntl[a[r]],r--;
        while(q[i].l>l)l++,cntl[a[l]]++,res+=cntr[a[l]];
        while(q[i].l<l)cntl[a[l]]--,res-=cntr[a[l]],l--;
        ans[q[i].id]+=q[i].f*res;
    }
    for(int i=1;i<=Q;i++)printf("%lld\n",ans[i]);
    return 0;
}