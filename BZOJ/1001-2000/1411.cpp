#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=100005;

int N,a[MX],tmp[MX];
LL T,x;

template<typename T>inline T read()
{
    T x=0;
    char c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

int main()
{
    N=read<int>(),T=read<LL>();
    for(int i=1;i<=N;i++)a[i]=read<int>()-1;
    x=T>>1;
    for(LL i=1,k;i<=x;i<<=1)if(i&x)
    {
        memcpy(tmp+1,a+1,sizeof(int)*N);
        k=i%N;
        int l=(N-k)%N+1,r=k+1;
        for(int j=1;j<=N;j++,l++,r++)
        {
            if(l>N)l=1;
            if(r>N)r=1;
            a[j]=tmp[l]^tmp[r];
        }
    }
    a[0]=a[N],a[N+1]=a[1];
    if(T&1)for(int i=1;i<=N;i++)printf("0 %d%c",(a[i]^a[i+1])+1," \n"[i==N]);
    else for(int i=1;i<=N;i++)printf("%d 0%c",a[i]+1," \n"[i==N]);
    return 0;
}