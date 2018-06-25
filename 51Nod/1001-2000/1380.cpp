#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
typedef long long LL;
const int maxn=100005;

struct node {LL dat,id;};
bool operator < (node a,node b)  {return a.dat>b.dat||(a.dat==b.dat&&a.id<b.id);}
LL ans,n,a[maxn],l[maxn],r[maxn];
set<node> q;

inline LL read()
{
    char ch=getchar();  LL ans=0LL,f=1LL;
    while(ch<'0'||ch>'9')  {if(ch=='-')  f=-1;  ch=getchar();}
    while(ch<='9'&&ch>='0')  ans=ans*10+ch-'0',ch=getchar();
    return ans*f;
}
inline void del(int id)
{
    l[r[id]]=l[id];
    r[l[id]]=r[id];
    q.erase((node){a[id],id});
}

int main()
{
    n=read();
    for(int i=0;i<n;i++)
    {
        a[i]=read();
        l[i]=(i-1+n)%n;
        r[i]=(i+1)%n;
        q.insert((node){a[i],i});
    }
    for(int i=1;i<=n/3;i++)
    {
        int id=q.begin()->id;
        LL a1=a[l[id]],b1=a[id],c1=a[r[id]];
        ans+=b1;
        del(l[id]);  del(r[id]);
        q.erase((node){a[id],id});
        a[id]=a1+c1-b1;
        q.insert((node){a[id],id});
    }
    printf("%lld",ans);
    return 0;
}
