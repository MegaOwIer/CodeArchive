#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
const int MX=4005;

int N,M,blt[MX],siz[MX],dfn[MX],low[MX],cnt,stk[MX],top;
tr1::unordered_map<string,int> Male,Female;
string n1,n2;
vector<int> G[MX];

void Tarjan(int u)
{
    typedef vector<int>::iterator Vit;
    static int tot=0,v;
    dfn[u]=low[u]=++tot,stk[++top]=u;
    for(Vit it=G[u].begin();it!=G[u].end();++it)
        if(!dfn[*it])Tarjan(*it),low[u]=min(low[u],low[*it]);
        else if(!blt[*it])low[u]=min(low[u],dfn[*it]);
    if(dfn[u]==low[u])
    {
        blt[u]=++cnt,siz[cnt]=1;
        while((v=stk[top--])!=u)blt[v]=cnt,siz[cnt]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>n1>>n2,Female[n1]=Male[n2]=i;
    cin>>M;
    for(int i=1;i<=M;i++)
    {
        cin>>n1>>n2;
        G[Female[n1]].push_back(Male[n2]);
    }
    for(int i=1;i<=N;i++)if(!dfn[i])Tarjan(i);
    for(int i=1;i<=N;i++)puts(siz[blt[i]]>1?"Unsafe":"Safe");
    return 0;
}
