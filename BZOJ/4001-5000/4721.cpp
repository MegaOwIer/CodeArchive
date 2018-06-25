#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=7500000;

int n,m,q,u,v,t,Q[4][maxn],h[4],T[4],mxid,mx=-2000000000,a,b;
char c;

inline void read(int& x)
{
    x=0,c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}

int main()
{
    read(n),read(m),read(q),read(u),read(v),read(t);
    for(int i=1;i<=n;i++)read(Q[1][i]),h[1]=h[2]=h[3]=1,T[1]=n;
    sort(Q[1]+1,Q[1]+n+1,greater<int>());
    for(int i=1,res=t-1;i<=m;i++,res--,mxid=0,mx=-2000000000)
    {
        for(int id=1;id<4;id++)if(h[id]<=T[id]&&Q[id][h[id]]>mx)mxid=id,mx=Q[mxid][h[mxid]];
        h[mxid]++;
        mx+=(i-1)*q;
        a=(LL)mx*u/v,b=mx-a;
        Q[2][++T[2]]=a-q*i,Q[3][++T[3]]=b-q*i;
        if(!res)printf(i+t>m?"%d":"%d ",mx),res=t;
    }
    puts("");
    for(int i=1,res=t-1;i<=m+n;i++,res--,mx=-2000000000,mxid=0)
    {
        for(int id=1;id<4;id++)if(h[id]<=T[id]&&Q[id][h[id]]>mx)mxid=id,mx=Q[mxid][h[mxid]];
        h[mxid]++;
        if(!res)printf(i+t>m+n?"%d":"%d ",mx+m*q),res=t;
    }
    return 0;
}
