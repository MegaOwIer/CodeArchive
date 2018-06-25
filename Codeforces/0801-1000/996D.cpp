#include<bits/stdc++.h>
using namespace std;

const int MX=203;
#define endl "\n"

int N,a[MX],ans;

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=1,ed=N*2;i<=ed;i++)cin>>a[i];
    for(int i=1,j,ed=N*2;i<ed;i+=2)
    {
        j=i+1;
        while(a[i]!=a[j])j++;
        ans+=j-i-1;
        for(int k=j-1;k>i;k--)a[k+1]=a[k];
    }
    cout<<ans<<endl;
    return 0;
}
