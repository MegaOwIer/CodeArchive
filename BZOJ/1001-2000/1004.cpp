#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
    char c;
    int top,bf[22];
    template<typename T>inline void read(T& x)
    {
        x=0,c=getchar();
        while(!isdigit(c))c=getchar();
        while(isdigit(c))x=x*10+c-'0',c=getchar();
    }
    template<typename T>inline void write(T x)
    {
        top=0;
        do bf[++top]=x%10,x/=10;while(x);
        while(top)putchar(48+bf[top--]);
        putchar('\n');
    }
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
 
int Sr,Sg,Sb,n,m,mod,cur[65][65],siz[65],f[25][25][25];
LL ans;
char vis[65];
 
inline LL Pow(LL a,int b)
{
    LL ans=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
inline int calc(int u)
{
    int cnt=0;
    memset(siz+1,0,sizeof(int)*n);
    memset(vis+1,0,sizeof(char)*n);
    for(int i=1,p;i<=n;i++)
    {
        if(vis[i])continue;
        p=cur[u][i],cnt++;
        while(!vis[p])vis[p]=1,siz[cnt]++,p=cur[u][p];
    }
    memset(f,0,sizeof(f));
    f[0][0][0]=1;
    for(int i=1;i<=cnt;i++)
        for(int j=Sr;~j;j--)for(int k=Sb;~k;k--)for(int l=Sg;~l;l--)
        {
            if(j>=siz[i])f[j][k][l]+=f[j-siz[i]][k][l];
            if(k>=siz[i])f[j][k][l]+=f[j][k-siz[i]][l];
            if(l>=siz[i])f[j][k][l]+=f[j][k][l-siz[i]];
            f[j][k][l]%=mod;
        }
    return f[Sr][Sb][Sg];
}
 
int main()
{
    read(Sr),read(Sb),read(Sg),read(m),read(mod);
    n=Sr+Sg+Sb;
    for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)read(cur[i][j]);
    m++;
    for(int i=1;i<=n;i++)cur[m][i]=i;
    LL ans=0;
    for(int i=1;i<=m;i++)ans=(ans+calc(i))%mod;
    write(ans*Pow(m,mod-2)%mod);
    return 0;
}