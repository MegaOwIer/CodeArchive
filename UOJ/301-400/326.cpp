#include<bits/stdc++.h>
#include"triangles.h"
using namespace std;
const int MX=4003;
const double pi=acos(-1.0);
#define nxt(i) (i==tot-1?0:i+1)

int tot;
struct Point
{
    int x,y,col,id;
    double arg;
    Point(){}
    Point(int x,int y,int c,int i):x(x),y(y),col(c),id(i),arg(atan2(y,x)){}
    bool operator < (const Point& a)const{return arg<a.arg;}
    double operator - (const Point& a){return atan2(y-a.y,x-a.x);}
}p[MX<<1],O;

inline double getArg(int u,int v)
{
    double ans=(O-p[v])-(p[u]-p[v]);
    return ans<0?ans+pi*2:ans;
}

void check_triangles(int N,int M,int *rx,int *ry,int *bx,int *by,int **ans)
{
    for(int i=0;i<N;i++)p[i]=Point(rx[i],ry[i],1,i);
    for(int i=0;i<M;i++)p[N+i]=Point(bx[i],by[i],0,i);
    tot=N+M,sort(p,p+tot);
    for(int i=0,x,y;i<tot;i++)
    {
        x=p[i].id;
        if(p[i].col)
        {
            double arg=1e30,tmp,mxarg=p[i].arg+pi;
            for(int j=nxt(i),id=-1;j!=i&&p[j].arg<mxarg;j=nxt(j))
            {
                tmp=getArg(j,i);
                if(p[j].col)
                {
                    y=p[j].id;
                    if(x>y)ans[y][x]=(tmp>arg?id:-1);
                    else ans[x][y]=(tmp>arg?id:-1);
                }
                else if(tmp<arg)arg=tmp,id=p[j].id;
            }
        }
        p[i].arg+=2*pi;
    }
}