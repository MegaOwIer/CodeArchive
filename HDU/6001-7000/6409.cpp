#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
using LL=long long;
const int MX=100005;

int val[MX];
LL dp1[MX][2],dp2[MX][2],mxdel,mndel;
vector<int> son[MX];

void dfs(int u)
{
    dp1[u][0]=dp2[u][0]=0;
    dp1[u][1]=dp2[u][1]=val[u];
    LL tmpmx=0,tmpmn=0;
    for(int i:son[u])
    {
        dfs(i);
        dp1[u][0]+=dp1[i][0];
        dp1[u][1]+=dp1[i][0];
        dp2[u][0]+=dp2[i][0];
        dp2[u][1]+=dp2[i][0];
        if(dp1[i][1]-dp1[i][0]>=tmpmx)mxdel=max(mxdel,tmpmx),tmpmx=dp1[i][1]-dp1[i][0];
        else mxdel=max(mxdel,dp1[i][1]-dp1[i][0]);
        if(dp2[i][1]-dp2[i][0]<=tmpmn)mndel=min(mndel,tmpmn),tmpmn=dp2[i][1]-dp2[i][0];
        else mndel=min(mndel,dp2[i][1]-dp2[i][0]);
    }
    dp1[u][0]+=tmpmx,dp1[u][1]+=tmpmx;
    dp2[u][0]+=tmpmn,dp2[u][1]+=tmpmn;
}

void work()
{
    int N;
    cin>>N;
    for(int i=1;i<=N;i++)son[i].clear();
    for(int i=2,u;i<=N;i++)
    {
        cin>>u;
        son[u].push_back(i);
    }
    for(int i=1;i<=N;i++)cin>>val[i];
    mxdel=mndel=0;
    dfs(1);
    cout<<max(dp1[1][0],dp1[1][1])+mxdel<<' '
        <<min(dp2[1][0],dp2[1][1])+mndel<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}
