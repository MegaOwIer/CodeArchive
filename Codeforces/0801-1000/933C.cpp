#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;

int n,tot;
struct point
{
    double x,y;
    point(double x=0,double y=0):x(x),y(y){}
    bool operator == (point a){return fabs(x-a.x)<eps&&fabs(y-a.y)<eps;}
    bool operator < (point a){return x<a.x||(x==a.x&&y<a.y);}
    point operator - (point a){return point(x-a.x,y-a.y);}
    point operator + (point a){return point(x+a.x,y+a.y);}
    point operator * (double a){return point(a*x,a*y);}
    double length(){return sqrt(x*x+y*y);}
    point cz(){return point(-y,x);}
};
struct line
{
    point a,b;
    line(point a,point b):a(a),b(b){}
    point iden(){return (b-a)*(1.0/(b-a).length());}
};
struct circle
{
    point o;
    int r;
}O[5];
vector<point> ans;
int cnt;

inline double dis(point a,point b){return (b-a).length();}
inline void check(int i,int j)
{
    if(dis(O[i].o,O[j].o)>O[i].r+O[j].r)return;
    if(dis(O[i].o,O[j].o)<abs(O[i].r-O[j].r))return;
    double DET=O[i].r*O[i].r-O[j].r*O[j].r;
    double d=dis(O[i].o,O[j].o);
    double t=DET/d;
    double a=(d+t)/2;
    point ident=line(O[i].o,O[j].o).iden();
    point C=O[i].o+ident*a;
    if(fabs(a-O[i].r)<eps)
    {
        ans.push_back(C);
        return;
    }
    double x=sqrt(O[i].r*O[i].r-a*a);
    ans.push_back(C+ident.cz()*x);
    ans.push_back(C-ident.cz()*x);
}
bool fl[5][5];
int xj(int i,int j)
{
    if(dis(O[i].o,O[j].o)>O[i].r+O[j].r)return 0;
    if(dis(O[i].o,O[j].o)<abs(O[i].r-O[j].r))return 0;
    return 1;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>O[i].o.x>>O[i].o.y>>O[i].r;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            fl[i][j]=fl[j][i]=xj(i,j);
    for(int i=1;i<=n;i++)
    {
        int tmp=0;
        for(int j=1;j<=n;j++)tmp+=fl[i][j];
        if(!tmp)cnt++;
    }
    if(cnt==n)return (cout<<n+1),0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            check(i,j);
    sort(ans.begin(),ans.end());
    ans.resize(unique(ans.begin(),ans.end())-ans.begin());
    tot=2-ans.size();
    for(auto i:ans)for(int j=1;j<=n;j++)
        if(fabs(O[j].r-dis(O[j].o,i))<eps)tot++;
    cout<<tot+cnt<<endl;
    return 0;
}