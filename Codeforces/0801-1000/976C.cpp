#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MX=300005;

int N;

struct Seg{int l,r,id;}s[MX];

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=1,u,v;i<=N;i++)
    {
        cin>>u>>v;
        u=u*2,v=v*2-1;
        s[i]=(Seg){u,v,i};
    }
    sort(s+1,s+N+1,[](const Seg& a,const Seg& b){return a.r==b.r?a.l<b.l:a.r<b.r;});
    for(int i=2;i<=N;i++)if(s[i].r==s[i-1].r)
        return printf("%d %d\n",s[i].id,s[i-1].id),0;
    sort(s+1,s+N+1,[](const Seg& a,const Seg& b){return a.l==b.l?a.r<b.r:a.l<b.l;});
    for(int i=2;i<=N;i++)if(s[i].l==s[i-1].l)
        return printf("%d %d\n",s[i-1].id,s[i].id),0;
    for(int i=2;i<=N;i++)if(s[i].r<s[i-1].r)
        return printf("%d %d\n",s[i].id,s[i-1].id),0;
    puts("-1 -1");
    return 0;
}