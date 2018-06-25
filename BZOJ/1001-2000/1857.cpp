#include<bits/stdc++.h>
using namespace std;
const double eps=1e-5;

int Ax,Ay,Bx,By,Cx,Cy,Dx,Dy,P,Q,R;

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline double dis(double x,double y){return sqrt(x*x+y*y);}
double calc(double x,double y)
{
    double lx=Cx,ly=Cy,rx=Dx,ry=Dy;
    while(fabs(rx-lx)>eps||fabs(ry-ly)>eps)
    {
        double x1=lx+(rx-lx)/3,y1=ly+(ry-ly)/3;
        double x2=lx+(rx-lx)/3*2,y2=ly+(ry-ly)/3*2;
        double tmp1=dis(x-Ax,y-Ay)/P+dis(x-x1,y-y1)/R+dis(x1-Dx,y1-Dy)/Q;
        double tmp2=dis(x-Ax,y-Ay)/P+dis(x-x2,y-y2)/R+dis(x2-Dx,y2-Dy)/Q;
        if(tmp1>tmp2)lx=x1,ly=y1;
        else rx=x2,ry=y2;
    }
    return dis(x-Ax,y-Ay)/P+dis(lx-x,ly-y)/R+dis(lx-Dx,ly-Dy)/Q;
}

int main()
{
    Ax=read(),Ay=read(),Bx=read(),By=read();
    Cx=read(),Cy=read(),Dx=read(),Dy=read();
    P=read(),Q=read(),R=read();
    double lx=Ax,ly=Ay,rx=Bx,ry=By;
    while(fabs(rx-lx)>eps||fabs(ry-ly)>eps)
    {
        double x1=lx+(rx-lx)/3,y1=ly+(ry-ly)/3;
        double x2=lx+(rx-lx)/3*2,y2=ly+(ry-ly)/3*2;
        double tmp1=calc(x1,y1),tmp2=calc(x2,y2);
        if(tmp1>tmp2)lx=x1,ly=y1;
        else rx=x2,ry=y2;
    }
    printf("%.2lf\n",calc(lx,ly));
    return 0;
}
