#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=105,MK=1005,INF=0x3f3f3f3f;
#define REP(i,a,b) for(int i=a;i<=b;i++)

int N,M,K,B[MX][MK],S[MX][MK],dis[MX][MX],cnt[MX],val[MX][MX];
LL tmp[MX];
char inq[MX];
queue<int> q;

inline int read()
{
    int x=0,c=getchar(),f=1;
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x*f;
}
bool SPFA(int S,int k)
{
    while(!q.empty())q.pop();
    memset(inq+1,0,sizeof(char)*N);
    memset(cnt+1,0,sizeof(int)*N);
    q.push(S),cnt[S]=1,tmp[S]=0;
    while(!q.empty())
    {
        int nw=q.front();
        q.pop(),inq[nw]=0;
        REP(i,1,N)if(i!=nw&&dis[nw][i]!=INF)
        {
            LL w=(LL)k*dis[nw][i]-val[nw][i];
            if(tmp[i]>=tmp[nw]+w)
            {
                tmp[i]=tmp[nw]+w;
                if(!inq[i])
                {
                    inq[i]=1,q.push(i);
                    if(++cnt[i]==N)return true;
                }
            }
        }
    }
    return false;
}
bool check(int val)
{
    memset(tmp+1,0x3f,sizeof(LL)*N);
    bool res=false;
    for(int i=1;i<=N;i++)
        if(tmp[i]==0x3f3f3f3f3f3f3f3fLL)
            res=res||SPFA(i,val);
    return res;
}

int main()
{
    memset(dis,0x3f,sizeof(dis));
    N=read(),M=read(),K=read();
    REP(i,1,N)dis[i][i]=0;
    REP(i,1,N)REP(j,1,K)B[i][j]=read(),S[i][j]=read();
    REP(i,1,N)REP(j,1,N)REP(k,1,K)if((~B[i][k])&&(~S[j][k]))
        val[i][j]=max(val[i][j],S[j][k]-B[i][k]);
    REP(i,1,M)
    {
        int u=read(),v=read(),w=read();
        dis[u][v]=w;
    }
    REP(k,1,N)REP(i,1,N)REP(j,1,N)if(dis[i][k]!=INF&&dis[k][j]!=INF)
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    int L=0,R=1000000000,mid,ans=0;
    check(0);
    while(L<=R)
        if(check(mid=L+R>>1))L=mid+1,ans=mid;
        else R=mid-1;
    printf("%d\n",ans);
    return 0;
}
