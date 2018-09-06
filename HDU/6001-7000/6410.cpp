#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
using LL=long long;
const int mod=1000000007;
const int MX=105,MV=10005;

int S[MV],val1[MX],val2[MX];
pair<int,int> P[MX];

int Inv(int u){return u==1?1:LL(mod-mod/u)*Inv(mod%u)%mod;}
int solve(int L,int R,int N)
{
    int ans=0;
    val1[0]=val2[N+1]=1;
    for(int val=L;val<=R;val++)
    {
        for(int i=1;i<=N;i++)val1[i]=S[val-P[i].first+1]-S[max(0,val-P[i].second)];
        for(int i=1;i<=N;i++)val1[i]=(LL)val1[i]*val1[i-1]%mod;
        for(int i=1;i<=N;i++)val2[i]=S[val-P[i].first+1]-S[max(1,val-P[i].second)];
        for(int i=N;i;i--)val2[i]=(LL)val2[i]*val2[i+1]%mod;
        for(int i=1;i<=N;i++)if(P[i].first<=val&&val<=P[i].second)
            ans=(ans+(LL)val1[i-1]*val2[i+1])%mod;
    }
    return ans;
}
void work()
{
    int N,L=0,R=0,ans=1;
    cin>>N;
    for(int i=1,l,r;i<=N;i++)
    {
        cin>>l>>r;
        P[i]=make_pair(l,r);
        ans=ans*LL(r-l+1)%mod;
        L=max(L,l),R=max(R,r);
    }
    cout<<(LL)solve(L,R,N)*Inv(ans)%mod<<endl;
}

int main()
{
    for(int i=1;i<=10000;i++)S[i]=S[i-1]+i;
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}
