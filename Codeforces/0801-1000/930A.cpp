#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int N,dep[MX],ans;

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    dep[1]=1;
    for(int i=2,u;i<=N;i++)
    {
        cin>>u;
        dep[i]=dep[u]+1;
    }
    sort(dep+1,dep+N+1);
    for(int i=1,j=1;i<=N;i=j)
    {
        while(dep[i]==dep[j]&&j<=N)j++;
        ans+=(j-i)&1;
    }
    cout<<ans<<endl;
    return 0;
}
