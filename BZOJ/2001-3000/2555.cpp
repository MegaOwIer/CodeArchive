#include<bits/stdc++.h>
using namespace std;
const int MX=3000005,MXL=600005;

int Q,N,seed,ans;
char op[10],s[MX];

struct LinkCutTree
{
    struct SplayNode
    {
        SplayNode *son[2],*fa;
        int siz,tag;

        SplayNode():siz(0),tag(0),fa(NULL){son[0]=son[1]=NULL;}
        bool isroot(){return !fa||(fa->son[0]!=this&&fa->son[1]!=this);}
        void update(int val){siz+=val,tag+=val;}
        int dir(){return fa->son[1]==this;}
        void pushdown()
        {
            if(!tag)return;
            for(int i=0;i<2;i++)if(son[i])
                son[i]->update(tag);
            tag=0;
        }
    }Node[MXL<<1];

    void rotate(SplayNode *o)
    {
        int d=o->dir();
        SplayNode *p=o->fa;
        o->fa=p->fa;
        if(!p->isroot())p->fa->son[p->dir()]=o;
        p->son[d]=o->son[d^1];
        if(o->son[d^1])o->son[d^1]->fa=p;
        o->son[d^1]=p,p->fa=o;
    }
    void splay(SplayNode *o)
    {
        static SplayNode *stk[MXL<<1],**top=stk;
        *++top=o;
        for(SplayNode *u=o;!u->isroot();u=u->fa)*++top=u->fa;
        while(top!=stk)(*top--)->pushdown();
        while(!o->isroot())
        {
            SplayNode *p=o->fa;
            if(!p->isroot())rotate(o->dir()==p->dir()?p:o);
            rotate(o);
        }
    }
    void access(SplayNode *o)
    {
        for(SplayNode *p=NULL;o;p=o,o=o->fa)
            splay(o),o->son[1]=p;
    }
    void link(int _u,int _v)
    {
        SplayNode *u=Node+_u,*v=Node+_v;
        access(v),splay(v),v->update(u->siz);
        u->fa=v;
    }
    void cut(int _u)
    {
        SplayNode *u=Node+_u;
        access(u),splay(u),u->son[0]->update(-u->siz);
        u->son[0]->fa=NULL,u->son[0]=NULL;
    }
}LCT;

struct SuffixAutomaton
{
    struct SAMNode
    {
        SAMNode *son[26],*link;
        int len,id;
    }*root,*last;
    int siz;

    SuffixAutomaton():siz(0){root=last=newNode(0);}
    SAMNode* newNode(int len)
    {
        SAMNode *tmp=new SAMNode;
        tmp->len=len;
        tmp->link=NULL;
        tmp->id=++siz;
        memset(tmp->son,0,sizeof(tmp->son));
        return tmp;
    }
    void extend(int val)
    {
        SAMNode *p=last,*np=newNode(last->len+1);
        LCT.Node[np->id].siz=1;
        while(p&&!p->son[val])p->son[val]=np,p=p->link;
        if(!p)np->link=root,LCT.link(np->id,1);
        else
        {
            SAMNode *q=p->son[val];
            if(q->len==p->len+1)np->link=q,LCT.link(np->id,q->id);
            else
            {
                SAMNode *clone=newNode(p->len+1);
                memcpy(clone->son,q->son,sizeof(q->son));
                clone->link=q->link,LCT.link(clone->id,q->link->id);
                q->link=np->link=clone;
                LCT.cut(q->id),clone,LCT.link(q->id,clone->id);
                LCT.link(np->id,clone->id);
                while(p&&p->son[val]==q)p->son[val]=clone,p=p->link;
            }
        }
        last=np;
    }
    int query(char *s,int N)
    {
        SAMNode *o=root;
        for(int i=1;o&&i<=N;i++)o=o->son[s[i]-'A'];
        if(!o)return 0;
        LCT.splay(&LCT.Node[o->id]);
        return LCT.Node[o->id].siz;
    }
}SAM;

void decode(char *s,int len,int seed)
{
    for(int i=0;i<len;i++)
        seed=(seed*131+i)%len,swap(s[i],s[seed]);
}

int main()
{
    scanf("%d%s",&Q,s+1);
    N=strlen(s+1);
    for(int i=1;i<=N;i++)SAM.extend(s[i]-'A');
    while(Q--)
    {
        scanf("%s%s",op+1,s+1);
        decode(s+1,N=strlen(s+1),seed);
        if(op[1]=='A')for(int i=1;i<=N;i++)SAM.extend(s[i]-'A');
        else seed^=(ans=SAM.query(s,N)),printf("%d\n",ans);
    }
    return 0;
}
