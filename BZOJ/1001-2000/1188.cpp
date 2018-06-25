#include<bits/stdc++.h>
using namespace std;
const int MX=25;

int N,SG[MX],vis[64];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
void getSG(int N)
{
    memset(vis,-1,sizeof(vis));
    SG[N-1]=0;
    for(int i=N-2,j,k;i>=0;i--)
    {
        for(j=i+1;j<N;j++)for(k=j;k<N;k++)
            vis[SG[j]^SG[k]]=i;
        for(j=0;vis[j]==i;j++);
        SG[i]=j;
    }
}

int main()
{
    for(int T=read();T--;)
    {
        getSG(N=read());
        int ans=0,tot=0;
        for(int i=0;i<N;i++)if(read()&1)ans^=SG[i];
        for(int i=0,j,k;i<N;i++)
            for(j=i+1;j<N;j++)for(k=j;k<N;k++)
                if((ans^SG[i]^SG[j]^SG[k])==0)
                {
                    ++tot;
                    if(tot==1)printf("%d %d %d\n",i,j,k);
                }
        if(tot>0)printf("%d\n",tot);
        else puts("-1 -1 -1\n0");
    }
    return 0;
}