#include<bits/stdc++.h>
using namespace std;
const int mod=10000;

int ans1,ans2,N=1;

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline int Pow(int a,int b)
{
    int ans=1;
    for(;b;b>>=1,a=a*a%mod)
        if(b&1)ans=ans*a%mod;
    return ans;
}

int main()
{
    for(int K=read(),p,m,tmp;K--;)
    {
        p=read(),m=read();
        N=N*Pow(p,m)%mod;
        if(p==2)continue;
        tmp=(ans1+ans2*(p-1))%mod;
        ans2=(ans2+(ans1+1)*(p-1))%mod;
        ans1=tmp;
    }
    printf("%d\n%d\n%d\n",ans1,ans2,(N-ans1-ans2+19999)%mod);
    return 0;
}
