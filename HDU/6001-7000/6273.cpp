#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=100005,mod=998244353;

int T,N,d2[MX],d3[MX];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline LL Pow(int a,int b)
{
    int ans=1;
    for(;b;b>>=1,a=(LL)a*a%mod)
        if(b&1)ans=(LL)ans*a%mod;
    return ans;
}

int main()
{
    for(T=read();T--;)
    {
        int N=read(),M=read();
        memset(d2+1,0,sizeof(int)*N);
        memset(d3+1,0,sizeof(int)*N);
        while(M--)
        {
            int l=read(),r=read(),p=read();
            if(p==2)d2[l]++,d2[r+1]--;
            else d3[l]++,d3[r+1]--;
        }
        for(int i=2;i<=N;i++)d2[i]+=d2[i-1],d3[i]+=d3[i-1];
        printf("%lld\n",Pow(2,*min_element(d2+1,d2+N+1))*Pow(3,*min_element(d3+1,d3+N+1))%mod);
    }
    return 0;
}