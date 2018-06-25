#include<bits/stdc++.h>
using namespace std;
typedef pair<vector<int>,vector<int> > Name;
const int MX=20005;

int N,M,ans[MX];
Name s[MX];

int read();

struct ACAutomaton
{
    struct Node
    {
        map<int,Node*> son;
        Node *fail;
        vector<int> flag;
        int sum,vis;

        Node():fail(NULL),sum(0),vis(0){son.clear(),flag.clear();}
        void* operator new (size_t);
    }*root,*pos[50005];

    ACAutomaton():root(new Node){}
    void insert(int id)
    {
        int len=read();
        Node *o=root;
        for(int i=1,x;i<=len;i++)
        {
            x=read();
            if(!o->son.count(x))o->son[x]=new Node;
            o=o->son[x];
        }
        o->flag.push_back(id);
        pos[id]=o;
    }
    void buildfail()
    {
        typedef map<int,Node*>::iterator Mit;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node *o=q.front();
            q.pop();
            for(Mit it=o->son.begin();it!=o->son.end();++it)
            {
                Node *tmp=o->fail;
                while(tmp&&!tmp->son.count(it->first))tmp=tmp->fail;
                if(tmp&&o!=root)it->second->fail=tmp->son[it->first];
                else it->second->fail=root;
                q.push(it->second);
            }
        }
    }
    void match(vector<int>& s,int id)
    {
        Node *o=root,*tmp;
        for(size_t i=0;i<s.size();i++)
        {
            while(o&&!o->son[s[i]])o=o->fail;
            if(!o)o=root;
            else o=o->son[s[i]];
            for(tmp=o;tmp!=root;tmp=tmp->fail)
                if(tmp->flag.size()&&tmp->vis!=id)
                    tmp->vis=id,ans[id]+=tmp->flag.size(),tmp->sum++;
        }
    }
}ACM;
inline void* ACAutomaton::Node::operator new (size_t)
{
    static ACAutomaton::Node Pool[100005],*ptr=Pool;
    return ptr++;
}

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

int main()
{
    N=read(),M=read();
    for(int i=1;i<=N;i++)
    {
        for(int k=read();k--;)s[i].first.push_back(read());
        for(int k=read();k--;)s[i].second.push_back(read());
    }
    for(int i=1;i<=M;i++)ACM.insert(i);
    ACM.buildfail();
    for(int i=1;i<=N;i++)ACM.match(s[i].first,i),ACM.match(s[i].second,i);
    for(int i=1;i<=M;i++)printf("%d\n",ACM.pos[i]->sum);
    for(int i=1;i<=N;i++)printf("%d%c",ans[i]," \n"[i==N]);
    return 0;
}
