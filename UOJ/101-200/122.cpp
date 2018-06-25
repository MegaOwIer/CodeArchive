#include<bits/stdc++.h>
using namespace std;
const int MX=200005;

int N,d[MX],pos[MX],s[MX],ans;

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

int main()
{
    N=read(),s[1]=1,s[2]=-1;
    for(int i=1;i<=N;i++)pos[d[i]=read()]=i;
    for(int i=1;i<=N;i++)d[pos[read()]]=i;
    for(int i=1;i<=N;i++)pos[d[i]]=i;
    for(int i=2;i<=N;i++)if(pos[i]<pos[i-1])s[i-1]++,s[i]--,ans+=2;
    for(int i=2;i<=N;i++)if(d[i-1]+1<d[i])s[d[i-1]]++,s[d[i]]--;
    for(int i=1,j=0;i<N;i++)j+=s[i],ans+=j?0:1;
    printf("%d.%c00\n",2+ans/2,"05"[ans&1]);
    return 0;
}
