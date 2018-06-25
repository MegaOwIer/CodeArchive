#include<bits/stdc++.h>
using namespace std;
const int MV=205,ME=11000;

int dis[MV],S,T,N,V;
string s,t,st[105];
vector<string> v1,v2;
unordered_map<string,int> id;
char inq[MV];

struct edge
{
    int to,f,c,flag;
    edge *nxt,*rev;
    edge(){}
    edge(int t,edge *n,int f,int c):to(t),f(f),c(c),nxt(n),flag(0){}
    void* operator new(size_t);
}*E[MV],ePool[ME],*ptr=ePool,*from[MV];
inline void* edge::operator new(size_t){return ptr++;}

inline void add(int u,int v,int f,int c)
{
    E[u]=new edge(v,E[u],f,c),E[v]=new edge(u,E[v],0,-c);
    E[u]->rev=E[v],E[v]->rev=E[u];
}
inline bool spfa()
{
    queue<int> q;
    int now;
    memset(dis+1,0x3f,sizeof(int)*T),dis[S]=0;
    memset(inq+1,0,sizeof(char)*T),inq[S]=1;
    q.push(S);
    while(!q.empty())
    {
        now=q.front(),q.pop(),inq[now]=0;
        for(edge *i=E[now];i;i=i->nxt)if(i->f&&dis[i->to]>dis[now]+i->c)
        {
            dis[i->to]=dis[now]+i->c,from[i->to]=i;
            if(!inq[i->to])q.push(i->to),inq[i->to]=1;
        }
    }
    return dis[T]<0x3f3f3f3f;
}
inline int MinCostMaxFlow()
{
    int ans=0,flow,cnt=0;
    while(spfa())
    {
        flow=2147483647;
        for(int i=T;i!=S;i=from[i]->rev->to)flow=min(flow,from[i]->f);
        for(int i=T;i!=S;i=from[i]->rev->to)from[i]->f-=flow,from[i]->rev->f+=flow;
        for(int i=T;i!=S;i=from[i]->rev->to)from[i]->flag^=1,from[i]->rev->flag^=1;
        ans+=flow*dis[T],cnt+=flow;
    }
    if(cnt!=2)puts("No Solution!"),exit(0);
    return ans;
}
void dfs(int u)
{
    u+=N;
    for(edge *i=E[u];i;i=i->nxt)
		if(i->flag&&abs(i->to-u)!=N)dfs(i->to);
    cout<<st[u-N]<<endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>V;
    S=1,T=N+N;
    for(int i=1;i<=N;i++)cin>>st[i],id[st[i]]=i,add(i,i+N,1,0);
    add(1,1+N,1,0),add(N,N+N,1,0);
    for(int i=1;i<=V;i++)
    {
        cin>>s>>t;
        if(id[s]>id[t])swap(s,t);
        add(id[s]+N,id[t],1,-1);
        if(id[s]==1&&id[t]==N)add(1+N,N,1,-1);
    }
    cout<<-MinCostMaxFlow()<<endl;
    for(int i=S;i!=N;)
    {
        cout<<st[i]<<endl,i+=N;
        for(edge *j=E[i];j;j=j->nxt)if(j->flag)
        {
            i=j->to,j->flag=0;
            break;
        }
    }
    dfs(S);
    return 0;
}
