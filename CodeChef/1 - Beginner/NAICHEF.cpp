#include<bits/stdc++.h>
using namespace std;
const int MX=10005;
#define endl "\n"

int T,N,A,B,cnt[MX];

int main()
{
    ios::sync_with_stdio(0);
    setiosflags(ios::fixed);
    cout.precision(9);
    cin>>T;
    while(T--)
    {
        cin>>N>>A>>B;
        memset(cnt+1,0,sizeof(int)*N);
        for(int i=1,x;i<=N;i++)cin>>x,cnt[x]++;
        cout<<(double)cnt[A]*cnt[B]/N/N<<endl;
    }
    return 0;
}
