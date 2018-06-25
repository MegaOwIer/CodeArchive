#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int N,M,ls[MX<<2];

struct cond
{
    int l,r,a;
    bool operator < (const cond& a)const{return r<a.r;}
}q[MX<<1];

struct Segment
{
    Segment *l,*r;
    int tag,mx;

    Segment():l(0),r(0),tag(0),mx(0){}
    void* operator new(size_t);
    void set(int val){mx=val;}
    void modify(int val){mx+=val,tag+=val;}
    void maintain(){mx=max(l->mx,r->mx);}
    void pushdown(){l->modify(tag),r->modify(tag),tag=0;}
}*root,Pool[MX<<3],*ptr;
inline void* Segment::operator new(size_t){return ptr++;}

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
void build(Segment* &o,int L,int R)
{
    o=new Segment;
    if(L==R)return o->set(ls[L]-1);
    void* operator new(size_t);
    void set(int val){mx=val;}
    void modify(int val){mx+=val,tag+=val;}
    void maintain(){mx=max(l->mx,r->mx);}
    void pushdown(){l->modify(tag),r->modify(tag),tag=0;}
}*root,Pool[MX<<3],*ptr;
inline void* Segment::operator new(size_t){return ptr++;}

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
void build(Segment* &o,int L,int R)
{
    o=new Segment;
    if(L==R)return o->set(ls[L]-1);
    int mid=L+R>>1;
    build(o->l,L,mid),build(o->r,mid+1,R);
    o->maintain();
}
void insert(Segment *o,int l,int r,int L,int R,int val)
{
    if(l<=L&&R<=r)return o->modify(val);
    int mid=L+R>>1;
    o->pushdown();
    if(l<=mid)insert(o->l,l,r,L,mid,val);
    if(r>mid)insert(o->r,l,r,mid+1,R,val);
    o->maintain();
}
int query(Segment *o,int l,int r,int L,int R)
{
    if(l<=L&&R<=r)return o->mx;
    int mid=L+R>>1,ans=0;
    o->pushdown();
    if(l<=mid)ans=max(ans,query(o->l,l,r,L,mid));
    if(r>mid)ans=max(ans,query(o->r,l,r,mid+1,R));
    return ans;
}

int main()
{
    for(int T=read();T--;)
    {
        int tot=0,sum=0,cnt=0;
        N=read(),M=read(),ptr=Pool;
        for(int i=1,l,r,a;i<=N;i++)
        {
            l=read()+1,r=read()+1,a=read(),sum+=a;
            if(l<=r)q[++tot]=(cond){l,r,a},q[++tot]=(cond){l+M,r+M,a};
            else q[++tot]=(cond){l,r+M,a};
        }
        if(sum>M){puts("No");continue;}
        for(int i=1;i<=tot;i++)ls[++cnt]=q[i].l,ls[++cnt]=q[i].r;
        sort(ls+1,ls+cnt+1),cnt=unique(ls+1,ls+cnt+1)-ls-1;
        sort(q+1,q+tot+1),build(root,1,cnt);
        bool flag=false;
        for(int i=1,l,r;i<=tot;i++)
        {
            l=lower_bound(ls+1,ls+cnt+1,q[i].l)-ls;
            r=lower_bound(ls+1,ls+cnt+1,q[i].r)-ls;
            insert(root,1,l,1,cnt,q[i].a);
            if(query(root,1,l,1,cnt)>ls[r]){flag=1;break;}
        }
        puts(flag?"No":"Yes");
    }
    return 0;
}
