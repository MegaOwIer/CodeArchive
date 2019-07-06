#include<bits/stdc++.h>
using namespace std;

int T,N,K,ans;
vector<int> a,b;

inline int read()
{
    static int x,c;
    c=getchar(),x=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

int main()
{
    T=read();
    while(T--)
    {
        N=read(),K=read();
        a.clear(),b.clear(),ans=0;
        for(int i=1;i<=N;i++)(i&1?a:b).push_back(read());
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end());
        for(int i:a)ans+=i;
        for(int i:b)ans-=i;
        for(int i=0;i<b.size()&&i<K&&a[i]>b[i];i++)ans-=2*(a[i]-b[i]);
        puts(ans>=0?"NO":"YES");
    }
    return 0;
}
