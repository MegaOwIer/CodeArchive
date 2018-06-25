#include<bits/stdc++.h>
using namespace std;

int n,k,x[25],ans;

inline bool check(int u)
{
    if((u&1)==0)return 0;
    for(int i=3;i<=sqrt(u);i+=2)if(u%i==0)return 0;
    return 1;
}
void dfs(int st,int lft,int sum)
{
    if(!lft){ans+=check(sum);return;}
    for(int i=st;i<=n-lft+1;i++)dfs(i+1,lft-1,sum+x[i]);
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",x+i);
    dfs(1,k,0);
    printf("%d",ans);
    return 0;
}