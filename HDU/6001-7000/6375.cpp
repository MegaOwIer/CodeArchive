#include<bits/stdc++.h>
using namespace std;

const int MXPL=400005,MXSZ=150005;

int N,Q;

struct Deque
{
    struct Node
    {
        Node *link[2];
        int val;
        void* operator new (size_t);
        Node(){}
        Node(int val):val(val){link[0]=link[1]=nullptr;}
    }*head,*tail;
    void clear(){head=tail=nullptr;}
    void pop_front()
    {
        if(head==nullptr)return (void)puts("-1");
        printf("%d\n",head->val);
        if(head==tail)return clear();
        Node *tmp=head;
        head=tmp->link[tmp->link[0]==nullptr];
        head->link[tmp==head->link[1]]=nullptr;
    }
    void pop_back()
    {
        if(tail==nullptr)return (void)puts("-1");
        printf("%d\n",tail->val);
        if(head==tail)return clear();
        Node *tmp=tail;
        tail=tmp->link[tmp->link[0]==nullptr];
        tail->link[tmp==tail->link[1]]=nullptr;
    }
    void push_front(int val)
    {
        Node *tmp=new Node(val);
        if(head==nullptr)
        {
            head=tail=tmp;
            return;
        }
        tmp->link[0]=head;
        head->link[nullptr==head->link[1]]=tmp;
        head=tmp;
    }
    void push_back(int val)
    {
        Node *tmp=new Node(val);
        if(tail==nullptr)
        {
            head=tail=tmp;
            return;
        }
        tmp->link[0]=tail;
        tail->link[nullptr==tail->link[1]]=tmp;
        tail=tmp;
    }
    void reverse(){swap(head,tail);}
    void merge(Deque &Q)
    {
        if(head==nullptr)
        {
            head=Q.head,tail=Q.tail;
            Q.clear();
            return;
        }
        if(Q.head==nullptr)return;
        tail->link[tail->link[1]==nullptr]=Q.head;
        Q.head->link[Q.head->link[1]==nullptr]=tail;
        tail=Q.tail;
        Q.clear();
    }
}Qu[MXSZ];
Deque::Node Pool[MXPL],*ptr;
inline void* Deque::Node::operator new (size_t){return ptr++;}

inline int read()
{
    int x=0,c=getchar();
    if(c==EOF)exit(0);
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1002.in","r",stdin);
#endif
    while(true)
    {
        N=read(),Q=read();
        for(int i=1;i<=N;i++)Qu[i].clear();
        ptr=Pool;
        while(Q--)
        {
            int op=read(),u=read(),v=read();
            if(op==1)
            {
                if(v==0)Qu[u].push_front(read());
                else Qu[u].push_back(read());
            }
            else if(op==2)
            {
                if(v==0)Qu[u].pop_front();
                else Qu[u].pop_back();
            }
            else
            {
                if(read()==1)Qu[v].reverse();
                Qu[u].merge(Qu[v]);
            }
        }
    }
    return 0;
}
