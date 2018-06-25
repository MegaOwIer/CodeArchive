#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1005;

struct frac{int a,b;double c;}p[maxn];
int n,k;
double mx,mn,aa,bb,mid,ans;
char ch;

inline bool operator < (frac a,frac b) {return a.c<b.c;}
inline void read(int& x)
{
    x=0,ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
}
inline void check(double u)
{
    for(int i=1;i<=n;i++)p[i].c=p[i].a-p[i].b*u;
    sort(p+1,p+n+1),aa=bb=0;
    for(int i=n;i>k;i--)aa+=p[i].a,bb+=p[i].b;
    ans=aa/bb;
    if(ans>=u)mn=u;
    else mx=u;
}

int main()
{
    while(~scanf("%d%d",&n,&k)&&(n||k))
    {
        for(int i=1;i<=n;i++)read(p[i].a);
        for(int i=1;i<=n;i++)read(p[i].b);
        mn=0,mx=1;
        while(mx-mn>1e-6)mid=(mx+mn)/2,check(mid);
        printf("%d\n",(int)(0.5+100*mn));
    }
    return 0;
}
