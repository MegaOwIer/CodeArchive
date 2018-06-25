#include<cstdio>
using namespace std;
const int mod=10007;

int n,ans;
char ch;

void read()
{
    ch=getchar();
    while(ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        while(n>=mod)  n-=mod;
        ch=getchar();
    }
}

int main()
{
    read();
    ans=n*(n+1)%mod;  ans=ans*(n+2)%mod;  ans=ans*1668%mod;
    printf("%d",ans);
    return 0;
}
