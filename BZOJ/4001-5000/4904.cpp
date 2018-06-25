#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MN=50005,MQ=200005,MX=225;

int N,Q,ans[MQ],a[MN],tr[MN];
vector<pii> ques[MN];
vector<int> Y[MX],YT[MX];

inline void read(int& x)
{
    static char c;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void add(int u){for(;u<=N;u+=u&-u)tr[u]++;}
inline int ask(int u){int ans=0;for(;u;u-=u&-u)ans+=tr[u];return ans;}
inline void work(int u,int val)
{
    for(int i=1,tmp,_v=val;i<MX;i++)
    {
        if(Y[i].empty()||Y[i].back()>=_v)
        {
            Y[i].push_back(_v),add(i);
            break;
        }
        tmp=upper_bound(Y[i].begin(),Y[i].end(),_v,greater<int>())-Y[i].begin();
        swap(Y[i][tmp],_v);
    }
    for(int i=1,tmp,_v=val;i<MX;i++)
    {
        if(YT[i].empty()||YT[i].back()<_v)
        {
            YT[i].push_back(_v);
            if(YT[i].size()>=MX)add(YT[i].size());
            break;
        }
        tmp=lower_bound(YT[i].begin(),YT[i].end(),_v)-YT[i].begin();
        swap(YT[i][tmp],_v);
    }
    for(vector<pii>::iterator vit=ques[u].begin();vit!=ques[u].end();++vit)
        ans[vit->second]=ask(vit->first);
}

int main()
{
    read(N),read(Q);
    for(int i=1;i<=N;i++)read(a[i]);
    for(int i=1,u,v;i<=Q;i++)
        read(u),read(v),ques[u].push_back(make_pair(v,i));
    for(int i=1;i<=N;i++)work(i,a[i]);
    for(int i=1;i<=Q;i++)printf("%d\n",ans[i]);
    return 0;
}