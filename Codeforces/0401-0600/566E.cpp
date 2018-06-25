#include<bits/stdc++.h>
using namespace std;
const int MX=1002;

int N,cnt;
bitset<1000> T[MX],tmp,in,G[MX];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline void add(int u,int v)
{
    if(G[u][v])return;
    G[u].set(v),G[v].set(u);
    printf("%d %d\n",u+1,v+1);
}

int main()
{
    N=read();
    for(int i=0,k;i<N;i++)
    {
        k=read();
        if(k==N)cnt++;
        while(k--)T[i].set(read()-1);
        G[i].set(i);
    }
    if(cnt==N)
    {
        for(int i=2;i<=N;i++)printf("%d %d\n",1,i);
        return 0;
    }
    if(cnt==2)
    {
        tmp.set();
        for(int i=0;i<N;i++)tmp&=T[i];
        int u=tmp._Find_first();
        int v=tmp._Find_next(u);
        printf("%d %d\n",u+1,v+1);
        tmp.reset();
        for(int i=0;i<N;i++)if(T[i].count()<N&&T[i]!=tmp)
        {
            tmp=T[i];
            tmp.set(u,0),tmp.set(v,0);
            for(int j=tmp._Find_first();j<N;j=tmp._Find_next(j))
                printf("%d %d\n",u+1,j+1);
            tmp.set(u),tmp.set(v);
            break;
        }
        for(int i=0;i<N;i++)if(T[i].count()<N&&T[i]!=tmp)
        {
            tmp=T[i];
            tmp.set(u,0),tmp.set(v,0);
            for(int j=tmp._Find_first();j<N;j=tmp._Find_next(j))
                printf("%d %d\n",v+1,j+1);
            break;
        }
        return 0;
    }
    for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)
    {
        tmp=T[i]&T[j];
        if(tmp.count()==2)
        {
            int u=tmp._Find_first();
            int v=tmp._Find_next(u);
            add(u,v),in.set(u),in.set(v);
        }
    }
    for(int i=0;i<N;i++)if(!in[i])
    {
        tmp=in;
        for(int j=0;j<N;j++)if(T[j][i])tmp&=T[j];
        if(tmp.count()==2)
        {
            int u=tmp._Find_first();
            int v=tmp._Find_next(u);
            printf("%d %d\n",i+1,G[u].count()==2?u+1:v+1);
        }
        else for(int j=tmp._Find_first();j<N;j=tmp._Find_next(j))
            if((G[j]&tmp)==tmp)
            {
                printf("%d %d\n",i+1,j+1);
                break;
            }
    }
    return 0;
}
