#include<bits/stdc++.h>
using namespace std;
const int MX=1000005;

int N,K,a[MX];

inline void read(int& x)
{
    static char c;
    c=getchar(),x=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
    read(N),read(K);
    for(int i=1,u,v;i<=K;i++)read(u),read(v),a[u]++,a[v+1]--;
    for(int i=1;i<=N;i++)a[i]+=a[i-1];
    nth_element(a+1,a+N/2+1,a+N+1);
    printf("%d\n",a[N+1>>1]);
    return 0;
}