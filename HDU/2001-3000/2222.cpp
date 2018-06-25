#include<bits/stdc++.h>
using namespace std;

struct node{int son[26],fail,fl;}p[500005];
int n,T,lth,cnt,now;
char ch[55],ss[1000005];
queue<int> q;
bool vis[500005];

void insert(char* ch)
{
    now=0;
    for(int i=0;i<lth;i++)
    {
        if(!p[now].son[ch[i]-'a']) p[now].son[ch[i]-'a']=++cnt;
        now=p[now].son[ch[i]-'a'];
    }
    p[now].fl++;
}
void build_fail()
{
    q.push(0);
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(int i=0;i<26;i++)
        {
            if(p[now].son[i])
            {
                if(now)p[p[now].son[i]].fail=p[p[now].fail].son[i];
                q.push(p[now].son[i]);
            }
            else p[now].son[i]=p[p[now].fail].son[i];
        }
    }
}
void match()
{
    scanf("%s",ss),lth=strlen(ss);
    int now=0,ans=0;
    for(int i=0;i<lth;i++)
    {
        while(!p[now].son[ss[i]-'a']&&now)now=p[now].fail;
        if(!now)now=p[now].son[ss[i]-'a'];
        now=p[now].son[ss[i]-'a'];
        if(!vis[now]) for(int k=now;k;k=p[k].fail) ans+=p[k].fl,p[k].fl=0;
        vis[now]=1;
    }
    printf("%d\n",ans);
}

int main()
{
    for(scanf("%d",&T);T--;)
    {
        memset(p,0,sizeof(p)),cnt=0,memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",ch);
            lth=strlen(ch);
            insert(ch);
        }
        build_fail();
        match();
    }
    return 0;
}
