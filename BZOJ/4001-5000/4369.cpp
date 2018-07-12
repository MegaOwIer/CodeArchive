#include<bits/stdc++.h>
using namespace std;

const int MX=500005;
#define cin FAKE_ISTREAM

int N,K[200005],Q;
pair<int,int> P[MX];

struct Istream
{
    static const int MXL=2000000;
    char bf[MXL],*p1,*p2;
    FILE *F;
    Istream(FILE *F):p1(bf),p2(bf),F(F){}
    char getchar(){return p1==p2&&(p2=(p1=bf)+fread(bf,1,MXL,F))==bf?EOF:*p1++;}
    template<typename T>Istream& operator >> (T &x)
    {
        x=0;  int c=getchar();
        while(!isdigit(c))c=getchar();
        while(isdigit(c))x=x*10+c-'0',c=getchar();
        return *this;
    }
}cin(stdin);

struct nulltag{};
struct Segment
{
    Segment *l,*r;
    int sum;
    Segment(){}
    Segment(int);
    Segment(Segment *o):l(o->l),r(o->r),sum(o->sum){}
    Segment(nulltag):l(this),r(this),sum(0){}
    void* operator new (size_t);
    void maintain(){sum=l->sum+r->sum;}
}*null=new Segment(nulltag()),*TR[MX],*cur;
Segment Pool[MX<<5],*ptr=Pool;
inline Segment::Segment(int val):l(null),r(null),sum(val){}
inline void* Segment::operator new (size_t){return ptr++;}

void insert(Segment* &o,Segment *p,int pos,int L,int R)
{
    o=new Segment(p->sum+1);
    if(L==R)return;
    int mid=L+R>>1;
    if(pos<=mid)insert(o->l,p->l,pos,L,mid),o->r=p->r;
    else insert(o->r,p->r,pos,mid+1,R),o->l=p->l;
}
void query(Segment *p,Segment* &o,int l,int r,int L,int R)
{
    if(l<=L&&R<=r){o=p;return;}
    if(o<cur)o=new Segment(o);
    int mid=L+R>>1;
    if(l<=mid)query(p->l,o->l,l,r,L,mid);
    if(r>mid)query(p->r,o->r,l,r,mid+1,R);
    o->maintain();
}
void Kth(Segment *p,Segment* &o,int K,int L,int R)
{
    if(o<cur)o=new Segment(o);
    if(L==R){o->sum+=K;return;}
    int mid=L+R>>1;
    int tmp=p->l->sum-o->l->sum;
    if(K<=tmp)Kth(p->l,o->l,K,L,mid);
    else o->l=p->l,Kth(p->r,o->r,K-tmp,mid+1,R);
    o->maintain();
}
bool can(int M,int *K)
{
    ptr=cur;
    if(M>N)return 0;
    long long sum=0;
    for(int i=0;i<M;i++)sum+=K[i];
    if(sum>N)return 0;
    sort(K,K+M);
    Segment *tmp=new Segment(0);
    for(int i=0;i<M;i++)
    {
        Segment *pos=TR[upper_bound(P+1,P+N+1,make_pair(K[i],N+1))-P-1];
        if(K[i]!=1)query(pos,tmp,1,K[i]-1,1,N);
        if(pos->sum-tmp->sum<K[i])return 0;
        Kth(pos,tmp,K[i],1,N);
    }
    return 1;
}

int main()
{
    cin>>N;
    for(int i=1,u,v;i<=N;i++)
        cin>>u>>v,P[i]=make_pair(u,v);
    sort(P+1,P+N+1);
    TR[0]=null;
    for(int i=1;i<=N;i++)
        insert(TR[i],TR[i-1],P[i].second,1,N);
    cur=ptr;
    cin>>Q;
    for(int i=1,M;i<=Q;i++)
    {
        cin>>M;
        for(int j=1;j<=M;j++)cin>>K[j];
        puts(can(M,K+1)?"1":"0");
    }
    return 0;
}