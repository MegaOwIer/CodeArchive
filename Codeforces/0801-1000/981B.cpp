#include<bits/stdc++.h>
using namespace std;
using LL=long long;

map<int,int> tmp;
int N;
LL ans;

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=1,a,x;i<=N;i++)
        cin>>a>>x,tmp[a]=x;
    cin>>N;
    for(int i=1,a,x;i<=N;i++)
        cin>>a>>x,tmp[a]=max(tmp[a],x);
    for(auto i:tmp)ans+=i.second;
    cout<<ans<<endl;
    return 0;
}

