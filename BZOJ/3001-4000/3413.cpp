#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int N,M,tr[MX<<1],NN;
char s[MX];
long long ans[MX];

struct SuffixAutomaton
{
    struct Node
    {
        Node *son[10],*link;
        int length,dfn,end,minpos;
        vector<Node*> next;

        void* operator new (size_t);
        Node(int l=0):length(l),link(NULL){memset(son,0,sizeof(son));}
    };
    vector<Node*> pos;

    SuffixAutomaton(){pos.push_back(new Node);}
    void extend(int val)
    {
        Node *last=pos.back();
        Node *cur=new Node(last->length+1),*p,*q;
        cur->minpos=last->minpos+1;
        for(p=last;p&&!p->son[val];p=p->link)p->son[val]=cur;
        if(!p)return cur->link=pos[0],pos.push_back(cur);
        q=p->son[val];
        if(p->length+1==q->length)return cur->link=q,pos.push_back(cur);
        Node *clone=new Node(p->length+1);
        clone->minpos=q->minpos;
        clone->link=q->link;
        memcpy(clone->son,q->son,sizeof(q->son));
        q->link=cur->link=clone;
        while(p)
        {
            if(p->son[val]==q)p->son[val]=clone;
            p=p->link;
        }
        return pos.push_back(cur);
    }
    void dfs(Node *o)
    {
        static int cnt=0;
        o->dfn=++cnt;
        for(vector<Node*>::iterator it=o->next.begin();it!=o->next.end();++it)
            dfs(*it),o->minpos=min(o->minpos,(*it)->minpos);
        o->end=cnt;
    }
}SAM;
typedef pair<SuffixAutomaton::Node*,int> ques_t;
SuffixAutomaton::Node Pool[MX<<1],*ptr=Pool;
vector<ques_t> Ques[MX];
void* SuffixAutomaton::Node::operator new (size_t){return ++NN,ptr++;}

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
void insert(int x){for(;x<=NN;x+=x&-x)tr[x]++;}
int ask(int x){int ans=0;for(;x;x^=x&-x)ans+=tr[x];return ans;}

int main()
{
    N=read(),scanf("%s",s+1);
    for(int i=1;i<=N;i++)SAM.extend(s[i]-'0');
    for(SuffixAutomaton::Node *i=Pool+1;i<ptr;i++)i->link->next.push_back(i);
    SAM.dfs(SAM.pos[0]);
    M=read();
    for(int i=1,len,j;i<=M;i++)
    {
        scanf("%s",s+1),len=strlen(s+1);
        SuffixAutomaton::Node *p=SAM.pos[0];
        for(j=1;j<=len;j++)
            if(p->son[s[j]-'0'])p=p->son[s[j]-'0'];
            else break;
        if(j<=len)
        {
            ans[i]=N,p=SAM.pos[0];
            for(j=1;j<=len;j++)
                if(p->son[s[j]-'0'])
                    Ques[N].push_back(make_pair(p=p->son[s[j]-'0'],i));
                else break;
        }
        else
        {
            int tmp=p->minpos;
            ans[i]=tmp-len,p=SAM.pos[0];
            for(j=1;j<=len;j++)
                Ques[tmp-len+j].push_back(make_pair(p=p->son[s[j]-'0'],i));
        }
    }
    for(int i=1;i<=N;i++)
    {
        insert(SAM.pos[i]->dfn);
        for(vector<ques_t>::iterator it=Ques[i].begin();it!=Ques[i].end();++it)
            ans[it->second]+=ask(it->first->end)-ask(it->first->dfn-1);
    }
    for(int i=1;i<=M;i++)printf("%lld\n",ans[i]);
    return 0;
}
