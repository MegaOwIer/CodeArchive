#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL d;

inline int read()
{
    int x=0,c=getchar(),f=1;
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x*f;
}

inline bool chk(LL x,LL y){return x%d==0&&y%d==0;}

int main()
{
    for(int T=read();T--;)
    {
        LL a=read(),b=read(),x=read(),y=read();
        d=__gcd(a,b)*2;
        if(chk(x,y)||chk(x+a,y+b)||chk(x+b,y+a)||chk(x+a+b,y+b+a))puts("Y");
        else puts("N");
    }
    return 0;
}
