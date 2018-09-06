#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
const int MX=1005;

int N,a[MX];

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>N)
    {
        int ans=-1;
        for(int i=1;i<=N;i++)cin>>a[i];
        sort(a+1,a+N+1);
        for(int i=1;i<N;i++)for(int j=i+1;j<=N;j++)
        {
            int tmp=a[i]+a[j];
            int id=lower_bound(a+1,a+N+1,tmp)-a-1;
            if(id>j)ans=max(tmp+a[id],ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
