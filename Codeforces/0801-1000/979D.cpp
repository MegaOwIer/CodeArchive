#include<bits/stdc++.h>
using namespace std;
const int MX=100005;
#define endl "\n"

int Q,type,x,s,k;

struct Trie
{
    struct Node
    {
        Node *son[2];
        int mn;
        Node():mn(2147483647){son[0]=son[1]=nullptr;}
    }*root;

    Trie():root(new Node){}
    void insert(int val)
    {
        Node *o=root;
        for(int i=16,d;i>=0;i--)
        {
            d=(val>>i)&1;
            if(!o->son[d])o->son[d]=new Node;
            o=o->son[d],o->mn=min(o->mn,val);
        }
    }
    int query(int mx,int val)
    {
        int ans=0;
        Node *o=root;
        for(int i=16,d;i>=0;i--)
        {
            d=(~val>>i)&1;
            if(d==1)
            {
                if(o->son[1]&&o->son[1]->mn<=mx)ans|=1<<i,o=o->son[1];
                else if(o->son[0]&&o->son[0]->mn<=mx)o=o->son[0];
                else return -1;
            }
            else
            {
                if(o->son[0]&&o->son[0]->mn<=mx)o=o->son[0];
                else if(o->son[1]&&o->son[1]->mn<=mx)ans|=1<<i,o=o->son[1];
                else return -1;
            }
        }
        return ans;
    }
}TR[MX];

int main()
{
    ios::sync_with_stdio(0);
    cin>>Q;
    while(Q--)
    {
        cin>>type>>x;
        if(type==1)
        {
            for(int i=1;i*i<=x;i++)if(x%i==0)
            {
                TR[i].insert(x);
                if(i*i!=x)TR[x/i].insert(x);
            }
        }
        else
        {
            cin>>k>>s;
            if(x%k)cout<<-1<<endl;
            else cout<<TR[k].query(s-x,x)<<endl;
        }
    }
    return 0;
}
