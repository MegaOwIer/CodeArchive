#include<cstdio>
#include<algorithm>
using namespace std;
#define goon {ans++;  continue;}

int n,k,ans,fa[150005],b1,b2,b3,c1,c2,c3;

int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=3*n;i++)  fa[i]=i;
    for(int i=1,a,b,c;i<=k;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(b>n||c>n)  goon
        b1=find(b),b2=find(b+n),b3=find(b+n*2);
        c1=find(c),c2=find(c+n),c3=find(c+n*2);
        if(a==1)
        {
            if(b1==c2||b1==c3)  goon
            fa[b1]=c1,fa[b2]=c2,fa[b3]=c3;
        }
        else
        {
            if(b==c||b1==c1||b1==c2)  goon
            fa[c1]=b2,fa[c2]=b3,fa[c3]=b1;
        }
    }
    printf("%d",ans);
    return 0;
}
