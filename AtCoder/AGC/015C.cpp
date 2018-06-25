#include<bits/stdc++.h>
using namespace std;
const int MX=2002;

int N,M,Q,V[MX][MX],EC[MX][MX],EL[MX][MX];

inline int read()
{
    static int c,x;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

int main()
{
    N=read(),M=read(),Q=read();
    for(int i=1;i<=N;i++,getchar())for(int j=1;j<=M;j++)
    {
        V[i][j]=getchar()-'0';
        if(V[i][j]&&V[i][j-1])EC[i][j]=1;
        if(V[i][j]&&V[i-1][j])EL[i][j]=1;
        EC[i][j]+=EC[i][j-1],EL[i][j]+=EL[i][j-1];
    }
    for(int i=2;i<=N;i++)for(int j=1;j<=M;j++)
        V[i][j]+=V[i-1][j],EC[i][j]+=EC[i-1][j],EL[i][j]+=EL[i-1][j];
    for(int i=1;i<=N;i++)for(int j=2;j<=M;j++)V[i][j]+=V[i][j-1];
    while(Q--)
    {
        int x1=read(),y1=read(),x2=read(),y2=read();
        int _V=V[x2][y2]+V[x1-1][y1-1]-V[x2][y1-1]-V[x1-1][y2];
        int _E=EC[x2][y2]+EC[x1-1][y1]-EC[x1-1][y2]-EC[x2][y1];
        _E+=EL[x2][y2]+EL[x1][y1-1]-EL[x2][y1-1]-EL[x1][y2];
        printf("%d\n",_V-_E);
    }
    return 0;
}
