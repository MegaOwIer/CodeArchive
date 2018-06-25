#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int MX=1000005;

namespace FastIO
{
    const int MXL=500000;
    struct FastIn
    {
        char bf[MXL],*p1,*p2;
        FILE *I;
        FastIn(FILE *I):p1(bf),p2(bf),I(I){}
        char getchar(){return p1==p2?(p2=(p1=bf)+fread(bf,1,MXL,I),p1==p2?EOF:*p1++):*p1++;}
        int operator () ()
        {
            int x,c;
            x=0,c=getchar();
            while(!isdigit(c))c=getchar();
            while(isdigit(c))x=x*10+c-'0',c=getchar();
            return x;
        }
    };
    struct FastOut
    {
        char bf[MXL],*p1,*const p2;
        FILE *O;
        FastOut(FILE *O):p1(bf),p2(bf+MXL),O(O){}
        ~FastOut(){flush();}
        void flush(){fwrite(bf,1,p1-bf,O),p1=bf;}
        void putchar(char c){if(p1==p2)flush();*p1++=c;}
        void operator () (int x)
        {
            static int dig[12],top;
            dig[top=1]='\n'-48;
            do dig[++top]=x%10,x/=10;while(x);
            while(top)putchar(dig[top--]+48);
        }
    };
}

int N,M,Q,fa[MX];
unsigned dis[MX],sum[MX];
FastIO::FastIn IN(stdin);
FastIO::FastOut OUT(stdout);

inline unsigned gcd(unsigned x,unsigned y)
{
    if(y)while((x%=y)&&(y%=x));
    return x+y;
}
int find(int u)
{
    if(u!=fa[u])
    {
        int tmp=fa[u];
        fa[u]=find(fa[u]);
        dis[u]=(dis[u]+dis[tmp])%M;
    }
    return fa[u];
}
void exgcd(int a,int b,int& x,int& y)
{
    if(!b)x=1,y=0;
    else exgcd(b,a%b,y,x),y-=a/b*x;
}
int calc(int a,int b,int c)
{
    int d=gcd(a,b),x,y;
    if(c%d)return -1;
    a/=d,b/=d,c/=d;
    exgcd(a,b,x,y);
    return ((LL)x*c%b+b)%b;
}

int main()
{
    N=IN(),M=IN(),Q=IN();
    for(int i=1;i<=N;i++)fa[i]=i,dis[i]=0,sum[i]=M;
    while(Q--)
    {
        int op=IN(),u=IN(),v=IN();
        int fu=find(u),fv=find(v);
        if(op==1)
        {
            int w=IN();
            if(fu==fv)sum[fu]=gcd(sum[fu],gcd(w<<1,dis[u]+dis[v]+w));
            else
            {
                fa[fu]=fv;
                dis[fu]=(dis[u]+dis[v]+w)%M;
                sum[fv]=gcd(sum[fv],gcd(sum[fu],w<<1));
            }
        }
        else
        {
            int x=IN(),b=IN(),c=IN();
            if(fu==fv)
            {
                int k=calc(b,sum[fu],dis[u]+dis[v]-x);
                if(~k&&k<c)OUT((c-k-1)/(sum[fu]/gcd(b,sum[fu]))+1);
                else OUT.putchar('0'),OUT.putchar('\n');
            }
            else OUT.putchar('0'),OUT.putchar('\n');
        }
    }
    return 0;
}