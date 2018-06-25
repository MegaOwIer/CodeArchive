#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int N,M,K,deg[MX],ans[MX];
vector<int> G[MX];
vector<pair<int,int> > res;
priority_queue<int,vector<int>,greater<int> > mn;
priority_queue<int> mx;

void work(int u)
{
    for(auto i:G[u])
        if(!--deg[i])mn.push(i);
}

int main()
{
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    scanf("%d%d%d",&N,&M,&K);
    for(int i=1,u,v;i<=M;i++)
    {
        scanf("%d%d",&u,&v);
        deg[v]++;
        G[u].push_back(v);
    }
    for(int i=1;i<=N;i++)if(!deg[i])mn.push(i);
    for(int i=1;i<=N;i++)
    {
        while(K&&mn.size()>1)
            mx.push(mn.top()),mn.pop(),K--;
        if(!mn.size())
        {
            ans[i]=mx.top(),mx.pop();
            work(ans[i]);
            res.push_back(make_pair(ans[i-1],ans[i]));
        }
        else if(mn.size()==1&&K&&mx.size()&&mn.top()<mx.top())
        {
            K--;
            int tmp=mx.top();
            mx.pop(),mx.push(mn.top()),mn.pop();
            work(ans[i]=tmp);
            res.push_back(make_pair(ans[i-1],tmp));
        }
        else ans[i]=mn.top(),mn.pop(),work(ans[i]);
    }
    for(int i=1;i<=N;i++)printf("%d%c",ans[i]," \n"[i==N]);
    printf("%lu\n",res.size());
    for(auto i:res)printf("%d %d\n",i.first,i.second);
    return 0;
}
