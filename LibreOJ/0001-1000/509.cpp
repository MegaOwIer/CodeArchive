#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=10000000,MN=10000005;

int _miu[MN],miu2[MN];
LL N,M,ans;
unordered_map<int,int> miu;

void init(int N)
{
    static int cnt=0,pr[664585];
    static char vis[MN];
    _miu[1]=miu2[1]=1;
    for(int i=2,tmp,j;i<=N;i++)
    {
        if(!vis[i])pr[++cnt]=i,_miu[i]=-1,miu2[i]=1;
        for(j=1;j<=cnt&&(tmp=i*pr[j])<=N;j++)
        {
            vis[tmp]=1;
            if(i%pr[j]==0)break;
            _miu[tmp]=-_miu[i],miu2[tmp]=miu2[i];
        }
    }
    for(int i=2;i<=N;i++)_miu[i]=_miu[i]+_miu[i-1];
    for(int i=2;i<=N;i++)miu2[i]=miu2[i]+miu2[i-1];
}
inline int getsum1(int n)
{
    if(n<=MX)return _miu[n];
    if(miu.count(n))return miu[n];
    int ans=1;
    for(int i=2,j,k;i<=n;i=j+1)
        j=n/(k=n/i),ans-=getsum1(k)*(j-i+1);
    return miu[n]=ans;
}
inline LL getsum2(LL n)
{
    if(n<=MX)return miu2[n];
    LL n0,ans=0,i;
    int pre,nw;
    for(i=1;i*i*i<=n;i++)ans+=(n/i/i)*(_miu[i]-_miu[i-1]);
    pre=getsum1(sqrt(n/(n/i/i+1)));
    for(LL j=n/i/i;j>0;j--,pre=nw)
        n0=sqrt(n/j),nw=getsum1(n0),ans+=(nw-pre)*j;
    return ans;
}

int main()
{
    init(MX);
    ios::sync_with_stdio(0);
    cin>>N>>M;
    if(N>M)swap(N,M);
    for(LL i=1,j,N0,M0,pre=0,nw;i<=N;i=j+1,pre=nw)
    {
        N0=sqrt(N/i),M0=sqrt(M/i);
        j=min(N/N0/N0,M/M0/M0);
        nw=getsum2(j),ans+=N0*M0*(nw-pre);
    }
    cout<<ans<<endl;
    return 0;
}