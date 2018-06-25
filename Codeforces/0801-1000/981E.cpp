#include<bits/stdc++.h>
using namespace std;
const int MX=10005,P1=998244353,P2=1000000007;

int N,Q,dp1[MX],dp2[MX],cnt;
vector<int> oper[MX];
bool ans[MX];

void insert(int x)
{
    for(int j=N-x;j>=0;j--)
    {
        dp1[j+x]=(dp1[j+x]+dp1[j])%P1;
        dp2[j+x]=(dp2[j+x]+dp2[j])%P2;
        if(dp1[j+x]||dp2[j+x])ans[j+x]=1;
    }
}
void del(int x)
{
    for(int j=0;j<=N-x;j++)
    {
        dp1[j+x]=(dp1[j+x]-dp1[j]+P1)%P1;
        dp2[j+x]=(dp2[j+x]-dp2[j]+P2)%P2;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>Q;
    for(int i=1,l,r,x;i<=Q;i++)
    {
        cin>>l>>r>>x;
        oper[l].push_back(x);
        oper[r+1].push_back(-x);
    }
    dp1[0]=dp2[0]=1;
    for(int i=1;i<=N;i++)
    {
        for(int j:oper[i])if(j<0)del(-j);
        for(int j:oper[i])if(j>0)insert(j);
    }
    for(int i=1;i<=N;i++)if(ans[i])cnt++;
    cout<<cnt<<endl;
    for(int i=1;i<=N;i++)if(ans[i])cout<<i<<' ';
    return 0;
}

