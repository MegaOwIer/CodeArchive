#include<bits/stdc++.h>
using namespace std;
using LL=long long;

int P,N,d[12],pw[12],cnt,ans;

void divide(int N)
{
    if(N%2==0)while(N%2==0)pw[0]++,N>>=1;
    for(int i=3;(LL)i*i<=N;i++)if(N%i==0)
    {
        d[++cnt]=i;
        while(N%i==0)N/=i,pw[cnt]++;
    }
    if(N>1)d[++cnt]=N,pw[cnt]=1;
}
inline int gcd(int u,int v)
{
    if(v)while((u%=v)&&(v%=u));
    return u+v;
}
inline int v(int p,int n)
{
    int ans=0;
    while(n%p==0)n/=p,ans++;
    return ans;
}
inline LL Pow(LL a,int b)
{
    LL ans=1;
    for(;b;b>>=1,a*=a)if(b&1)ans*=a;
    return ans;
}
int solve1(int alpha)
{
    if(alpha<=1)return 1<<alpha;
    int mx=(alpha-2)/P,res=1,C=Pow(2,alpha-1)/gcd(P,2);
    for(int i=0;i<=mx;i++)
        res+=C/gcd(Pow(2,alpha-2),P*Pow(2,i*P));
    if(alpha%P==1||P==1)res++;
    return res;
}
inline int solve2(int p,int alpha)
{
    int mx=(alpha-1)/P,res=0,C=Pow(p,alpha-1);
    for(int i=0;i<=mx;i++)res+=C/gcd(C,P*Pow(p,i*P));
    return (p-1)/gcd(p-1,P)*res+1;
}

int main()
{
    scanf("%d%*d%d",&P,&N);
    divide(N);
    ans=solve1(pw[0]);
    for(int i=1;i<=cnt;i++)ans*=solve2(d[i],pw[i]);
    cout<<ans<<endl;
    return 0;
}
