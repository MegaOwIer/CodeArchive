#include<bits/stdc++.h>
using namespace std;

const int MX=100005;

int N,M,dep[MX];
vector<int> G[MX];
vector<vector<int>> ans;

struct cmp{bool operator () (int a,int b){return dep[a]<dep[b];}};
priority_queue<int,vector<int>,cmp> Q;

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
void dfs(int u)
{
    int &cur=dep[u],mx=0;
    for(int i:G[u])dfs(i),mx=max(mx,dep[i]);
    cur=mx+1;
}

int main()
{
    N=read(),M=read();
    for(int i=2,u;i<=N;i++)u=read(),G[u].push_back(i);
    dfs(1);
    Q.push(1);
    while(!Q.empty())
    {
        vector<int> tmp,res;
        for(int i=1;i<=M&&!Q.empty();i++)
        {
            int nw=Q.top();  Q.pop();
            res.push_back(nw);
            for(int j:G[nw])tmp.push_back(j);
        }
        for(int i:tmp)Q.push(i);
        ans.push_back(res);
    }
    printf("%d\n",(int)ans.size());
    // for(auto vec:ans)
    // {
    //     printf("%d ",(int)vec.size());
    //     for(int i:vec)printf("%d ",i);
    //     putchar('\n');
    // }
    return 0;
}
