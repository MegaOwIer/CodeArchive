#include<bits/stdc++.h>
using namespace std;
const int MX=100005,MN=500005;

int T,N,Q,l[MX];
string pre,suf;
char str[MN+MX<<1],*s[MX],t[MX];

struct ACAutomaton
{
    struct Node
    {
        Node *son[27],*fail;
        int len,ans;
        Node(int l=0):fail(NULL),len(l),ans(0){memset(son,0,sizeof(son));}
        void* operator new(size_t);
    }*root;
    
    void init(){root=new Node;}
    
    Node* insert(char *s)
    {
        Node *o=root;
        for(char *i=s;*i;i++)
        {
            if(!o->son[*i-'a'])o->son[*i-'a']=new Node(i-s+1);
            o=o->son[*i-'a'];
        }
        return o;
    }
    void build()
    {
        queue<Node*> q;
        for(int i=0;i<27;i++)
            if(root->son[i])q.push(root->son[i]),root->son[i]->fail=root;
            else root->son[i]=root;
        while(!q.empty())
        {
            Node *o=q.front();
            q.pop();
            for(int i=0;i<27;i++)
                if(!o->son[i])o->son[i]=o->fail->son[i];
                else q.push(o->son[i]),o->son[i]->fail=o->fail->son[i];
        }
    }
    void match(char *s,int len)
    {
        Node *o=root;
        for(char *i=s;*i;i++)
        {
            o=o->son[*i-'a'];
            for(Node *p=o;p!=root;p=p->fail)
                if(p->len<=len)p->ans++;
        }
    }
}ACM;
ACAutomaton::Node POOL[MN+MX],*ptr,*pos[MX];
inline void* ACAutomaton::Node::operator new(size_t){return ptr++;}

int main()
{
    ios::sync_with_stdio(0);
    for(cin>>T;T--;)
    {
        ptr=POOL,ACM.init();
        cin>>N>>Q;
        for(int i=1,tmp=0;i<=N;i++)
        {
            s[i]=str+tmp;
            cin>>pre;
            strcpy(s[i],(pre+char('z'+1)+pre).c_str());
            l[i]=pre.length()+1;
            tmp+=l[i]<<1;
        }
        for(int i=1;i<=Q;i++)
        {
            cin>>pre>>suf;
            strcpy(t+1,(suf+char('z'+1)+pre).c_str());
            pos[i]=ACM.insert(t+1);
        }
        ACM.build();
        for(int i=1;i<=N;i++)ACM.match(s[i],l[i]);
        for(int i=1;i<=Q;i++)printf("%d\n",pos[i]->ans);
    }
    return 0;
}