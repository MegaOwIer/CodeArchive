#include<bits/stdc++.h>
using namespace std;
typedef long double LD;
const double eps=1e-8;
#define endl "\n"

int T,R;

struct Vector
{
    LD x,y,z;

    Vector(LD x=0,LD y=0,LD z=0):x(x),y(y),z(z){}
    Vector operator + (Vector a){return Vector(x+a.x,y+a.y,z+a.z);}
    Vector operator - (Vector a){return Vector(x-a.x,y-a.y,z-a.z);}
    Vector operator * (Vector a){return Vector(y*a.z-z*a.y,z*a.x-x*a.z,x*a.y-y*a.x);}
    Vector operator * (LD a){return Vector(x*a,y*a,z*a);}
    LD operator & (Vector a){return x*a.x+y*a.y+z*a.z;}
    LD length(){return sqrtl(x*x+y*y+z*z);}
}v;
typedef Vector Point;
Point P,Q,O;

istream& operator >> (istream& os,Vector& a)
{
    os>>a.x>>a.y>>a.z;
    return os;
}
bool check(LD val)
{
    Point M=Q+v*val;
    Vector nor=(O-P)*(M-P)*(M-P);
    return fabsl((O-P)&nor)>=nor.length()*R;
}

int main()
{
    ios::sync_with_stdio(0);
    setiosflags(ios::fixed);
    cout.precision(12);
    cin>>T;
    while(T--)
    {
        cin>>P>>Q>>v>>O>>R;
        double l=0,r=1e9,mid;
        check(0);
        while(r-l>eps)
        {
            mid=(l+r)/2;
            if(check(mid))r=mid;
            else l=mid;
        }
        cout<<l<<endl;
    }
    return 0;
}
