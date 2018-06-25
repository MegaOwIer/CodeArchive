#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=10007;

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

int N,M,son[6005][26],siz,fail[6005],dp[105][6005],ans;
char s[105];
bool fl[6005];

inline int Pow(int a,int b)
{
    int ans=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
inline void insert()
{
    scanf("%s",s+1);
    int lth=strlen(s+1),now=0;
    for(int i=1;i<=lth;i++)
    {
        if(!son[now][s[i]-'A'])son[now][s[i]-'A']=++siz;
        now=son[now][s[i]-'A'];
    }
    fl[now]=1;
}
inline void getfail()
{
    int now;
    queue<int> q;
    for(int i=0;i<26;i++)if(son[0][i])q.push(son[0][i]);
    while(!q.empty())
    {
        now=q.front(),q.pop();
        for(int i=0,j;i<26;i++)if(son[now][i])
        {
            j=fail[now];
            while(j&&!son[j][i])j=fail[j];
            j=son[j][i];
            fail[son[now][i]]=j;
            fl[son[now][i]]|=fl[fail[son[now][i]]];
            q.push(son[now][i]);
        }
    }
}

int main()
{
    read(N),read(M);
    ans=Pow(26,M);
    while(N--)insert();
    getfail();
    dp[0][0]=1;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<=siz;j++)if(dp[i][j]&&!fl[j])
        {
            for(int k=0,l;k<26;k++)
            {
                l=j;
                while(l&&!son[l][k])l=fail[l];
                l=son[l][k];
                if(!fl[l])(dp[i+1][l]+=dp[i][j])%=mod;
            }
        }
    }
    for(int i=0;i<=siz;i++)(ans+=mod-dp[M][i])%=mod;
    write(ans);
    return 0;
}