#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=40005,mod=1000000007;
 
int N,a[MX+10000],Q,cnt,val[5135],ans,pr[5135];
bitset<4203> num[MX],tmp;
bool vis[MX+10000];
struct Segment
{
    int prod;
    LL sum;
    bitset<4203> prime;
    Segment *l,*r;
    Segment():l(NULL),r(NULL){}
    void* operator new(size_t);
    void setval(int val){sum=prod=val,prime=num[val];}
    void work(){ans=(LL)ans*prod%mod,tmp|=prime;}
    void maintain()
    {
        sum=l->sum+r->sum;
        prod=(LL)l->prod*r->prod%mod;
        prime=l->prime|r->prime;
    }
}*root;
 
inline void* Segment::operator new(size_t)
{
    static Segment Pool[MX<<2],*prt=Pool;
    return prt++;
}
 
inline void read(int& x)
{
    static char c;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline int Pow(int a,int b)
{
    int ans=1;
    for(;b;b>>=1,a=(LL)a*a%mod)
        if(b&1)ans=(LL)ans*a%mod;
    return ans;
}
void build(Segment* &o,int L,int R)
{
    o=new Segment;
    if(L==R)return o->setval(a[L]);
    int mid=L+R>>1;
    build(o->l,L,mid),build(o->r,mid+1,R);
    o->maintain();
}
void modify(Segment* o,int pos,int val,int L,int R)
{
    if(L==R)return o->setval(val);
    int mid=L+R>>1;
    if(pos<=mid)modify(o->l,pos,val,L,mid);
    else modify(o->r,pos,val,mid+1,R);
    o->maintain();
}
int getphi(int val)
{
    int ans=val%mod;
    for(int i=0;(LL)pr[i]*pr[i]<=val;i++)if(val%pr[i]==0)
    {
    	while(val%pr[i]==0)val/=pr[i];
    	ans=(LL)ans*::val[i]%mod;
    }
    if(val>1)ans=(LL)ans*(val-1)%mod*Pow(val,mod-2)%mod;
    return ans;
}
int ask1(Segment *o,int l,int r,int L,int R)
{
    if(L==l&&r==R)return o->sum;
    int mid=L+R>>1;
    if(r<=mid)return ask1(o->l,l,r,L,mid);
    else if(l>mid)return ask1(o->r,l,r,mid+1,R);
    else return ask1(o->l,l,mid,L,mid)+ask1(o->r,mid+1,r,mid+1,R);
}
void ask2(Segment *o,int l,int r,int L,int R)
{
    if(l<=L&&R<=r)return o->work();
    int mid=L+R>>1;
    if(l<=mid)ask2(o->l,l,r,L,mid);
    if(r>mid)ask2(o->r,l,r,mid+1,R);
}
 
int main()
{
    for(int i=2;i<=50000;i++)if(!vis[i])
    {
        pr[cnt]=i,val[cnt++]=(LL)(i-1)*Pow(i,mod-2)%mod;
        for(int j=i;j<=50000;j+=i)vis[j]=1;
    }
    for(int i=0;pr[i]<40000;i++)
        for(int j=pr[i];j<=40000;j+=pr[i])
            num[j].set(i);
    read(N),read(Q);
    for(int i=1;i<=N;i++)read(a[i]);
    build(root,1,N);
    for(int i=1,op,l,x;i<=Q;i++)
    {
        read(op),read(l),read(x);
        if(op==0)modify(root,l,x,1,N);
        else if(op==1)printf("%d\n",getphi(ask1(root,l,x,1,N)));
        else
        {
            ans=1,tmp.reset();
            ask2(root,l,x,1,N);
            for(int j=tmp._Find_first();j<tmp.size();j=tmp._Find_next(j))
                ans=(LL)ans*val[j]%mod;
            printf("%d\n",ans);
        }
    }
    return 0;
}
