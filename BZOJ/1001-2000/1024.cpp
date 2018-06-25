#include<bits/stdc++.h>
using namespace std;

int x,y,n;

double dfs(double x,double y,double N)
{
    if(N==1)return max(x/y,y/x);
    double ans=1e18,tmp;
    tmp=x/N;
    for(int i=1;i<N;i++)ans=min(ans,max(dfs(tmp*i,y,i),dfs(x-tmp*i,y,N-i)));
    tmp=y/N;
    for(int i=1;i<N;i++)ans=min(ans,max(dfs(x,tmp*i,i),dfs(x,y-tmp*i,N-i)));
    return ans;
}

int main()
{
    scanf("%d%d%d",&x,&y,&n);
    printf("%.6lf\n",dfs(x,y,n));
    return 0;
}