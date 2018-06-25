#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=100005;

int N,K;
string s[MX];

struct SuffixAutomaton
{
    struct Node
    {
        Node *son[26],*link;
        int length,vis,siz;
        LL cnt;
        vector<Node*> nxt;
    }*root,*last,Pool[MX<<1],*ptr;
    int siz;
    vector<Node*> pos[MX];

    SuffixAutomaton(){ptr=Pool,root=newNode();}
    Node* newNode(int length=0)
    {
        ++siz;
        ptr->length=length;
        ptr->vis=0,ptr->siz=0,ptr->cnt=0;
        ptr->link=NULL;
        memset(ptr->son,NULL,sizeof(ptr->son));
        return ptr++;
    }
    Node* extend(int val,int id)
    {
        Node *cur=newNode(last->length+1),*p=last;
        last=cur;
        for(;p&&!p->son[val];p=p->link)p->son[val]=cur;
        if(!p)cur->link=root;
        else
        {
            Node *q=p->son[val];
            if(p->length+1==q->length)cur->link=q;
            else
            {
                Node *clone=newNode(p->length+1);
                clone->link=q->link;
                clone->vis=q->vis;
                clone->siz=q->siz;
                memcpy(clone->son,q->son,sizeof(q->son));
                while(p&&p->son[val]==q)p->son[val]=clone,p=p->link;
                q->link=cur->link=clone;
            }
        }
        pos[id].push_back(cur);
        while(cur&&cur->vis!=id)
            cur->siz++,cur->vis=id,cur=cur->link;
    }
    void insert(string& a,int id)
    {
        last=root;
        for(int i=0;i<a.length();i++)
            extend(a[i]-'a',id);
    }
    void dfs(Node *o)
    {
        if(o->link)o->cnt+=o->link->cnt;
        for(vector<Node*>::iterator it=o->nxt.begin();it!=o->nxt.end();++it)
            dfs(*it);
    }
    void getans()
    {
        for(Node *i=Pool+1;i<ptr;i++)
        {
            if(i->siz>=K)
                i->cnt=i->length-i->link->length;
            i->link->nxt.push_back(i);
        }
        dfs(root);
        for(int i=1;i<=N;i++)
        {
            LL ans=0;
            for(int j=0;j<pos[i].size();j++)
                ans+=pos[i][j]->cnt;
            printf("%lld ",ans);
        }
    }
}SAM;

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>K;
    for(int i=1;i<=N;i++)
    {
        cin>>s[i];
        SAM.insert(s[i],i);
    }
    SAM.getans();
    return 0;
}
