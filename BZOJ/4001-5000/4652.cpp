#include<bits/stdc++.h>
#include<tr1/unordered_map>
using namespace std;
typedef long long LL;
const int MK=2005,MX=1000005;

int N,M,K,pre[MK],miu[MX],pr[78501],cnt,d[12],tot;
LL ans;
bool vis[MX];
tr1::unordered_map<int,int> sum;
tr1::unordered_map<LL,LL> res;

inline int f(int n){return n/K*pre[K]+pre[n%K];}
inline void divide(int K)
{
    for(int i=1;pr[i]*pr[i]<=K;i++)if(K%pr[i]==0)
    {
        d[++tot]=pr[i];
        while(K%pr[i]==0)K/=pr[i];
    }
    if(K>1)d[++tot]=K;
}
int getmiu(int u)
{
    if(u<=1e6)return miu[u];
    if(sum.count(u))return sum[u];
    int ans=1;
    for(int i=2,j;i<=u;i=j+1)
        j=u/(u/i),ans-=(j-i+1)*getmiu(u/i);
    return sum[u]=ans;
}
LL G(int N,int K,int index=1)
{
    if(N<=1)return N;
    if(K==1)return getmiu(N);
    LL tmp=(LL)N*INT_MAX+K;
    if(res.count(tmp))return res[tmp];
    int pr=d[index],q=K;
    while(q%pr==0)q/=pr;
    return res[tmp]=G(N,q,index+1)+G(N/pr,K,index);
}

int main()
{
    miu[1]=1;
    for(int i=2,tmp;i<=1e6;i++)
    {
        if(!vis[i])pr[++cnt]=i,miu[i]=-1;
        for(int j=1;j<=cnt&&(tmp=i*pr[j])<=1e6;j++)
        {
            vis[tmp]=1;
            if(i%pr[j]==0){miu[tmp]=0;break;}
            miu[tmp]=-miu[i];
        }
    }
    for(int i=1;i<=1e6;i++)miu[i]+=miu[i-1];
    ios::sync_with_stdio(0);
    cin>>N>>M>>K;
    divide(K);
    for(int i=1;i<=K;i++)
        pre[i]=pre[i-1]+(__gcd(i,K)==1);
    for(int i=1,j;i<=N&&i<=M;i=j+1)
    {
        j=min(N/(N/i),M/(M/i));
        ans+=LL(N/i)*f(M/i)*(G(j,K)-G(i-1,K));
    }
    cout<<ans<<endl;
    return 0;
}
