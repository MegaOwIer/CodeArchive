#include<bits/stdc++.h>
using namespace std;

using LL=long long;
const int P=998244353;
constexpr int Inv(int u){return u==1?1:LL(P-P/u)*Inv(P%u)%P;}
const int inv3=Inv(3);
const int MX=1000005;

int N,ans1,ans2,fac[MX],inv[MX];

inline int C(int n,int m){return (LL)fac[n]*inv[m]%P*inv[n-m]%P;}
inline int Pow(int a,LL b)
{
    int ans=1;
    b%=P-1,b+=P-1;
    for(;b;b>>=1,a=(LL)a*a%P)
        (b&1)&&(ans=(LL)ans*a%P);
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    fac[0]=1;
    for(int i=1;i<=N;i++)fac[i]=(LL)fac[i-1]*i%P;
    inv[N]=Inv(fac[N]);
    for(int i=N;i;i--)inv[i-1]=(LL)inv[i]*i%P;
    for(int i=1;i<=N;i++)
    {
        int tmp=(LL)C(N,i)*Pow(3,LL(N-i)*N+i)%P;
        int res=Pow(1-Pow(3,i-N)+P,N)-1;
        if(i&1)ans1=(ans1+tmp)%P;
        else ans1=(ans1-tmp+P)%P;
    }
    for(int i=1;i<=N;i++)
    {
        int tmp=LL(Pow(1-Pow(3,i-N)+P,N)-1)*C(N,i)%P*Pow(3,LL(N-i)*N)%P;
        if(i&1)ans2=(ans2-tmp+P)%P;
        else ans2=(ans2+tmp)%P;
    }
    cout<<(ans1*2%P-ans2*3ll%P+P)%P;
    return 0;
}
