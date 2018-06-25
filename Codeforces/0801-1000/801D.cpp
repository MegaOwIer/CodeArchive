#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using LD=long double;
const int MX=1005;

int N;
LD ans=1e100;

struct Point
{
    LL x,y;
    Point(){}
    Point(LL x,LL y):x(x),y(y){}
    bool operator == (Point a){return x==a.x&&y==a.y;}
    Point operator - (Point a){return Point(x-a.x,y-a.y);}
    LL operator * (Point a){return x*a.x+y*a.y;}
    LD length(){return sqrtl(x*x+y*y);}
    Point identity(){return Point(y,-x);}
}P[MX];
istream& operator >> (istream& os,Point& a)
{
    os>>a.x>>a.y;
    return os;
}

inline LD query(Point& a,Point& b,Point& c)
{
    if(a==c||b==c)return 1e100;
    return fabsl((b-a).identity()*(c-a)/(b-a).length());
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=0;i<N;i++)cin>>P[i];
    P[N]=P[0];
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(i!=j)
    {
        LD tmp1=min(query(P[i],P[j],P[(i+1)%N]),query(P[i],P[j],P[(i-1+N)%N]));
        LD tmp2=min(query(P[i],P[j],P[(j+1)%N]),query(P[i],P[j],P[(j-i+N)%N]));
        ans=min(ans,min(tmp1,tmp2));
    }
    cout<<fixed<<setprecision(9)<<ans/2<<endl;
    return 0;
}
