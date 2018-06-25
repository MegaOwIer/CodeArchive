#include<bits/stdc++.h>
using namespace std;
const int MM=5005,mod=1000000007;

int N,M,Q,id[MM],pos[MM],pw[1005];
char s[MM];

struct Bitset
{
    unsigned bit[32];
    int val,id;
    bool operator > (const Bitset& a)const
    {
        for(int i=31;i>=0;i--)
            if(bit[i]!=a.bit[i])return bit[i]>a.bit[i];
        return false;
    }
    void set(int u){bit[u>>5]|=1<<(u&31);}
}b[MM];

inline void update(int& a,int b){a+=b;if(a>=mod)a-=mod;}

int main()
{
    scanf("%d%d%d",&N,&M,&Q),gets(s);
    pw[0]=1;
    for(int i=1;i<=N;i++)pw[i]=(pw[i-1]<<1)%mod;
    for(int i=0;i<N;i++)
    {
        gets(s+1);
        for(int j=1;j<=M;j++)if(s[j]=='1')
            b[j].set(i),update(b[j].val,pw[i]);
    }
    for(int i=1;i<=M;i++)b[i].id=i;
    sort(b+1,b+M+1,greater<Bitset>());
    for(int i=1;i<=M;i++)pos[b[i].id]=i;
    b[0].val=pw[N];
    while(Q--)
    {
        gets(s+1);
        int mn=M+1,mx=0;
        for(int i=1;i<=M;i++)s[i]=='0'?mn=min(mn,pos[i]):mx=max(mx,pos[i]);
        if(mx>mn)puts("0");
        else printf("%d\n",(b[mx].val-b[mn].val+mod)%mod);
    }
    return 0;
}