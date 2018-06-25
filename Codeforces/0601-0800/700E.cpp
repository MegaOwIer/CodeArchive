#include<bits/stdc++.h>
using namespace std;
const int MX=200005;

int N,dp[MX<<1];
char s[MX];

struct SegTreeNode
{
    SegTreeNode *l,*r;
    SegTreeNode():l(NULL),r(NULL){}
}*TR[MX<<1];

struct SuffixAutomaton
{
    struct Node
    {
        Node *son[26],*link;
        int len,pos,id;
    }*root,*last,*topo[MX<<1];
    vector<Node*> Pool;
    int siz;

    SuffixAutomaton(){last=root=newNode(0,0);}
    Node* newNode(int len,int pos)
    {
        Node *tmp=new Node;
        Pool.push_back(tmp);
        tmp->len=len;
        tmp->pos=pos;
        tmp->id=++siz;
        tmp->link=NULL;
        memset(tmp->son,0,sizeof(tmp->son));
        return tmp;
    }
    void extend(int val)
    {
        Node *p=last,*np=newNode(last->len+1,last->pos+1);
        while(p&&!p->son[val])p->son[val]=np,p=p->link;
        if(!p)np->link=root;
        else
        {
            Node *q=p->son[val];
            if(q->len==p->len+1)np->link=q;
            else
            {
                Node *nq=newNode(p->len+1,np->pos);
                memcpy(nq->son,q->son,sizeof(q->son));
                nq->link=q->link;
                np->link=q->link=nq;
                while(p&&p->son[val]==q)p->son[val]=nq,p=p->link;
            }
        }
        last=np;
    }
    void build()
    {
        static int num[MX];
        for(auto i:Pool)num[i->len]++;
        for(int i=1;i<=N;i++)num[i]+=num[i-1];
        for_each(
            Pool.rbegin(),
            Pool.rend(),
            [this](Node *a){topo[num[a->len]--]=a;}
        );
        assert(topo[1]==root);
    }
}SAM;
using SAMNode=SuffixAutomaton::Node;
SAMNode *pos[MX<<1];

void insert(SegTreeNode* &o,int pos,int L,int R)
{
    o=new SegTreeNode;
    if(L==R)return;
    int mid=L+R>>1;
    if(pos<=mid)insert(o->l,pos,L,mid);
    else insert(o->r,pos,mid+1,R);
}
SegTreeNode* merge(SegTreeNode *o,SegTreeNode *p)
{
    if(!o||!p)return o?o:p;
    SegTreeNode *tmp=new SegTreeNode;
    tmp->l=merge(o->l,p->l);
    tmp->r=merge(o->r,p->r);
    return tmp;
}
bool query(SegTreeNode *o,int l,int r,int L,int R)
{
    if(!o)return false;
    if(l<=L&&R<=r)return true;
    int mid=L+R>>1;
    return (l<=mid&&query(o->l,l,r,L,mid))||(r>mid&&query(o->r,l,r,mid+1,R));
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>(s+1);
    for(int i=1;i<=N;i++)SAM.extend(s[i]-'a');
    SAM.build();
    for(auto i:SAM.Pool)if(i->pos)insert(TR[i->id],i->pos,1,N);
    for(int i=SAM.siz;i>=2;i--)
    {
        auto o=SAM.topo[i];
        TR[o->link->id]=merge(TR[o->link->id],TR[o->id]);
    }
    for(int i=2;i<=SAM.siz;i++)
    {
        auto o=SAM.topo[i];
        if(o->link->id==1)dp[o->id]=1,pos[o->id]=o;
        else if(query(TR[pos[o->link->id]->id],o->pos-o->len+pos[o->link->id]->len,o->pos-1,1,N))
            dp[o->id]=dp[o->link->id]+1,pos[o->id]=o;
        else dp[o->id]=dp[o->link->id],pos[o->id]=pos[o->link->id];
    }
    cout<<*max_element(dp+1,dp+SAM.siz+1)<<endl;
    return 0;
}
