#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod=998244353,ord=917504,TP=19190506;

int F[ord+10],G[1089920];

inline LL read()
{
    LL x=0;
    int c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
int getinv(int u){return u==1?1:LL(mod-mod/u)*getinv(mod%u)%mod;}
int Pow(int a,int b)
{
    int ans=1;
    for(;b;b>>=1,a=(LL)a*a%mod)
        if(b&1)ans=(LL)ans*a%mod;
    return ans;
}

int main()
{
    F[0]=1;
    for(int i=1,x=1,y=1,tmp=getinv(TP);i<ord;i++)
        F[i]=(LL)F[i-1]*y%mod,x=(LL)x*tmp%mod,y=(y+x)%mod;
    G[0]=1;
    for(int i=1;i<1089914;i++)G[i]=(LL)G[i-1]*i%mod;
    for(int T=read();T--;)
    {
        LL N=read(),M=read();
        int nL=N%ord,nH=N/ord,mL=M%ord,mH=M/ord;
        if(nL<mL)
        {
            puts("0");
            continue;
        }
        int ans=(LL)Pow(TP,LL(nL-mL)*mL%ord)*F[nL]%mod*getinv((LL)F[nL-mL]*F[mL]%mod)%mod;
        ans=(LL)ans*G[nH]%mod*getinv((LL)G[nH-mH]*G[mH]%mod)%mod;
        printf("%d\n",ans);
    }
    return 0;
}
