#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int MX=100005,mod=1000000007;

int Fib[MX],T,N,M,ans;
LL S1,S2;

inline int read()
{
    static int x,c;
    c=getchar(),x=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

int main()
{
    Fib[1]=1;
    for(int i=2;i<=100000;i++)Fib[i]=(Fib[i-1]+Fib[i-2])%mod;
    T=read();
    while(T--)
    {
        M=read(),N=read();
        S1=S2=0;
        for(int i=1;i<=M;i++)S1+=read();
        for(int i=1;i<=M;i++)S2+=read();
        S1%=mod,S2%=mod;
        if(N==1)ans=S1*M%mod;
        else ans=(S1*Fib[N-2]+S2*Fib[N-1])%mod*M%mod;
        printf("%d\n",ans);
    }
    return 0;
}
