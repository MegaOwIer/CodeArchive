#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define endl "\n"

int N,M,x,m0;
LL K;

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>M>>K;
    if(K<N)cout<<K+1<<' '<<1<<endl;
    else
    {
        K-=N;
        m0=M*2-2;
        x=N-(K/m0)*2;
        K%=m0;
        if(K<M-1)cout<<x<<' '<<K+2<<endl;
        else cout<<x-1<<' '<<M-K+M-1<<endl;
    }
    return 0;
}