#include<bits/stdc++.h>
using namespace std;

using LL=long long;
using Point=tuple<int,int,int>;
const int MX=100005;

int N,ans[MX];
Point P[MX];

inline LL calc(LL x,LL y){return x*x+y*y;}

int main()
{
    srand(time(0));
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=1,x,y;i<=N;i++)
    {
        cin>>x>>y;
        P[i]=make_tuple(i,x,y);
    }
    LL x,y;
#define get(d) get<d>(P[i])
    do
    {
        random_shuffle(P+1,P+N+1);
        x=0,y=0;
        for(int i=1;i<=N;i++)
            if(calc(x+get(1),y+get(2))<=calc(x-get(1),y-get(2)))
                x+=get(1),y+=get(2),ans[get(0)]=1;
            else x-=get(1),y-=get(2),ans[get(0)]=-1;
    }
    while(calc(x,y)>LL(2.25e12));
#undef get
    for(int i=1;i<=N;i++)cout<<ans[i]<<' ';
    return 0;
}