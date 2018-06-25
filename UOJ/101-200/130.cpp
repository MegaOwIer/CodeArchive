#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;

struct node {int dep;  LL val;}now;
bool operator < (node a,node b)  {return a.val>b.val||(a.val==b.val&&a.dep>b.dep);}
priority_queue<node> q;
LL ans,n,k,a,sum;
int dep;

inline LL read()
{
    char ch=getchar();  LL ans=0LL;
    while(ch<'0'||ch>'9')  ch=getchar();
    while(ch>='0'&&ch<='9')  ans=ans*10+ch-'0',ch=getchar();
    return ans;
}

signed main()
{
    n=read(),k=read();
    for(int i=1;i<=n;i++)  a=read(),q.push((node){0,a});
    if((n-1)%(k-1))  for(int i=k-1-(n-1)%(k-1);i;i--)  q.push((node){0,0LL});
    while(q.size()!=1)
    {
        dep=0,sum=0LL;
        for(int i=1;i<=k;i++)
        {
            now=q.top(),q.pop();
            dep=max(dep,now.dep);
            sum+=now.val;
        }
        ans+=sum;
        q.push((node){dep+1,sum});
    }
    printf("%lld\n%lld",ans,q.top().dep);
    return 0;
}