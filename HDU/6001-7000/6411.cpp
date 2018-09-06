#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
using LL=long long;
const int MX=100005;
const int mod=1000000007;

int val[MX],pw2[31];
char vis[MX];
vector<int> V,G[MX];

inline void update(int &u,int v){((u+=v)>=mod)&&(u-=mod);}
void bfs(int u)
{
    V.clear();
    queue<int> Q;
    Q.push(u);
    while(!Q.empty())
    {
        int nw=Q.front();  Q.pop();
        if(vis[nw])continue;
        vis[nw]=1,V.push_back(val[nw]);
        for(int i:G[nw])Q.push(i);
    }
}
int getans()
{
    int ans=0,cnt[31];
    sort(V.begin(),V.end(),greater<int>());
    memset(cnt,0,sizeof(cnt));
    for(int i:V)for(int j=0;j<30;j++)cnt[j]+=(i>>j)&1;
    for(int val:V)
    {
        int sum=0;
        for(int i=0;i<30;i++)if((val>>i)&1)
            cnt[i]--,update(sum,(LL)pw2[i]*cnt[i]%mod);
        update(ans,(LL)sum*val%mod);
    }
    return ans;
}
void work()
{
    int N,M,ans=0;
    cin>>N>>M;
    for(int i=1;i<=N;i++)G[i].clear();
    memset(vis+1,0,sizeof(char)*N);
    for(int i=1;i<=N;i++)cin>>val[i];
    for(int i=1,u,v;i<=M;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=N;i++)if(!vis[i])
        bfs(i),update(ans,getans());
    cout<<ans<<endl;
}

int main()
{
    for(int i=0;i<=29;i++)pw2[i]=1<<i;
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)work();
    return 0;
}