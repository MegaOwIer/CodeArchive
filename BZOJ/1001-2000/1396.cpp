#include<bits/stdc++.h>
using namespace std;
const int MX=100005,INF=2147483647;

int N,num[MX];
char s[MX];

struct SuffixAutomaton
{
    struct Node
    {
        Node *son[26],*link;
        int length,siz,endpos;
        
        Node(int s=0):siz(s){}
        void* operator new (size_t);
    }*start,*last;

    SuffixAutomaton()
    {
        start=new Node;
        start->length=0,start->endpos=0;
        last=start;
    }
    Node* extend(int val)
    {
        Node *o=last,*p=new Node(1);
        p->length=o->length+1,p->endpos=o->endpos+1;
        while(o&&!o->son[val])o->son[val]=p,o=o->link;
        if(!o)return p->link=start,last=p;
        Node *q=o->son[val];
        if(q->length==o->length+1)return p->link=q,last=p;
        Node *clone=new Node;
        clone->length=o->length+1;
        clone->link=q->link;
        clone->endpos=q->endpos;
        memcpy(clone->son,q->son,sizeof(q->son));
        p->link=q->link=clone;
        while(o&&o->son[val]==q)o->son[val]=clone,o=o->link;
        return last=p;
    }
}SAM;
typedef SuffixAutomaton::Node SAMNode;
SAMNode SAMNodePool[MX<<1],*ptr=SAMNodePool,*topo[MX<<1];
inline void* SAMNode::operator new (size_t){return ptr++;}

struct Segment
{
    Segment *l,*r;
    int mn;

    Segment():l(NULL),r(NULL),mn(INF){}
    void* operator new (size_t);
    void modify(int val){mn=min(mn,val);}
    void pushdown(){l->modify(mn),r->modify(mn),mn=INF;}
}*T1,*T2;
inline void* Segment::operator new (size_t)
{
    static Segment Pool[MX<<2],*ptr=Pool;
    return ptr++;
}

void build(Segment* &o,int L,int R)
{
    o=new Segment;
    if(L==R)return;
    int mid=L+R>>1;
    build(o->l,L,mid),build(o->r,mid+1,R);
}
void insert(Segment *o,int l,int r,int val,int L,int R)
{
    if(!o)o=new Segment;
    if(l<=L&&R<=r)return o->modify(val);
    o->pushdown();
    int mid=L+R>>1;
    if(l<=mid)insert(o->l,l,r,val,L,mid);
    if(r>mid)insert(o->r,l,r,val,mid+1,R);
}
int query(Segment *o,int pos,int L,int R)
{
    if(L==R)return o->mn;
    o->pushdown();
    int mid=L+R>>1;
    if(pos<=mid)return query(o->l,pos,L,mid);
    return query(o->r,pos,mid+1,R);
}

int main()
{
    scanf("%s",s+1),N=strlen(s+1);
    build(T1,1,N),build(T2,1,N);
    for(int i=1;i<=N;i++)SAM.extend(s[i]-'a');
    for(SAMNode *i=SAMNodePool;i!=ptr;i++)num[i->length]++;
    for(int i=1;i<=N;i++)num[i]+=num[i-1];
    for(SAMNode *i=ptr-1;i>=SAMNodePool;i--)topo[num[i->length]--]=i;
    for(int i=ptr-SAMNodePool;i>1;i--)topo[i]->link->siz+=topo[i]->siz;
    for(SAMNode *i=SAMNodePool;i!=ptr;i++)if(i->siz==1)
    {
        int mxlen=i->length,mnlen=i->link->length+1,endpos=i->endpos;
        insert(T1,endpos-mxlen+1,endpos-mnlen+1,endpos+1,1,N);
        insert(T2,endpos-mnlen+1,endpos,mnlen,1,N);
    }
    for(int i=1;i<=N;i++)printf("%d\n",min(query(T1,i,1,N)-i,query(T2,i,1,N)));
    return 0;
}
