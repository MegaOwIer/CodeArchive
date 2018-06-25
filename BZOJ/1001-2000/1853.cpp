#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
LL L,R,ans,num[2050],que[5000],tail;
bool invalid[2050];

void prework()
{
    int cnt=0;
    for(int i=1;i<=N;i++)for(int j=i+1;j<=N;j++)if(!invalid[j])
        if(num[j]%num[i]==0)invalid[j]=1;
    for(int i=1;i<=N;i++)if(!invalid[i])num[++cnt]=num[i];
    N=cnt,reverse(num+1,num+N+1);
}
inline LL gcd(LL u,LL v)
{
    if(v)while((u%=v)&&(v%=u));
    return u|v;
}
void dfs(int index,int sign,LL lcm)
{
    if(index>N)
    {
        if(lcm>1)ans+=sign*(R/lcm-(L-1)/lcm);
        return;
    }
    dfs(index+1,sign,lcm);
    LL tmp=num[index]/gcd(num[index],lcm);
    if(tmp>R/lcm)return;
    dfs(index+1,-sign,lcm*tmp);
}

int main()
{
    scanf("%lld%lld",&L,&R);
    que[tail=1]=0;
    for(int i=1;i<=tail;i++)
    {
        LL nw=que[i];
        if(nw*10+6<=R)que[++tail]=num[++N]=nw*10+6;
        if(nw*10+8<=R)que[++tail]=num[++N]=nw*10+8;
    }
    prework(),dfs(1,-1,1);
    printf("%lld\n",ans);
    return 0;
}
