#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;

namespace FastIO
{
    char c;
    int bf[22],top;
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

int n,mx,id,p[maxn],q[maxn],ans;
char s[maxn];
set<int> t;
set<int>::iterator tmp;

inline bool cmp (int a,int b){return a-p[a]<b-p[b];}

int main()
{
    read(n);
    scanf("%s",s+1);
    s[0]='#',mx=id=0;
    for(int i=1;i<=n;i++)
    {
        if(mx>=i)p[i]=min(p[id*2-i],mx-i);
        else p[i]=0;
        while(s[i+p[i]+1]==s[i-p[i]])p[i]++;
        if(p[i]+i>mx)id=i,mx=i+p[i];
    }
    for(int i=1;i<=n;i++)q[i]=i;
    sort(q+1,q+n+1,cmp);
    for(int i=1,now=1;i<=n;i++)
    {
        while(now<=n&&q[now]-p[q[now]]<=i)
            t.insert(q[now++]);
        tmp=t.upper_bound(i+p[i]/2);
        if(tmp!=t.begin())ans=max(ans,((*(--tmp)-i))<<2);
    }
    write(ans);
    return 0;
}