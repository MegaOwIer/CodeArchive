#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=300005;

int N,M,ans[MX];
LL res;

struct seg
{
    int l,r,len;
    void init(int _l,int _r){l=_l,r=_r,len=_r-_l+1;}
    bool operator < (const seg& a)const{return len<a.len;}
}P[MX];

struct FastIn
{
    static const int MXL=20000000;
    char bf[MXL],*p1,*p2;
    FILE *I;
    FastIn(FILE *I):p1(bf),p2(bf),I(I){}
    char getchar(){return p1==p2&&(p2=(p1=bf)+fread(p1,1,MXL,I),p1==p2)?EOF:*p1++;}
    int operator () ()
    {
        int x=0,c=getchar();
        while(!isdigit(c))c=getchar();
        while(isdigit(c))x=x*10+c-'0',c=getchar();
        return x;
    }
}IN(stdin);

namespace Subtask1_3_5
{
    int tr[MX];

    inline void add(int u,int v){for(;u<=N;u+=u&-u)tr[u]+=v;}
    inline int ask(int u){int ans=0;for(;u;u^=u&-u)ans+=tr[u];return ans;}
    void main()
    {
        sort(P+1,P+M+1);
        for(int i=1,j=1;i<=N;i++)
        {
            while(j<=M&&P[j].len<i)add(P[j].l,1),add(P[j].r+1,-1),j++;
            int &tmp=ans[i];
            tmp=M-j+1;
            for(int k=i;k<=N;k+=i)tmp+=ask(k);
        }
    }
}

namespace Subtask2_4
{
    void main()
    {
        for(int i=1;i<=M;i++)
        {
            int l=P[i].l-1,r=P[i].r;
            for(int j=1,k,tmp;j<=r;j=k+1)
            {
                tmp=r/j,k=r/tmp;
                if(max(j,l/tmp+1)<=k)ans[max(j,l/tmp+1)]++,ans[k+1]--;
            }
        }
        for(int i=1;i<=N;i++)ans[i]+=ans[i-1];
    }
}

int main()
{
    M=IN(),N=IN();
    for(int i=1,l,r;i<=M;i++)l=IN(),r=IN(),P[i].init(l,r);
    if(N<=100000)Subtask1_3_5::main();
    else Subtask2_4::main();
    for(int i=1;i<=N;i++)printf("%d\n",ans[i]);
    return 0;
}
