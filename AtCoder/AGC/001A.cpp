#include<bits/stdc++.h>
using namespace std;

int N,a[205],ans;

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N*2;i++)cin>>a[i];
    sort(a+1,a+N*2+1);
    for(int i=1;i<=2*N;i+=2)ans+=a[i];
    cout<<ans<<endl;
    return 0;
}
