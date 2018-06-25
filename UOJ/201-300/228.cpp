#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define int LL
const int maxn=100000+5;

struct node
{
    int l,r;
    LL tag,sum,mx,mn;
}p[maxn<<2];
int n,m;

inline LL read()
{
    char ch=getchar();  LL ans=0LL;
    while(ch<'0'||ch>'9')  ch=getchar();
    while(ch>='0'&&ch<='9')  ans=ans*10+ch-'0',ch=getchar();
    return ans;
}
void pushup(int id)
{
    p[id].mn=min(p[id<<1].mn,p[id<<1|1].mn);
    p[id].mx=max(p[id<<1].mx,p[id<<1|1].mx);
    p[id].sum=p[id<<1].sum+p[id<<1|1].sum;
}
void pushdown(int id)
{
    if(!p[id].tag)  return;
    LL tag=p[id].tag;  int mid=p[id].l+p[id].r>>1;
    p[id<<1].tag+=tag;  p[id<<1|1].tag+=tag;
    p[id<<1].mx+=tag;  p[id<<1|1].mx+=tag;
    p[id<<1].mn+=tag;  p[id<<1|1].mn+=tag;
    p[id<<1].sum+=tag*(mid-p[id].l+1);  p[id<<1|1].sum+=tag*(p[id].r-mid);
    p[id].tag=0;
}
void build(int l,int r,int id)
{
    p[id].l=l,p[id].r=r;
    if(l==r)  {p[id].mx=p[id].mn=p[id].sum=read();  return;}
    int mid=l+r>>1;
    build(l,mid,id<<1),build(mid+1,r,id<<1|1);
    pushup(id);
}
void add(int l,int r,int del,int id)
{
    if(p[id].l==l&&p[id].r==r)
    {
        p[id].mx+=del,p[id].mn+=del,p[id].tag+=del*1LL;
        p[id].sum+=1LL*del*(r-l+1);
        return;
    }
    pushdown(id);
    int mid=p[id].l+p[id].r>>1;
    if(mid>=r)  add(l,r,del,id<<1);
    else  if(l>mid)  add(l,r,del,id<<1|1);
          else  add(l,mid,del,id<<1),add(mid+1,r,del,id<<1|1);
    pushup(id);
}
void sqr(int l,int r,int id)
{
    if(p[id].l==l&&p[id].r==r&&p[id].mx-p[id].mn==(int)sqrt((double)p[id].mx)-(int)sqrt((double)p[id].mn))
    {
        int del=(int)sqrt((double)p[id].mx)-p[id].mx;
        p[id].mx+=del,p[id].mn+=del,p[id].tag+=del*1LL;
        p[id].sum+=1LL*del*(r-l+1);
        return;
    }
    pushdown(id);
    int mid=p[id].l+p[id].r>>1;
    if(mid>=r)  sqr(l,r,id<<1);
    else  if(l>mid)  sqr(l,r,id<<1|1);
          else  sqr(l,mid,id<<1),sqr(mid+1,r,id<<1|1);
    pushup(id);
}
LL ask(int l,int r,int id)
{
    if(p[id].l==l&&p[id].r==r)  return p[id].sum;
    pushdown(id);
    int mid=p[id].l+p[id].r>>1;
    if(mid>=r)  return ask(l,r,id<<1);
    else  if(mid<l)  return  ask(l,r,id<<1|1);
          else  return ask(l,mid,id<<1)+ask(mid+1,r,id<<1|1);
}

signed main()
{
    n=read(),m=read();
    build(1,n,1);
    for(int opt,x,y,r;m--;)
    {
        opt=read(),x=read(),y=read();
        if(opt==1)
		{
			r=read();
			add(x,y,r,1);
		}
        if(opt==2)  sqr(x,y,1);
        if(opt==3)  printf("%lld\n",ask(x,y,1));
    }
    return 0;
}
