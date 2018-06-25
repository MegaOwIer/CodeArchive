#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int N,RT,deg[MX];
vector<int> leaf;

inline void makeroot(int u)
{
    if(RT)puts("No"),exit(0);
    RT=u;
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=1,u,v;i<N;i++)
    {
        cin>>u>>v;
        deg[u]++,deg[v]++;
    }
    for(int i=1;i<=N;i++)
        if(deg[i]==1)leaf.push_back(i);
        else if(deg[i]>2)makeroot(i);
    if(!RT)printf("Yes\n1\n%d %d\n",leaf[0],leaf[1]);
    else
    {
        printf("Yes\n%u\n",leaf.size());
        for(int i:leaf)
            printf("%d %d\n",RT,i);
    }
    return 0;
}

