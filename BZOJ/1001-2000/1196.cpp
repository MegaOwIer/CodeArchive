#include<bits/stdc++.h>
using namespace std;
const int MX=10005;
 
int N,M,K,fa[MX],cnt,ans;
 
struct edge
{
    int u,v,c1,c2;
    bool flag;
    bool operator < (const edge& a)const{return c1<a.c1;}
    bool operator > (const edge& a)const{return min(c1,c2)<min(a.c1,a.c2);}
}e[MX<<1];
 
inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
 
int main()
{
    N=read(),K=read(),M=read()-1;
    for(int i=1;i<=N;i++)fa[i]=i;
    for(int i=1;i<=M;i++)
        e[i].u=read(),e[i].v=read(),e[i].c1=read(),e[i].c2=read();
    sort(e+1,e+M+1);
    for(int i=1,fu,fv;cnt<K;i++)
    {
        fu=find(e[i].u),fv=find(e[i].v);
        if(fu==fv)continue;
        fa[fu]=fv,cnt++,e[i].flag=true;
        if(e[i].c1>ans)ans=e[i].c1;
    }
    sort(e+1,e+M+1,greater<edge>());
    for(int i=1,fu,fv;i<=M;i++)if(!e[i].flag)
    {
        fu=find(e[i].u),fv=find(e[i].v);
        if(fu==fv)continue;
        fa[fu]=fv,cnt++;
        ans=max(ans,min(e[i].c1,e[i].c2));
    }
    printf("%d\n",ans);
    return 0;
}