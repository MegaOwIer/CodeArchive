#include<bits/stdc++.h>
using namespace std;

int x,y,z,limit,ans;

inline int Digit(int x)
{
    int re=0;
    while(x)++re,x>>=1;
    return re;
}
int Count(int x)
{
    int re=0;
    while(x)x^=x&-x,++re;
    return re;
}
int main()
{
    scanf("%d%d%d",&x,&y,&z);
    limit=max(max(Digit(x),Digit(y)),Digit(z));
    x=Count(x),y=Count(y),z=Count(z);
    if(x<y)swap(x,y);
    if(!z)ans=(x+y)?-1:0;
    else if(!y)ans=(x==z)?(1<<x)-1:-1;
    else if(z<=y)ans=((1<<x)-1)+((1<<z)-1|((1<<y-z)-1<<x));
    else if(z<=x) ans=((1<<x)-1)+((1<<y)-1<<z-y);
    else if(z<=x+y) ans=((1<<x)-1<<z-x)+((1<<z-x)-1|((1<<x+y-z)-1<<z+z-x-y));
    else ans=-1;
    if(Digit(ans)>limit) ans=-1;
    printf("%d",ans);
    return 0;
}
