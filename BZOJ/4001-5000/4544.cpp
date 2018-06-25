#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int T,flag;
LL n;
 
int solve(LL u)
{
    int ans=1,tmp;
    for(LL i=5;i*i<=u;i+=2)if(u%i==0)
    {
        tmp=0;
        while(u%i==0)tmp++,u/=i;
        if(i%3==2)continue;
        ans*=tmp*2+1;
    }
    if(u!=1&&u%3==1)ans*=3;
    return flag?2*ans:6*ans;
}
 
signed main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        flag=n&1;
        while(~n&1)n>>=1;
        while(n%3==0)n/=3;
        printf("%d\n",solve(n));
    }
    return 0;
}
