#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
#define Vit(T) vector<T>::iterator
#define st first
#define nd second

const int MX=100005;

int N,fa[MX],dis[MX];
LL ans1,ans2,f[MX],pre[MX],suf[MX],pans[MX],sans[MX];
bool vis[MX],ond[MX];
vector<pii> G[MX],diam;

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline void add(int u,int v,int w)
{
    G[u].push_back(make_pair(v,w));
    G[v].push_back(make_pair(u,w));
}
void dfs1(int u,int f)
{
    vis[u]=true;
    for(Vit(pii) it=G[u].begin();it!=G[u].end();++it)if(it->st!=f)
        if(!vis[it->st])fa[it->st]=u,dis[it->st]=it->nd,dfs1(it->st,u);
        else if(!ond[it->st])
        {
            int u1=u,v1=it->st;
            diam.push_back(make_pair(u1,it->nd));
            ond[u1]=1;
            while(u1!=v1)
                diam.push_back(make_pair(fa[u1],dis[u1])),u1=fa[u1],ond[u1]=1;
        }
}
void dfs2(int u,int _f)
{
    for(Vit(pii) it=G[u].begin();it!=G[u].end();++it)
        if(it->st!=_f&&!ond[it->st])
        {
            dfs2(it->st,u);
            ans1=max(ans1,f[u]+f[it->st]+it->nd);
            f[u]=max(f[u],f[it->st]+it->nd);
        }
}

int main()
{
    N=read(),diam.push_back(make_pair(-1,-1));
    for(int i=1,u,v,w;i<=N;i++)
        u=read(),v=read(),w=read(),add(u,v,w);
    dfs1(1,0);
    for(Vit(pii) it=diam.begin()+1;it!=diam.end();++it)dfs2(it->st,0);
    LL tmp=0,res=0;
    for(int i=1;i<diam.size();i++)
    {
        if(i!=1)tmp+=diam[i].nd;
        pre[i]=max(pre[i-1],tmp+f[diam[i].st]);
        pans[i]=max(pans[i-1],tmp+res+f[diam[i].st]);
        res=max(res,f[diam[i].st]-tmp);
    }
    tmp=res=0;
    for(int i=diam.size()-1;i;i--)
    {
        if(i!=diam.size()-1)tmp+=diam[i+1].nd;
        suf[i]=max(suf[i+1],tmp+f[diam[i].st]);
        sans[i]=max(sans[i+1],tmp+res+f[diam[i].st]);
        res=max(res,f[diam[i].st]-tmp);
    }
    ans2=pans[diam.size()-1];
    for(int i=1;i<diam.size()-1;i++)
        ans2=min(ans2,max(max(pans[i],sans[i+1]),pre[i]+suf[i+1]+diam[1].nd));
    ans1=max(ans1,ans2);
    printf("%lld.%c\n",ans1>>1,"05"[ans1&1]);
    return 0;
}
