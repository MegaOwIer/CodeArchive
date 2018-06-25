#include<bits/stdc++.h>
using namespace std;
const int MX=10005;

class FastIO
{
private:
    static const int MXL=200000;
    FILE *I;
    char IBF[MXL],*p1,*p2,c;
    int f;
    char getchar(){return p1==p2?(p2=(p1=IBF)+fread(IBF,1,MXL,I)),p1==p2?EOF:*p1++:*p1++;}
public:
    FastIO(FILE *I):I(I),p1(IBF),p2(IBF){}
    template<typename T>void read(T& x)
    {
        x=0,c=getchar(),f=0;
        while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
        while(isdigit(c))x=x*10+c-'0',c=getchar();
        if(f)x=-x;
    }
}IO(stdin);
#define read(x) IO.read(x)

int n,x[MX],y[MX],w[MX];
double T=10000,ansx,ansy,dx,dy,dis;

int main()
{
    read(n);
    for(int i=1;i<=n;i++)
    {
        read(x[i]),read(y[i]),read(w[i]);
        ansx+=(double)x[i]*w[i],ansy+=(double)y[i]*w[i];
    }
    ansx/=n,ansy/=n;
    while(T>1e-9)
    {
        dx=dy=0;
        for(int i=1;i<=n;i++)
        {
            dis=sqrt((ansx-x[i])*(ansx-x[i])+(ansy-y[i])*(ansy-y[i]));
            dx+=(x[i]-ansx)*w[i]/dis,dy+=(y[i]-ansy)*w[i]/dis;
        }
        ansx+=dx*T,ansy+=dy*T;
        T*=0.97;
    }
    printf("%.3lf %.3lf",ansx,ansy);
	return 0;
}