#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int main()
{
    ios::sync_with_stdio(0);
    int n,ans=0;
    cin>>n;
    for(int i:{100,20,10,5,1})
        ans+=n/i,n%=i;
    cout<<ans<<endl;
}
