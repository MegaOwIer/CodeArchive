#include<bits/stdc++.h>
using namespace std;
const int MX=1000005;

int N,a[MX],now;
long long ans;

struct nulltag{};
struct Heap
{
    struct Node
    {
        int val,siz,dis;
        Node *L,*R;
        Node(){}
        Node(nulltag):siz(0),dis(-1),L(this),R(this){}
        Node(int);
        void* operator new(size_t);
        void operator delete(void*);
        void maintain(){siz=1+L->siz+R->siz;}
    }*root;
    int L,R;
    Heap(){}
    Heap(int i,int val):root(new Node(val)),L(i),R(i){}
    int top(){return root->val;}
    int size(){return root->siz;}
    int length(){return R-L+1;}
    void merge(const Heap& a){R=a.R,root=merge(root,a.root);}
    void pop()
    {
        Node *tmp=merge(root->L,root->R);
        delete root;
        root=tmp;
    }
    Node* merge(Node*,Node*);
}H[MX];
Heap::Node Pool[MX],*ptr=Pool,*stk[MX],**top=stk,*null=new Heap::Node(nulltag());
inline Heap::Node::Node(int v):val(v),siz(1),dis(0),L(null),R(null){}
inline void* Heap::Node::operator new(size_t){return ::top==stk?ptr++:*::top--;}
inline void Heap::Node::operator delete(void* p){*++::top=(Node*)p;}
inline Heap::Node* Heap::merge(Node *x,Node *y)
{
    if(x==null)return y;
    if(y==null)return x;
    if(x->val<y->val)swap(x,y);
    x->R=merge(x->R,y);
    if(x->L->dis<x->R->dis)swap(x->L,x->R);
    x->dis=x->R->dis+1;
    x->maintain();
    return x;
}

inline void read(int& x)
{
    static char c;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
    read(N);
    for(int i=1;i<=N;i++)read(a[i]),a[i]-=i;
    for(int i=1;i<=N;i++)
    {
        ++now;
        H[now]=Heap(i,a[i]);
        while(now>1&&H[now].top()<H[now-1].top())
        {
            now--;
            H[now].merge(H[now+1]);
            while(H[now].size()*2>H[now].length()+1)
				H[now].pop();
        }
    }
    for(int i=1,t;i<=now;i++)
    {
		t=H[i].top();
        for(int j=H[i].L;j<=H[i].R;j++)ans+=abs(t-a[j]);
	}
    printf("%lld\n",ans);
    return 0;
}