#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MX=100005;
#define mp make_pair
#define upper(a,b) upper_bound(a.begin(),a.end(),mp(b,INT_MAX))
#define lower(a,b) lower_bound(a.begin(),a.end(),mp(b,0))

int N,M,pr[9595],d[MX],cnt;
vector<pii> pw[9595];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline void work(int val,int index)
{
    int id,p,cnt;
    while(val!=1)
    {
        id=d[val],p=pr[id],cnt=0;
        while(d[val]==id)val/=p,cnt++;
        pw[id].push_back(mp(index,cnt));
    }
}
inline void query(int L,int R,int val)
{
    int id,p,cnt;
    while(val!=1)
    {
        id=d[val],p=pr[id],cnt=0;
        while(d[val]==id)val/=p,cnt++;
        int tmp=(--upper(pw[id],R))->second;
        tmp-=(--lower(pw[id],L))->second;
        if(tmp<cnt)return (void)puts("No");
    }
    puts("Yes");
}

int main()
{
    for(int i=2,tmp;i<=100000;i++)
    {
        if(!d[i])pr[++cnt]=i,d[i]=cnt;
        for(int j=1;j<=cnt&&j<=d[i]&&(tmp=i*pr[j])<=100000;j++)
            d[tmp]=j;
    }
    for(int i=1;i<=cnt;i++)pw[i].push_back(mp(0,0));
    for(int T=read();T--;)
    {
        N=read(),M=read();
        for(int i=1;i<=cnt;i++)pw[i].resize(1);
        for(int i=1;i<=N;i++)work(read(),i);
        for(int i=1;i<=cnt;i++)for(int j=1;j<pw[i].size();j++)
            pw[i][j].second+=pw[i][j-1].second;
        for(int i=1,l,r,val;i<=M;i++)
            l=read(),r=read(),val=read(),query(l,r,val);
    }
    return 0;
}
/*
1
5 4
6 4 7 2 5
1 2 24
1 3 18
2 5 17
3 5 35

*/