#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=1000000007,MX=200000;

int H,W,A,B,fac[MX+5],ifac[MX+5],ans;

inline int C(int n,int m){return (LL)fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
inline int Pow(int a,int b)
{
    int ans=1;
    for(;b;b>>=1,a=(LL)a*a%mod)
        if(b&1)ans=(LL)ans*a%mod;
    return ans;
}

int main()
{
    cin>>H>>W>>A>>B;
    fac[0]=1;
    for(int i=1;i<=MX;i++)fac[i]=(LL)fac[i-1]*i%mod;
    ifac[MX]=Pow(fac[MX],mod-2);
    for(int i=MX;i;i--)ifac[i-1]=(LL)ifac[i]*i%mod;
    if(H==A+1)
    {
        cout<<C(H-2+W-B,H-1)<<endl;
        return 0;
    }
    for(int i=1;i<=B;i++)
        ans=(ans+(LL)C(H-A+i-3,i-1)*C(A+W-B-1,A))%mod;
    for(int i=B+1;i<=W;i++)
        ans=(ans+(LL)C(H-A+i-3,i-1)*C(A+W-i,A))%mod;
    cout<<ans<<endl;
    return 0;
}