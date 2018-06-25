#include<cstdio>
#include<cmath>
using namespace std;

struct toy
{
    int x;
    char s[2000];
}p[100005];
int n,m;
int ans=1;

int main()
{
    scanf("%d%d",&n,&m); 
    for(int i=1;i<=n;i++)  scanf("%d%s",&p[i].x,p[i].s);
    for(int i=1,a,b;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        if((!a&&!p[ans].x)||(a&&p[ans].x))  ans-=b;
        else  ans+=b;
        if(ans>n)  ans-=n;
        if(ans<1)  ans+=n;
    }
    printf("%s",p[ans].s);
    return 0;
}
