#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
using std::min;
using std::max;
using std::make_pair;
typedef long long LL;
typedef std::pair<int,int> pii;
typedef std::vector<int>::iterator Vit;
const int MX=100000,INF=0x3f3f3f3f;

int N,M,K,p[MX+5],s[MX+5],c[MX+5],x[MX+5],f[MX+5],sum[MX+5];
LL ans[MX+5];
std::vector<int> a[MX+5];
priority_queue<pii,std::less<pii>,pairing_heap_tag> Addt,Temp;
std::priority_queue<pii> Heap,Ans;

inline int read()
{
    int x=0,c=getchar(); 
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

int main()
{
    N=read(),M=read(),K=read();
    for(int i=1;i<=N;i++)
    {
        p[i]=read(),s[i]=read(),c[i]=read(),x[i]=read();
        if(x[i]==0)f[i]=INF;
        else
        {
            f[i]=c[i]/x[i];
            if(c[i]%x[i])f[i]++;
            if(f[i]<=MX)a[f[i]].push_back(i);
        }
    }
    for(int i=1;i<=N;i++)if(f[i]>MX)
        if(x[i]==0)
        {
            Heap.push(make_pair(p[i]+s[i],1));
            if(c[i]>1)Heap.push(make_pair(p[i],c[i]-1));
        }
        else
        {
            int usd=MX*x[i];
            Heap.push(make_pair(p[i]+s[i],1));
            Addt.push(make_pair(p[i],x[i]));
            if(c[i]>usd+1)Heap.push(make_pair(p[i],c[i]-usd-1));
        }
    for(int i=MX;i;i--)
    {
        for(Vit it=a[i].begin();it!=a[i].end();++it)
        {
            int usd=(i-1)*x[*it];
            Heap.push(make_pair(p[*it]+s[*it],1));
            if(c[*it]>usd+1)Heap.push(make_pair(p[*it],c[*it]-usd-1));
        }
        int lft=M;
        while(lft&&!Addt.empty())
        {
            pii tmp=Addt.top();
            Addt.pop();
            int usd=min(lft,tmp.second);
            tmp.second-=usd,lft-=usd;
            Heap.push(make_pair(tmp.first,usd));
            Temp.push(make_pair(tmp.first,usd));
            if(tmp.second)Addt.push(tmp);
        }
        Addt.join(Temp);
        lft=M;
        while(lft&&!Heap.empty())
        {
            pii tmp=Heap.top();
            Heap.pop();
            int usd=min(tmp.second,lft);
            ans[MX]+=(LL)tmp.first*usd,sum[MX]+=usd;
            Ans.push(make_pair(-tmp.first,usd));
            tmp.second-=usd,lft-=usd;
            if(tmp.second)Heap.push(tmp);
        }
        for(Vit it=a[i].begin();it!=a[i].end();++it)
            Addt.push(make_pair(p[*it],x[*it]));
    }
    for(int i=MX-1;i;i--)
    {
        ans[i]=ans[i+1],sum[i]=sum[i+1];
        int cnt=max(0,sum[i]-i*M);
        while(cnt)
        {
            pii tmp=Ans.top();
            Ans.pop();
            int usd=min(tmp.second,cnt);
            ans[i]+=(LL)tmp.first*usd,sum[i]-=usd;
            tmp.second-=usd,cnt-=usd;
            if(tmp.second)Ans.push(tmp);
        }
    }
    while(K--)printf("%lld\n",ans[read()]);
    return 0;
}
