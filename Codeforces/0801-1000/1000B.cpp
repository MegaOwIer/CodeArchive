#include<bits/stdc++.h>
using namespace std;

using LL=long long;
using pii=pair<int,int>;
#define endl "\n"
const int MX=100005;

int N,a[MX],M,tmp[MX];
LL ans,curans;

void check(int pos)
{
    int id=upper_bound(a,a+N+2,pos)-a;
    if(id%2==0)ans=max(ans,curans-tmp[id]*2+M-pos);
    else
    {
        int blc=tmp[id]+a[id]-pos;
        ans=max(ans,curans-blc*2+M-pos);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++)cin>>a[i];
    a[N+1]=M;
    for(int i=0;i<=N;i+=2)tmp[i]=a[i+1]-a[i];
    for(int i=N;i>=0;i--)tmp[i]+=tmp[i+1];
    curans=ans=tmp[0];
    if(a[1]!=1)check(1);
    if(a[N]!=M-1)check(M-1);
    for(int i=1;i<=N;i++)
    {
        if(a[i]-1!=a[i-1])check(a[i]-1);
        if(a[i]+1!=a[i+1])check(a[i]+1);
    }
    cout<<ans<<endl;
    return 0;
}
