#include<bits/stdc++.h>
using namespace std;

using LL=long long;
#define endl '\n'

int N,ans[25];
set<int> S[25];

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    S[0].insert(0);
    for(int i=1;i<=21;i++)
    {
        for(int j:S[i-1])for(int k:{1,5,10,50})
            S[i].insert(j+k);
        ans[i]=S[i].size();
    }
    if(N<=20)cout<<ans[N]<<endl;
    else cout<<ans[20]+LL(ans[21]-ans[20])*(N-20)<<endl;
    return 0;
}
