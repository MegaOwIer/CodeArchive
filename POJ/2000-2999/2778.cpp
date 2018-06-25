#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
typedef long long LL;
const int mod=100000;

struct martix {int n;LL a[105][105];}d,ans,c;
struct node {int son[4],fail,fl;}p[105];
int n,m,lth,cnt,sr,now,to;
LL tot;
char ch[15];
queue<int> q;

martix operator * (martix a,martix b)
{
    for(int i=0;i<=cnt;i++)for(int j=0;j<=cnt;j++)
    {
        c.a[i][j]=0;
        for(int k=0;k<=cnt;k++)c.a[i][j]+=a.a[i][k]*b.a[k][j];
        if(c.a[i][j]>=mod)c.a[i][j]%=mod;
    }
    return c;
}
inline int getnum(char c){if(c=='A')return 0;if(c=='G')return 1;if(c=='C')return 2;if(c=='T')return 3;}
inline void insert()
{
    scanf("%s",ch),lth=strlen(ch),now=0;
    for(int i=0;i<lth;i++)
    {
        sr=getnum(ch[i]);
        if(!p[now].son[sr])p[now].son[sr]=++cnt;
        now=p[now].son[sr];
    }
    p[now].fl++;
}
void build()
{
    q.push(0);
    while(!q.empty())
    {
        now=q.front(),q.pop();
        for(int i=0;i<4;i++)
        {
            if(p[now].son[i])
            {
                if(now)p[p[now].son[i]].fail=p[p[now].fail].son[i];
                q.push(p[now].son[i]);
            }
            else p[now].son[i]=p[p[now].fail].son[i];
        }
    }
    for(int i=0;i<=cnt;i++)
    {
        if(p[i].fl||p[p[i].fail].fl)continue;
        for(int j=0;j<4;j++)
        {
            to=p[i].son[j];
            if(p[to].fl||p[p[to].fail].fl)continue;
            d.a[i][to]++;
        }
    }
}

int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)insert();
    build();
    for(int i=0;i<=cnt;i++)ans.a[i][i]=1;
    while(n)
    {
        if(n&1)ans=ans*d;
        d=d*d;
        n>>=1;
    }
    for(int i=0;i<=cnt;i++)tot+=ans.a[0][i];
    printf("%lld",tot%mod);
    return 0;
}
