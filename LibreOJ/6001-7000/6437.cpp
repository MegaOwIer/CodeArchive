#include<bits/stdc++.h>
using namespace std;
typedef long double LD;
const LD eps=1e-6,pi=acosl(-1);

int N,M;
LD ans,alpha;
vector<LD> args;

int read();

struct Point
{
    LD x,y;

    Point(LD x=0,LD y=0):x(x),y(y){}
    Point operator + (Point a){return Point(x+a.x,y+a.y);}
    Point operator - (Point a){return Point(x-a.x,y-a.y);}
    LD operator & (Point a){return x*a.y-y*a.x;}
    LD operator * (Point a){return x*a.x+y*a.y;}
    Point operator * (LD a){return Point(x*a,y*a);}
    Point operator / (LD a){return Point(x/a,y/a);}
    LD operator == (Point a){return fabsl(x-a.x)<eps&&fabsl(y-a.y)<eps;}
    void read()
    {
        LD a=::read(),b=::read();
        x=a*cosl(alpha)-b*sinl(alpha);
        y=a*sinl(alpha)+b*cosl(alpha);
    }
    Point normal(){return Point(y,-x);}
    LD length(){return sqrtl(x*x+y*y);}
    Point identity()
    {
        LD tmp=length();
        return Point(x/tmp,y/tmp);
    }
}Poly[505],P[205],O(0,0);

struct Line
{
    Point x,y;

    Line(){}
    Line(Point x,Point y):x(x),y(y){}
    Point direction(){return y-x;}
    Point normal(){return (y-x).normal();}
    bool check_on_segment(Point a)
    {
        if(a==x||a==y)return true;
        return fabsl((x-a)&(y-a))<eps&&(x-a)*(y-a)<0;
    }
    void work(LD R)
    {
        LD dis=fabsl((O-x)*normal())/(y-x).length();
        if(dis>R)return;
        LD d=sqrt(R*R-dis*dis);
        Point M=x+(y-x).identity()*((y-x).identity()*(O-x)),P;
        P=M+direction().identity()*d;
        if(check_on_segment(P))args.push_back(atan2l(P.y,P.x));
        P=M-direction().identity()*d;
        if(check_on_segment(P))args.push_back(atan2l(P.y,P.x));
    }
}Side[505];

inline int read()
{
    int x=0,c=getchar(),f=1;
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x*f;
}
bool check_in_polygon(LD x,LD y)
{
    int tot=0;
    Point P(x,y);
    for(int i=0;i<M;i++)
        if(Side[i].check_on_segment(P))return false;
    for(int i=0;i<M;i++)
    {
        Line tmp=Side[i];
        if((tmp.x.x-x)*(tmp.y.x-x)>0)continue;
        LD yy=tmp.x.y+(tmp.y.y-tmp.x.y)/(tmp.y.x-tmp.x.x)*(x-tmp.x.x);
        if(yy>y)continue;
        tot^=1;
    }
    return tot;
}
LD getans(LD x,LD y)
{
    if(fabsl(x)<eps&&fabsl(y)<eps)return check_in_polygon(0,0)*pi*2;
    LD R=sqrtl(x*x+y*y);
    args.clear();
    for(int i=0;i<M;i++)Side[i].work(R);
    args.push_back(-pi),args.push_back(pi);
    sort(args.begin(),args.end());
    args.erase(unique(args.begin(),args.end()),args.end());
    LD ans=0;
    for(int i=1;i<args.size();i++)
    {
        LD tmp=(args[i-1]+args[i])/2;
        if(check_in_polygon(R*cos(tmp),R*sin(tmp)))ans+=args[i]-args[i-1];
    }
    return ans;
}

int main()
{
    srand(time(0));
    for(int i=0;i<100;i++)rand();
    alpha=(LD)rand()/RAND_MAX*pi*2;
    N=read(),M=read();
    for(int i=1;i<=N;i++)P[i].read();
    for(int i=1;i<=M;i++)Poly[i].read();
    Poly[0]=Poly[M];
    for(int i=0;i<M;i++)Side[i]=Line(Poly[i],Poly[i+1]);
    for(int i=1;i<=N;i++)ans+=getans(P[i].x,P[i].y);
    printf("%.5Lf\n",ans/pi/2);
    return 0;
}
