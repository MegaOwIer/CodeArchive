#include<bits/stdc++.h>
using namespace std;

const int MX=500005;

int N,K[MX];
pair<int,int> P[MX];

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

void init(int N,int *A,int *B)
{
    ::N=N,TR[0]=null;
    for(int i=0;i<N;i++)P[i+1]=make_pair(A[i],B[i]);
    sort(P+1,P+N+1);
    for(int i=1;i<=N;i++)
        insert(TR[i],TR[i-1],P[i].second,1,N);
    cur=ptr;
}
int can(int M,int *_K)
{
    ptr=cur;
    if(M>N)return 0;
    long long sum=0;
    memcpy(K+1,_K,sizeof(int)*M);
    for(int i=1;i<=M;i++)sum+=K[i];
    if(sum>N)return 0;
    sort(K+1,K+M+1);
    Segment *tmp=new Segment(0);
    for(int i=1;i<=M;i++)
    {
        Segment *pos=TR[upper_bound(P+1,P+N+1,make_pair(K[i],N+1))-P-1];
        if(K[i]!=1)query(pos,tmp,1,K[i]-1,1,N);
        if(pos->sum-tmp->sum<K[i])return 0;
        Kth(pos,tmp,K[i],1,N);
    }
    return 1;
}
