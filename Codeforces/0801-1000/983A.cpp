#include<bits/stdc++.h>
using namespace std;
using LL=long long;
#define endl "\n"

int N;
LL a,b,q,d;

inline LL read()
{
    static int c;
    static LL x;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

int main()
{
    scanf("%d",&N);
    while(N--)
    {
        a=read(),b=read(),q=read();
        b/=__gcd(a,b);
        while((d=__gcd(q,b))^1)
            while(b%d==0)b/=d;
        puts(b==1?"Finite":"Infinite");
    }
    return 0;
}