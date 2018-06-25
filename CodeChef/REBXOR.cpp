#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=400005;

char Pool[200000000],*p=Pool;
inline void* operator new (size_t siz){return (p+=siz)-siz;}
inline void operator delete(void*){}

namespace FastIO
{
    char c;
    int bf[22],top;
    template<typename T>inline void read(T& x)
    {
        x=0,c=getchar();
        while(!isdigit(c))c=getchar();
        while(isdigit(c))x=x*10+c-'0',c=getchar();
    }
    template<typename T>inline void write(T x)
    {
        top=0;
        do bf[++top]=x%10,x/=10;while(x);
        while(top)putchar(48+bf[top--]);
        putchar('\n');
    }
}
using FastIO::read;
using FastIO::write;

struct Trie
{
    struct Node
    {
        Node *son[2];
        Node(){son[0]=son[1]=NULL;}
    }*root;
    Trie(){root=new Node;}
    void insert(int x)
    {
        Node* o=root;
        for(int i=1<<29,j;i;i>>=1)
        {
            j=(bool)(x&i);
            if(!o->son[j])o->son[j]=new Node;
            o=o->son[j];
        }
    }
    int query(int x)
    {
        int ans=0;
        Node* o=root;
        for(int i=1<<29,j;i&&o;i>>=1)
        {
            j=(bool)(x&i);
            if(o->son[j^1])ans+=i,o=o->son[j^1];
            else o=o->son[j];
        }
        return ans;
    }
}A,B;

int n,a[maxn],lmx[maxn],rmx[maxn],ans;

int main()
{
    read(n);
    for(int i=1;i<=n;i++)read(a[i]);
    A.insert(0),B.insert(0);
    for(int i=1,now=0;i<=n;i++)
    {
        now^=a[i],A.insert(now);
        lmx[i]=max(lmx[i-1],A.query(now));
    }
    for(int i=n,now=0;i;i--)
    {
        now^=a[i],B.insert(now);
        rmx[i]=max(rmx[i+1],B.query(now));
    }
    for(int i=1;i<n;i++)ans=max(ans,lmx[i]+rmx[i+1]);
    write(ans);
    return 0;
}