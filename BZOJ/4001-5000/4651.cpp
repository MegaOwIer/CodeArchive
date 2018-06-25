#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int MX=100010,MN=MX*25;

int N,M,c,dfn[MN],low[MN],cnt,flag,ans,head[MN],tot;
pii pos[MX],pos2[MN];
char vis[MX];
queue<int> q;

struct edge{int to,nxt;}e[MN<<2];

struct HashTable
{
    static const int MOD=899981;
    struct edge{int x,y,nxt;}e[MN];
    int head[MOD],tot,T,vis[MOD];

    void clear(){tot=0,T++;}
    int insert(int x,int y)
    {
        int pos=(LL(x-1)*M+y)%MOD;
        if(vis[pos]!=T)vis[pos]=T,head[pos]=0;
        e[++tot]=(edge){x,y,head[pos]},head[pos]=tot;
        return tot;
    }
    int find(int x,int y)
    {
        int pos=(LL(x-1)*M+y)%MOD;
        if(vis[pos]!=T)return 0;
        for(int i=head[pos];i;i=e[i].nxt)
            if(e[i].x==x&&e[i].y==y)return i;
        return 0;
    }
}mp1,mp2;

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline void add(int u,int v)
{
    e[++tot]=(edge){v,head[u]},head[u]=tot;
    e[++tot]=(edge){u,head[v]},head[v]=tot;
}
void Tarjan(int u,int f)
{
    int siz=0;
    dfn[u]=low[u]=++cnt;
    for(int i=head[u];i;i=e[i].nxt)if(e[i].to!=f)
    {
#define v e[i].to
        ++siz;
        if(!dfn[v])
        {
            Tarjan(v,u),low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u])
            {
                flag++;
                if(!f&&siz<=1)flag--;
            }
        }
        else low[u]=min(low[u],dfn[v]);
#undef v
    }
}
void work(int u)
{
    mp2.clear();
    q.push(u),vis[u]=1;
    while(!q.empty())
    {
        int nw=q.front();
        q.pop();
        int x=pos[nw].first,y=pos[nw].second;
        for(int i=-2;i<=2;i++)for(int j=-2,k;j<=2;j++)
        {
            int nx=x+i,ny=y+j;
            if(nx<1||ny<1||nx>N||ny>M)continue;
            if(k=mp1.find(nx,ny))
            {
                if(!vis[k])q.push(k),vis[k]=1;
                continue;
            }
            if(!mp2.find(nx,ny))
                pos2[mp2.insert(nx,ny)]=make_pair(nx,ny);
        }
    }
    int V=mp2.tot;
    memset(dfn+1,0,sizeof(int)*V);
    memset(low+1,0,sizeof(int)*V);
    tot=0,memset(head+1,0,sizeof(int)*V);
    for(int i=1,j;i<=V;i++)
    {
        int x=pos2[i].first,y=pos2[i].second;
        if(j=mp2.find(x+1,y))add(i,j);
        if(j=mp2.find(x,y+1))add(i,j);
    }
    cnt=0,flag=0,Tarjan(1,0);
    if(flag)ans=1;
    if(cnt!=V)ans=0;
}
int solve()
{
    if((LL)N*M-c<=1)return -1;
    if((LL)N*M-c==2)
    {
        memset(vis+1,0,sizeof(char)*N*M);
        for(int i=1;i<=c;i++)
            vis[(pos[i].first-1)*M+pos[i].second]=1;
        int x1=0,y1=0,x2=0,y2=0;
        for(int i=N*M;i;i--)if(!vis[i])
            if(x1)x2=(i-1)/M+1,y2=i-M*(x2-1);
            else x1=(i-1)/M+1,y1=i-M*(x1-1);
        if(abs(x1-x2)+abs(y1-y2)==1)return -1;
        else return 0;
    }
    if(c==0)return min(N,M)==1?1:2;
    mp1.clear();
    memset(vis+1,0,sizeof(char)*c);
    for(int i=1;i<=c;i++)mp1.insert(pos[i].first,pos[i].second);
    ans=(min(N,M)==1)?1:2;
    for(int i=1;i<=c&&ans;i++)if(!vis[i])work(i);
    return ans;
}

int main()
{
    for(int T=read();T--;)
    {
        N=read(),M=read(),c=read();
        for(int i=1;i<=c;i++)pos[i].first=read(),pos[i].second=read();
        printf("%d\n",solve());
    }
    return 0;
}
