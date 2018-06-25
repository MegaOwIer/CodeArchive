#include<bits/stdc++.h>
using namespace std;
const int MX=100005;
#define endl "\n"

int N,M,c1,c2,l[MX],e[MX],Q,v;

inline int queryl(int x1,int x2,int y1,int y2)
{
    int id=lower_bound(l+1,l+c1+1,y1)-l;
    if(l[id]<=y2)return y2-y1+x2-x1;
    if(id==1)return x2-x1+y2-y1+2*(l[id]-y2);
    return min(x2-x1+y2-y1+2*(l[id]-y2),x2-x1+y2-y1+2*(y1-l[id-1]));
}
inline int querye(int x1,int x2,int y1,int y2)
{
    int del=x2-x1;
    del=(del/v)+int(bool(del%v));
    int id=lower_bound(e+1,e+c2+1,y1)-e;
    if(e[id]<=y2)return y2-y1+del;
    if(id==1)return del+y2-y1+2*(e[id]-y2);
    return min(del+y2-y1+2*(e[id]-y2),del+y2-y1+2*(y1-e[id-1]));
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>M>>c1>>c2>>v;
    for(int i=1;i<=c1;i++)cin>>l[i];
    for(int i=1;i<=c2;i++)cin>>e[i];
    l[++c1]=e[++c2]=200000000;
    cin>>Q;
    for(int x1,x2,y1,y2,ans;Q--;)
    {
        cin>>x1>>y1>>x2>>y2;
        if(x1>x2)swap(x1,x2);
        if(y1>y2)swap(y1,y2);
        if(x1==x2)cout<<y2-y1<<endl;
        else cout<<min(queryl(x1,x2,y1,y2),querye(x1,x2,y1,y2))<<endl;
    }
    return 0;
}