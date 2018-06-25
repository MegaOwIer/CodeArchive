#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=40005;

int N,tot;
LL ans;
multiset<int> S;

struct Point
{
    int pos,val,type;
    bool operator < (const Point& a)const{return pos<a.pos;}
}P[MX<<1];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

int main()
{
    for(N=read();N--;)
    {
        int l=read(),r=read(),val=read();
        if(l==r)continue;
        ++tot,P[tot].pos=l,P[tot].val=val;
        ++tot,P[tot].pos=r,P[tot].val=val,P[tot].type=1;
    }
    sort(P+1,P+tot+1);
    for(int i=1;i<=tot;i++)
    {
        if(P[i].pos!=P[i-1].pos&&!S.empty())
            ans+=LL(P[i].pos-P[i-1].pos)*(*--S.end());
        if(P[i].type)S.erase(S.find(P[i].val));
        else S.insert(P[i].val);
    }
    printf("%lld\n",ans);
    return 0;
}