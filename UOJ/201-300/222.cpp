#include<bits/stdc++.h>
using namespace std;
const int MX=500005;

int N,M,ls[MX<<1],tot,ans=2147483647;

struct interval
{
    int l,r,len;
    bool operator < (const interval& a)const{return len>a.len;}
}e[MX];

struct Segment{int mx,tag;}p[MX<<3];
#define lson p[id<<1]
#define rson p[id<<1|1]

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline void pushdown(int id)
{
    int val=p[id].tag;
    lson.tag+=val,lson.mx+=val;
    rson.tag+=val,rson.mx+=val;
    p[id].tag=0;
}
void insert(int l,int r,int val,int L,int R,int id)
{
    if(l<=L&&R<=r)
    {
        p[id].tag+=val,p[id].mx+=val;
        return;
    }
    pushdown(id);
    int mid=L+R>>1;
    if(l<=mid)insert(l,r,val,L,mid,id<<1);
    if(r>mid)insert(l,r,val,mid+1,R,id<<1|1);
    p[id].mx=max(lson.mx,rson.mx);
}

int main()
{
    N=read(),M=read();
    for(int i=1;i<=N;i++)
    {
        ls[++tot]=e[i].l=read();
        ls[++tot]=e[i].r=read();
        e[i].len=e[i].r-e[i].l;
    }
    sort(ls+1,ls+tot+1),tot=unique(ls+1,ls+tot+1)-ls-1;
    for(int i=1;i<=N;i++)
        e[i].l=lower_bound(ls+1,ls+tot+1,e[i].l)-ls,
        e[i].r=lower_bound(ls+1,ls+tot+1,e[i].r)-ls;
    sort(e+1,e+N+1);
    for(int i=1,j=1;i<=N;i++)
    {
        while(j<=N&&p[1].mx<M)insert(e[j].l,e[j].r,1,1,tot,1),j++;
        if(p[1].mx>=M)ans=min(ans,e[i].len-e[j-1].len);
        else break;
        insert(e[i].l,e[i].r,-1,1,tot,1);
    }
    printf("%d\n",ans==(-1U>>1)?-1:ans);
    return 0;
}
