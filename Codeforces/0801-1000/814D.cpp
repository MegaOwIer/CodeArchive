#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int MX=1005,arr[]={0,1};

int N,fa[MX];
vector<int> son[MX];
LL ans,dp[MX][2][2];

struct Circle
{
    int x,y,r;
    LL area;
}C[MX];
istream& operator >> (istream& os,Circle& a)
{
    os>>a.x>>a.y>>a.r;
    a.area=(LL)a.r*a.r;
    return os;
}

inline bool judge(const Circle& a,const Circle& b)
{
    static auto sqr=[](int a)->LL{return (LL)a*a;};
    return sqr(a.x-b.x)+sqr(a.y-b.y)<=sqr(a.r-b.r);
}
void dfs(int u)
{
    LL g[2][2]={0,0,0,0};
    for(int i:son[u])
    {
        dfs(i);
        for(int j:arr)for(int k:arr)
            g[j][k]+=dp[i][j][k];
    }
    for(int i:arr)for(int j:arr)
        dp[u][i][j]=max(
            g[i^1][j]+C[u].area*(i?-1:1),
            g[i][j^1]+C[u].area*(j?-1:1)
        );
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N;i++)cin>>C[i];
    sort(C+1,C+N+1,[](const Circle& a,const Circle& b){return a.r>b.r;});
    for(int i=1;i<=N;i++)
    {
        for(int j=i-1;j;j--)if(judge(C[i],C[j])){fa[i]=j;break;}
        son[fa[i]].push_back(i);
    }
    for(int i=1;i<=N;i++)if(!fa[i])dfs(i),ans+=dp[i][0][0];
    cout<<fixed<<setprecision(12)<<ans*acosl(-1.0)<<endl;
    return 0;
}