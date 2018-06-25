#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int N,ans=-1U>>1;

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=1,x;i<=N;i++)
    {
        cin>>x;
        int tmp=x/N*N+i;
        if(tmp<=x)tmp+=N;
        ans=min(ans,tmp);
    }
    cout<<(ans-1)%N+1<<endl;
    return 0;
}
