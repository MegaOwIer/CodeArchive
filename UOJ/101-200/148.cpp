#include<bits/stdc++.h>
using namespace std;
const int maxn=50005;

int n,m,l,a[maxn],mn,mx,mid;
char c;

inline void read(int& x)
{
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline bool check(int val)
{
    for(int cnt=0,i=1,lst=0;i<=n+1;i++)
    {
        if(a[i]<val+lst)cnt++;
        else lst=a[i];
        if(cnt>m)return 0;
    }
    return 1;
}

int main()
{
    read(l),read(n),read(m),a[n+1]=l;
    for(int i=1;i<=n;i++)read(a[i]);
    mn=1,mx=l;
    while(mn<=mx)
    {
        mid=mn+mx>>1;
        if(check(mid))mn=mid+1;
        else mx=mid-1;
    }
    printf("%d",mn-1);
    return 0;
}
