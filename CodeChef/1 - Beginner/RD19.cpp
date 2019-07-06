#include<bits/stdc++.h>
using namespace std;

int T,N,ans;

inline int read()
{
    static int x,c;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

int main()
{
    T=read();
    while(T--)
    {
        N=read(),ans=0;
        while(N--)ans=__gcd(ans,read());
        puts(ans==1?"0":"-1");
    }
    return 0;
}
