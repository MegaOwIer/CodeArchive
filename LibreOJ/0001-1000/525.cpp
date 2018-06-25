#include<bits/stdc++.h>
using namespace std;

int N,K;

inline int getPhi(int u)
{
    int ans=u;
    for(int i=2;i*i<=u;i++)if(u%i==0)
    {
        while(u%i==0)u/=i;
        ans=ans/i*(i-1);
    }
    if(u>1)ans=ans/u*(u-1);
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>K;
    if(K==1)return puts("-1"),0;
    N=K+getPhi(K);
    cout<<N<<endl;
    for(int i=0;i<K;i++)cout<<0<<' ';
    cout<<K-1<<' ';
    for(int i=K+1;i<N;i++)cout<<0<<' ';
    cout<<1<<endl;
    return 0;
}