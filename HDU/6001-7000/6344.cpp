#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
const int MX=1005;

int T,N,M,K,a[MX];
char s[15];

bool check(int sta)
{
    map<int,int> S;
    for(int i=1;i<=N;i++)++S[sta&a[i]];
    int sum=0;
    for(auto i:S)
    {
        sum+=i.second*i.second;
        if(sum>K)return false;
    }
    return true;
}
int solve()
{
    cin>>N>>M>>K;
    K=N*N-K*2;
    for(int i=1;i<=N;i++)
    {
        cin>>(s+1);
        int &tmp=(a[i]=0);
        for(int j=1;j<=M;j++)
            tmp=tmp<<1|(s[j]-'A');
    }
    int ans=0;
    for(int i=(1<<M)-1;i>=0;i--)
        if(check(i))ans++;
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>T;
    for(int i=1;i<=T;i++)
        cout<<"Case #"<<i<<": "<<solve()<<endl;
    return 0;
}
