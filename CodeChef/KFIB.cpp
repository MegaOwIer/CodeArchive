#include<bits/stdc++.h>
using namespace std;
const int MX=200005,mod=1e9+7;

int a[MX],N,K;

int main()
{
    cin>>N>>K;
    for(int i=1;i<=K;i++)a[i]=i;
    for(int i=K+1;i<=N;i++)
    {
        a[i]=(a[i-1]-a[i-K-1]+mod)%mod;
        a[i]=(a[i]+a[i-1])%mod;
    }
    cout<<(a[N]-a[N-1]+mod)%mod<<endl;
    return 0;
}