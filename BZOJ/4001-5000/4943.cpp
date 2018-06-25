#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=200005;
#define inline __attribute__((always_inline))
 
char Pool[500000000],*ptr=Pool;
inline void* operator new(size_t siz){return (ptr+=siz)-siz;}
inline void operator delete(void*){}
 
namespace FastIO
{
    const int MXL=1000000;
    struct FastIn
    {
        char BF[MXL],*p1,*p2,c;
        FastIn():p1(BF),p2(BF){}
        inline char getchar(){return p1==p2?p2=(p1=BF)+fread(BF,1,MXL,stdin),p1==p2?EOF:*p1++:*p1++;}
        template<typename T>inline void operator()(T& x)
        {
            x=0,c=getchar();
            while(!isdigit(c))c=getchar();
            while(isdigit(c))x=x*10+c-'0',c=getchar();
        }
        inline void getstr(char *s)
        {
            while(!isdigit(*s=getchar()));
            while((*++s=getchar())!=' ');
            *s=0;
        }
    };
    struct FastOut
    {
        char BF[MXL],*p1,*const p2;
        int bf[22],tp;
        FastOut():p1(BF),p2(BF+MXL){}
        ~FastOut(){flush();}
        inline void putchar(char c){if(p1==p2)flush();*p1++=c;}
        inline void flush(){fwrite(BF,1,p1-BF,stdout),p1=BF;}
        template<typename T>inline void operator()(T x)
        {
            bf[tp=1]='\n'-48;
            do bf[++tp]=x%10,x/=10;while(x);
            while(tp)putchar(48+bf[tp--]);
        }
    };
}
 
struct nulltag{};
struct Trie
{
    struct Node
    {
        Node *son[6],*fail;
        int cnt;
        Node();
        Node(nulltag):cnt(0),fail(this){for(int i=0;i<6;i++)son[i]=this;}
    }*root,*rtt[55];
     
    Trie():root(new Node){for(int i=0;i<6;i++)root->son[i]=new Node,root->son[i]->fail=root;}
    inline void insert(int u){root->son[u]->cnt++;}
    void modify(int*,int,int,int);
    int query(int,char*);
};
 
Trie::Node *null=new Trie::Node(nulltag());
inline Trie::Node::Node():cnt(0),fail(null){for(int i=0;i<6;i++)son[i]=null;}
inline void Trie::modify(int *s,int mid,int tot,int sig)
{
    static int i,j,l;
    static Node *rt,*_rt;
    rt=root;
    for(i=1;i<=mid;i++)rt=rt->son[s[i]];
    memset(rtt,0,sizeof(rtt));
    for(i=1;i<mid;i++,rt=rt->fail)
    {
        _rt=rt;
        for(l=mid-i+2,j=mid+1;l<=50&&j<=tot;j++,l++)
        {
            if(_rt->son[s[j]]==null)_rt->son[s[j]]=new Node;
            _rt=_rt->son[s[j]],_rt->cnt+=sig;
            if(~sig)
            {
                if(rtt[l+1])rtt[l+1]->fail=_rt;
                rtt[l]=_rt;
            }
        }
    }
    _rt=root;
    for(l=2,i=mid+1;l<=50&&i<=tot;i++,l++)
    {
        _rt=_rt->son[s[i]];
        if(rt->son[s[i]]==null)rt->son[s[i]]=new Node;
        rt=rt->son[s[i]],rt->cnt+=sig;
        if(~sig)
        {
            if(rtt[l+1])rtt[l+1]->fail=rt;
            rt->fail=_rt;
        }
    }
}
inline int Trie::query(int l,char *s)
{
    static Node *rt;
    static int ret,i;
    ret=1,rt=root;
    for(i=1;i<l;i++)rt=rt->son[s[i]-49];
    for(i=l;s[i]&&ret;rt=rt->fail,i++)
    {
        rt=rt->son[s[i]-49];
        __asm__ __volatile__("\tmull %%ebx\n\tdivl %%ecx\n":"=d"(ret):"a"(ret),"b"(rt->cnt),"c"(998244353));
    }
    return ret;
}
 
Trie T;
int N,M,a[MX],nxt[MX],pre[MX],tmp[55],s[105];
char ch[10000005];
FastIO::FastIn IN;
FastIO::FastOut OUT;

int main()
{
    IN(N),IN(M);
    for(int i=1;i<=N;i++)IN(a[i]),T.insert(--a[i]);
    for(register int op,x,y,i,j;M--;)
    {
        IN(op);
        if(op==1)
        {
            IN(x),IN(y);
            pre[y]=x,nxt[x]=y;
            for(i=1;x&&i<50;x=pre[x],i++)tmp[i]=a[x];
            reverse(tmp+1,tmp+i),memcpy(s+1,tmp+1,sizeof(int)*(i-1));
            for(j=1;y&&j<50;y=nxt[y],j++)tmp[j]=a[y];
            memcpy(s+i,tmp+1,sizeof(int)*(j-1));
            T.modify(s,i-1,i+j-2,1);
        }
        else if(op==2)
        {
            IN(x),y=nxt[x];
            pre[y]=nxt[x]=0;
            for(i=1;x&&i<50;x=pre[x],i++)tmp[i]=a[x];
            reverse(tmp+1,tmp+i),memcpy(s+1,tmp+1,sizeof(int)*(i-1));
            for(j=1;y&&j<50;y=nxt[y],j++)tmp[j]=a[y];
            memcpy(s+i,tmp+1,sizeof(int)*(j-1));
            T.modify(s,i-1,i+j-2,-1);
        }
        else IN.getstr(ch+1),IN(x),OUT(T.query(x,ch));
    }
    return 0;
}
