#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int MX=30005,mod1=998244353,mod2=1000000007;
const pii P=make_pair(29,31);

int T,N;
pii pw[MX],hs[MX];
LL pre[MX<<1],suf[MX<<1],ans;
char s[MX];

#define fi first
#define se second
pii operator + (pii a,int x)
{
    return make_pair((a.fi+x)%mod1,(a.se+x)%mod2);
}
pii operator - (pii a,pii b)
{
    return make_pair((a.fi-b.fi+mod1)%mod1,(a.se-b.se+mod2)%mod2);
}
pii operator * (pii a,pii b)
{
    return make_pair((LL)a.fi*b.fi%mod1,(LL)a.se*b.se%mod2);
}
#undef fi
#undef se
inline pii substr(int l,int r){return hs[r-1]-hs[l-1]*pw[r-l];}

int main()
{
    pw[0]=make_pair(1,1);
    for(int i=1;i<=30000;i++)pw[i]=pw[i-1]*P;
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--)
    {
        cin>>(s+1);
        N=strlen(s+1);
        memset(pre+1,0,sizeof(LL)*N);
        memset(suf+1,0,sizeof(LL)*N);
        for(int i=1;i<=N;i++)hs[i]=hs[i-1]*P+(s[i]-'a'+1);
        hs[N+1]=make_pair(0,0);
        for(int L=1;L+L<=N;L++)for(int i=1,j=L+1;j<=N;i+=L,j+=L)
        {
            if(s[i]!=s[j])continue;
            int l,r,mid,lcs=0,lcp=0;
            l=1,r=min(L,N-j+1);
            while(l<=r)
            {
                mid=l+r>>1;
                if(substr(i,i+mid)==substr(j,j+mid))lcp=mid,l=mid+1;
                else r=mid-1;
            }
            l=1,r=min(i,L);
            while(l<=r)
            {
                mid=l+r>>1;
                if(substr(i+1-mid,i+1)==substr(j+1-mid,j+1))lcs=mid,l=mid+1;
                else r=mid-1;
            }
            if(lcp+lcs<=L)continue;
            pre[i-lcs+1]++,pre[i-(L-lcp)+1]--;
            suf[i-lcs+2*L]++,suf[i+lcp+L]--;
        }
        ans=0;
        for(int i=1;i<=N;i++)pre[i]+=pre[i-1],suf[i]+=suf[i-1];
        for(int i=1;i<N;i++)ans+=suf[i]*pre[i+1];
        printf("%lld\n",ans);
    }
    return 0;
}
