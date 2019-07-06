#include<bits/stdc++.h>
using namespace std;

int T,N,ans;

inline int read()
{
    static int x,c;
    c=getchar(),x=0;
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
        while(N--)ans^=read()*2;
        printf("%d\n",ans);
    }
    return 0;
}
