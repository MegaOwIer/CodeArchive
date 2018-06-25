#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100005;

struct node
{
    int l,r,mx;
    LL sum;
}p[maxn<<2];
int pos[maxn],n,m;

inline int read()
{
    char ch=getchar();  int ans=0;
    while(ch<'0'||ch>'9')  ch=getchar();
    while(ch>='0'&&ch<='9')  ans=ans*10+ch-'0',ch=getchar();
    return ans;  
}
inline void pushup(int id)
{
    p[id].mx=max(p[id<<1].mx,p[id<<1|1].mx);
    p[id].sum=p[id<<1].sum+p[id<<1|1].sum;
}
void build(int l,int r,int id)
{
    p[id].l=l,p[id].r=r;
    if(l==r)  {p[id].sum=p[id].mx=read();  pos[l]=id;  return;}
    int mid=l+r>>1;
    build(l,mid,id<<1);  build(mid+1,r,id<<1|1);
    pushup(id);
}
LL ask(int l,int r,int id)
{
    if(p[id].l==l&&p[id].r==r)  return p[id].sum;
    int mid=p[id].l+p[id].r>>1;
    if(mid>=r)  return ask(l,r,id<<1);
    else  if(mid<l)  return ask(l,r,id<<1|1);
          else  return ask(l,mid,id<<1)+ask(mid+1,r,id<<1|1);
}
void mod(int l,int r,int mo,int id)
{
    if(p[id].l==l&&p[id].r==r&&p[id].mx<mo)  return;
    if(p[id].l==l&&p[id].r==r&&l==r)  {p[id].mx%=mo,p[id].sum%=1LL*mo;  return;}
    int mid=p[id].l+p[id].r>>1;
    if(mid>=r)  mod(l,r,mo,id<<1);
    else  if(mid<l)  mod(l,r,mo,id<<1|1);
          else  mod(l,mid,mo,id<<1),mod(mid+1,r,mo,id<<1|1);
    pushup(id); 
}
void insert(int pos,int val)
{
    p[pos].sum=val*1LL;  p[pos].mx=val;
    for(int i=pos>>1;i;i>>=1)  pushup(i);
}

int main()
{
    n=read(),m=read();  build(1,n,1);
    for(int opt,l,r,x;m--;)
    {
        opt=read(),l=read(),r=read();
        if(opt==1)  printf("%lld\n",ask(l,r,1));
        else  if(opt==2)  x=read(),mod(l,r,x,1);
              else  insert(pos[l],r);
    }
    return 0;
}
