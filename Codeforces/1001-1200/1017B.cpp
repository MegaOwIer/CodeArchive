#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
using LL=long long;
const int MX=100005;

int N,cnt[2];
LL ans;
char s[MX],t[MX];

int main()
{
    ios::sync_with_stdio(false);
    cin>>N>>(s+1)>>(t+1);
    for(int i=1;i<=N;i++)if(t[i]=='1')cnt[s[i]-'0']++;
    for(int i=1;i<=N;i++)if(t[i]=='0')ans+=cnt[s[i]^'1'];
    cnt[0]=cnt[1]=0;
    for(int i=1;i<=N;i++)if(t[i]=='0')cnt[s[i]-'0']++;
    ans+=(LL)cnt[0]*cnt[1];
    cout<<ans<<endl;
    return 0;
}
