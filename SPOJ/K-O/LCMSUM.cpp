#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1000005;
 
int T,n,cnt,prime[78500],pw[maxn];
LL g[maxn];
char c;
bool vis[maxn];
 
inline void read(int& x)
{
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-48,c=getchar();
}
 
int main()
{
    g[1]=1,pw[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        if(!vis[i])prime[++cnt]=i,g[i]=1+1LL*i*(i-1),pw[i]=i;
        for(int j=1;j<=cnt&&(LL)prime[j]*i<=1000000;j++)
        {
            vis[prime[j]*i]=1;
            if(i%prime[j]==0)
            {
                g[prime[j]*i]=g[i]+g[i/pw[i]]*(prime[j]-1)*pw[i]*pw[i]*prime[j];
                pw[prime[j]*i]=pw[i]*prime[j];
                break;
            }
            g[prime[j]*i]=g[prime[j]]*g[i];
            pw[prime[j]*i]=prime[j];
        }
    }
    read(T);
    while(T--)read(n),printf("%lld\n",(g[n]+1)*n/2);
    return 0;
}
