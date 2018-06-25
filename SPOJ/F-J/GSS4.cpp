#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=100005;

int N,nxt[MX],M,cnt;
LL a[MX],tr[MX],tmp;

template<typename T>inline void read(T& x)
{
    static char c;
    c=getchar(),x=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline int find(int x){return x==nxt[x]?x:nxt[x]=find(nxt[x]);}
inline void add(int u,LL v){for(;u<=N;u+=u&-u)tr[u]+=v;}
inline LL ask(int u){LL ans=0;for(;u;u-=u&-u)ans+=tr[u];return ans;}

int main()
{
    while(~scanf("%d",&N))
    {
        cnt++;
        printf("Case #%d:\n",cnt);
        memset(tr+1,0,sizeof(LL)*N);
        for(int i=1;i<=N;i++)
            read(a[i]),nxt[i]=(a[i]>1?i:i+1),add(i,a[i]);
        nxt[N+1]=N+1;
        read(M);
        for(int i=1,op,l,r;i<=M;i++)
        {
            read(op),read(l),read(r);
            if(l>r)swap(l,r);
            if(op)printf("%lld\n",ask(r)-ask(l-1));
            else for(int j=find(l);j<=r;j=find(j+1))
            {
                tmp=a[j]-floor(sqrt(a[j]));
                a[j]-=tmp,add(j,-tmp);
                if(a[j]==1)nxt[j]=j+1;
            }
        }
        putchar('\n');
    }
    return 0;
}