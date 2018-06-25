#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MN=105,MK=1005,INF=0x3f3f3f3f;

int N,M,K,B[MN][MK],S[MN][MK],dis[MN][MN],val[MN][MN],L,R=1e9,mid,ans;
LL DIS[MN];
char ins[MN];

inline void read(int& x)
{
    static char c,f=0;
    c=getchar(),x=0;
    while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    if(f)f=0,x=-x;
}
bool SPFA(int u,int val)
{
    bool res=false;
    LL tmp;
    ins[u]=true;
    for(int i=1;i<=N;i++)if(i!=u&&dis[u][i]!=INF)
    {
        tmp=(LL)dis[u][i]*val-::val[u][i];
        if(DIS[i]>=DIS[u]+tmp)
        {
            if(ins[i])return true;
            DIS[i]=DIS[u]+tmp;
            res=res||SPFA(i,val);
        }
    }
    ins[u]=false;
    return res;
}
inline bool check(int val)
{
    bool res=false;
    memset(ins+1,0,sizeof(char)*N);
    memset(DIS+1,0,sizeof(LL)*N);
    for(int i=1;i<=N;i++)
        res=res||SPFA(i,val);
    return res;
}

int main()
{
    read(N),read(M),read(K);
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=N;i++)for(int j=1;j<=K;j++)
        read(B[i][j]),read(S[i][j]);
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)
        for(int k=1;k<=K;k++)if(~B[i][k]&&~S[j][k])
            val[i][j]=max(val[i][j],S[j][k]-B[i][k]);
    for(int i=1,u,v,w;i<=M;i++)
        read(u),read(v),read(w),dis[u][v]=w;
    for(int k=1;k<=N;k++)for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(L<=R)check(mid=L+R>>1)?L=(ans=mid)+1:R=mid-1;
    printf("%d\n",ans);
    return 0;
}
