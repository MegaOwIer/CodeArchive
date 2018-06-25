#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
#define clear(a,b) memset(a,b,sizeof(a))

struct edge {int to,next,w;}s[100001];
int head[1001],n,m,x,tot,dis1[1001],ans[1001],dis,now;
bool vis[1001];
queue<int> q;

void add(int a,int b,int w)
{
    s[++tot].to=b,s[tot].next=head[a],head[a]=tot,s[tot].w=w;
}

int spfa(int u)
{
    q.push(u);  clear(dis1,0x7f);
    dis1[u]=0;  clear(vis,0);
    while(!q.empty())
    {
        now=q.front();  q.pop();  vis[now]=0;
        for(int i=head[now];i;i=s[i].next)
        {
            dis=dis1[now]+s[i].w;
            if(dis1[s[i].to]>dis)
            {
                dis1[s[i].to]=dis;
                if(!vis[s[i].to])  {q.push(s[i].to);  vis[s[i].to]=1;}
            }
        }
    }
    return dis1[x];
}
void spfa()
{
    q.push(x);  clear(ans,0x3f);  ans[x]=0;
    while(!q.empty())
    {
        now=q.front();  q.pop();  vis[now]=0;
        for(int i=head[now];i;i=s[i].next)
        {
            dis=ans[now]+s[i].w;
            if(ans[s[i].to]>dis)
            {
                ans[s[i].to]=dis;
                if(!vis[s[i].to])  {q.push(s[i].to);  vis[s[i].to]=1;}
            }
        }
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&x);
    for(int i=1,a,b,c;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    spfa();
    for(int i=1;i<=n;i++)  if(i!=x)  ans[i]+=spfa(i);
    sort(ans+1,ans+n+1);
    printf("%d",ans[n]);
    return 0;
}
