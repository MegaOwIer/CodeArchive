#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=300005;

int N,a[MX],SA[MX],rk[MX],tp[MX],Height[MX];
LL ans[MX],cnt[MX];
char s[MX];
pair<int,int> pos[MX];

struct UnionFindSet
{
    int fa[MX],siz[MX],mx[MX],mn[MX];

    int find(int u){return u==fa[u]?u:fa[u]=find(fa[u]);}
    void merge(int x,int y)
    {
        x=find(x),y=find(y),fa[y]=x;
        mx[x]=max(mx[x],mx[y]);
        mn[x]=min(mn[x],mn[y]);
        siz[x]+=siz[y];
    }
}UFS;

inline int read()
{
    int x=0,c=getchar(),f=1;
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x*f;
}
inline void RadixSort(int M)
{
    static int num[MX];
    memset(num+1,0,sizeof(int)*M);
    for(int i=1;i<=N;i++)num[rk[tp[i]]]++;
    for(int i=2;i<=M;i++)num[i]+=num[i-1];
    for(int i=N;i;i--)SA[num[rk[tp[i]]]--]=tp[i];
}

int main()
{
    N=read(),scanf("%s",s+1);
    for(int i=1;i<=N;i++)a[i]=read();
    for(int i=1;i<=N;i++)rk[i]=s[i],tp[i]=i;
    RadixSort(127);
#define cmp (tp[SA[i]]==tp[SA[i-1]]&&tp[SA[i]+w]==tp[SA[i-1]+w])
    for(int i,w=1,p,m=127;w<=N;w<<=1,m=p)
    {
        for(p=0,i=N-w+1;i<=N;i++)tp[++p]=i;
        for(i=1;i<=N;i++)if(SA[i]>w)tp[++p]=SA[i]-w;
        RadixSort(m),memcpy(tp+1,rk+1,sizeof(int)*N);
        rk[SA[1]]=p=1;
        for(i=2;i<=N;i++)rk[SA[i]]=cmp?p:++p;
    }
#undef cmp
    for(int i=1,k=0,j;i<=N;Height[rk[i++]]=k)
        for(k=k?k-1:k,j=SA[rk[i]-1];s[i+k]==s[j+k];k++);
    for(int i=1;i<=N;i++)
        UFS.fa[i]=i,UFS.mx[i]=UFS.mn[i]=a[SA[i]],UFS.siz[i]=1;
    memset(ans+1,0xc0,sizeof(LL)*N);
    for(int i=2;i<=N;i++)pos[i-1]=make_pair(Height[i],i);
    sort(pos+1,pos+N,greater<pair<int,int> >());
    for(int i=pos[1].first,j=1;i>=0;i--)
    {
        ans[i]=ans[i+1],cnt[i]=cnt[i+1];
        while(j<N&&pos[j].first==i)
        {
            int x=UFS.find(pos[j].second),y=UFS.find(pos[j].second-1);
            ans[i]=max(ans[i],(LL)UFS.mx[x]*UFS.mx[y]);
            ans[i]=max(ans[i],(LL)UFS.mn[x]*UFS.mn[y]);
            cnt[i]+=(LL)UFS.siz[x]*UFS.siz[y];
            UFS.merge(x,y),j++;
        }
    }
    for(int i=0;i<N;i++)
        if(cnt[i])printf("%lld %lld\n",cnt[i],ans[i]);
        else puts("0 0");
    return 0;
}
