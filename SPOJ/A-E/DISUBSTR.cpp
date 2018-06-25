#include<bits/stdc++.h>
using namespace std;
const int MX=1005;

int T,N,M,SA[MX],height[MX],rk[MX],tp[MX],ans;
char s[MX];

inline void RadixSort()
{
    static int tax[MX];
    memset(tax+1,0,sizeof(int)*M);
    for(int i=1;i<=N;i++)tax[rk[tp[i]]]++;
    for(int i=2;i<=M;i++)tax[i]+=tax[i-1];
    for(int i=N;i;i--)SA[tax[rk[tp[i]]]--]=tp[i];
}
inline bool cmp(int a,int b,int c){return tp[a]==tp[b]&&tp[a+c]==tp[b+c];}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1),N=strlen(s+1),M=127;
        for(int i=1;i<=N;i++)rk[i]=s[i],tp[i]=i;
        RadixSort();
        for(int w=1,p=0;w<=N;w<<=1,M=p,p=0)
        {
            for(int i=N-w+1;i<=N;i++)tp[++p]=i;
            for(int i=1;i<=N;i++)if(SA[i]>w)tp[++p]=SA[i]-w;
            RadixSort(),memcpy(tp+1,rk+1,sizeof(int)*N);
            rk[SA[1]]=p=1;
            for(int i=2;i<=N;i++)rk[SA[i]]=cmp(SA[i],SA[i-1],w)?p:++p;
        }
        for(int i=1,j,k=0;i<=N;height[rk[i++]]=k)
            for(k=k?k-1:0,j=SA[rk[i]-1];s[i+k]==s[j+k];++k);
        ans=0;
        for(int i=1;i<=N;i++)ans+=N-i+1-height[i];
        printf("%d\n",ans);
    }
    return 0;
}