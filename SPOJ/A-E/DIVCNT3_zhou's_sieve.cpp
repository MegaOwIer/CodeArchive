#include<bits/stdc++.h>
using namespace std;

using LL=long long;
const int MX=316230;

int pr[27299],cnt,f[MX],d[MX],pi[MX];
int SqrtN;
LL N;
int L[MX],L0[MX];
LL F[MX],F0[MX],G[MX],G0[MX];

inline LL read()
{
    LL x=0;  int c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

void GetF(int P)
{
    for(int i=1;i<=SqrtN;i++)F[i]=N/i;
    for(int i=1;i<=SqrtN;i++)F0[i]=i;
    for(int i=1;i<=P;i++)
    {
        for(int j=1;j<=SqrtN&&i<=L[j];j++)
        {
            LL tmp=N/j/pr[i];
            if(tmp>SqrtN)F[j]-=F[N/tmp]-max(0,i-L[N/tmp]-1);
            else F[j]-=F0[tmp]-max(0,min(i-1,pi[tmp])-L0[tmp]);
        }
        for(int j=SqrtN,y;j&&i<=L0[j];j--)
            y=j/pr[i],F0[j]-=F0[y]-max(0,min(i-1,pi[y])-L0[y]);
    }
    for(int i=1;i<=SqrtN;i++)
        F0[i]-=pi[i]-L0[i]+1,F[i]-=max(0,P-L[i])+1;
    for(int i=1;i<=SqrtN;i++)F[i]<<=2;
}
void GetG(int P)
{
    for(int i=1;i<=SqrtN;i++)G[i]=G0[i]=1;
    for(int i=P;i;i--)
    {
        for(int j=1;j<=SqrtN&&i<=L[j];j++)
        {
            LL tmp=N/j/pr[i];
            for(int c=1;tmp;tmp/=pr[i],++c)
                if(tmp>SqrtN)G[j]+=(3*c+1)*(G[N/tmp]+4*max(0,P-max(i,L[N/tmp])));
                else G[j]+=(3*c+1)*(G0[tmp]+4*max(0,pi[tmp]-max(i,L0[tmp])));
        }
        for(int j=SqrtN;j&&i<=L0[j];j--)
        {
            int tmp=j/pr[i];
            for(int c=1;tmp;tmp/=pr[i],++c)
                G0[j]+=(3*c+1)*(G0[tmp]+4*max(0,pi[tmp]-max(i,L0[tmp])));
        }
    }
    G[1]+=4*(P-L[1]);
}
LL solve()
{
    auto sqr=[](LL x){return x*x;};
    SqrtN=(int)sqrt(N);
    L0[0]=0;
    for(int i=1;i<=SqrtN;i++)
        for(L0[i]=L0[i-1];sqr(pr[L0[i]+1])<=i;L0[i]++);
    L[SqrtN+1]=0;
    for(int i=SqrtN;i;i--)
        for(L[i]=L[i+1];sqr(pr[L[i]+1])<=N/i;L[i]++);
    LL ans=0;
    GetF(pi[SqrtN]),GetG(pi[SqrtN]);
    for(int i=1;i<=SqrtN;i++)ans+=f[i]*F[i];
    return ans+G[1];
}

int main()
{
    f[1]=d[1]=1;
    for(int i=2,tmp;i<MX;i++)
    {
        if(!d[i])pr[++cnt]=i,f[i]=4,pi[i]=1,d[i]=i;
        for(int j=1;j<=cnt&&(tmp=i*pr[j])<MX;j++)
            if(i%pr[j]==0){d[tmp]=d[i]*pr[j],f[tmp]=f[i/d[i]]*(f[d[i]]+3);break;}
            else d[tmp]=pr[j],f[tmp]=f[i]*4;
    }
    for(int i=2;i<MX;i++)pi[i]+=pi[i-1];
    for(int T=(int)read();T--;)
        N=read(),printf("%lld\n",solve());
    return 0;
}
