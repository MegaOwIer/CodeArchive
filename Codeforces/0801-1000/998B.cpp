#include<bits/stdc++.h>
using namespace std;

const int MX=105;

int N,a[MX],B,ans;
multiset<int> S;

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>B;
    for(int i=1,cnt=0;i<=N;i++)
    {
        cin>>a[i];
        if(!cnt&&i>1)S.insert(abs(a[i]-a[i-1]));
        if(a[i]&1)cnt++;
        else cnt--;
    }
    while(!S.empty()&&*S.begin()<=B)
        ans++,B-=*S.begin(),S.erase(S.begin());
    cout<<ans<<endl;
    return 0;
}
