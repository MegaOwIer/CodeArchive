#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using LL=long long;
const int MX=200005,mod=998244353;

int N;
set<pii> S[MX];

struct Segment
{
    int val,mtag,ptag;
    Segment *l,*r;

    Segment():val(0),mtag(1),ptag(0),l(nullptr),r(nullptr){}
    void modify(int _m,int _p,int len)
    {
        mtag=(LL)mtag*_m%mod;
        ptag=((LL)ptag*_m+_p)%mod;
        val=((LL)val*_m+(LL)_p*len)%mod;
    }
    void pushdown(int L,int R)
    {
        if(mtag==1&&!ptag)return;
        int mid=L+R>>1;
        l->modify(mtag,ptag,mid-L+1);
        r->modify(mtag,ptag,R-mid);
        mtag=1,ptag=0;
    }
    void maintain(){val=(l->val+r->val)%mod;}
}*root;

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
    if(L==R)return;
    int mid=L+R>>1;
    build(o->l,L,mid),build(o->r,mid+1,R);
}
void modify(Segment *o,int l,int r,int L,int R,int _m,int _p)
{
    if(l<=L&&R<=r)return o->modify(_m,_p,R-L+1);
    o->pushdown(L,R);
    int mid=L+R>>1;
    if(l<=mid)modify(o->l,l,r,L,mid,_m,_p);
    if(r>mid)modify(o->r,l,r,mid+1,R,_m,_p);
    o->maintain();
}
int query(Segment *o,int l,int r,int L,int R)
{
    if(l<=L&&R<=r)return o->val;
    o->pushdown(L,R);
    int ans=0,mid=L+R>>1;
    if(l<=mid)ans+=query(o->l,l,r,L,mid);
    if(r>mid)ans+=query(o->r,l,r,mid+1,R);
    return ans%mod;
}

int main()
{
    build(root,1,N=read());
    for(int Q=read(),op,l,r,x,L,R;Q--;)
    {
        op=read(),l=read(),r=read();
        if(op==1)
        {
            x=read(),L=l,R=r,modify(root,l,r,1,N,1,1);
            while(true)
            {
                auto it=S[x].lower_bound(make_pair(l,-1));
                if(it==S[x].end()||it->first>r)break;
                modify(root,it->first,min(r,it->second),1,N,2,mod-2);
                R=max(R,it->second),S[x].erase(it);
            }
            auto it=S[x].lower_bound(make_pair(l,-1));
            if(it!=S[x].begin()&&(--it)->second>=l)
            {
                modify(root,l,min(r,it->second),1,N,2,mod-2);
                S[x].erase(it),L=min(it->first,L),R=max(R,it->second);
            }
            S[x].insert(make_pair(L,R));
        }
        else printf("%d\n",query(root,l,r,1,N));
    }
    return 0;
}
