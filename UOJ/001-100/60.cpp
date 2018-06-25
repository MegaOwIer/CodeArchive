#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long LL;
#define endl "\n"

int N;

inline int Pow(int a,int b)
{
    int ans=1;
    for(;b;b>>=1,a=(LL)a*a%mod)
        if(b&1)ans=(LL)ans*a%mod;
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    cout<<(Pow(3,N)+Pow(3,N-1))%mod<<endl;
    while(N--)cout<<"A 0 0 0 0"<<endl;
    return 0;
}