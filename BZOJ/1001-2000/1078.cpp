#include<bits/stdc++.h>
using namespace std;
const int MX=105;

int N,son[MX][2],ans[MX],fa[MX],RT=1;

inline int read()
{
    static int x,c;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
void Getnum(int x,int now)
{
    if((!son[x][0]&&!son[x][1])||(!son[x][1]&&son[x][0]&&son[son[x][0]][0]))
    {
        son[fa[x]][0]=son[x][0];
        if(son[x][0])fa[son[x][0]]=fa[x];
        ans[now]=x;
        if(!fa[x])RT=son[x][0];
    }
    else Getnum(son[x][0],now),swap(son[x][0],son[x][1]);
}

int main()
{
    N=read();
    for(int i=2,u;i<=N+1;i++)
    {
        u=read()+1;
        if(u<=100)son[u][0]=i,fa[i]=u;
        else son[u-100][1]=i,fa[i]=u-100;
    }
    for(int i=N+1;i;i--)Getnum(RT,i);
    for(int i=1;i<=N+1;i++)printf("%d%c",ans[i]-1," \n"[i>N]);
    return 0;
}