#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MXN=205,MXM=10205;

class FastIO
{
private:
    static const int MXL=200005;
    FILE *I,*O;
    char IBF[MXL],*p1,*p2,OBF[MXL],*p3,*const ED,c;
    int tp,bf[22];
    char getchar(){return p1==p2?(p2=(p1=IBF)+fread(IBF,1,MXL,I)),p1==p2?EOF:*p1++:*p1++;}
    void putchar(char c){if(p3==ED)flush();*p3++=c;}
    void flush(){fwrite(OBF,1,p3-OBF,O),p3=OBF;}
public:
    FastIO(FILE *I,FILE *O):I(I),O(O),p1(IBF),p2(IBF),p3(OBF),ED(OBF+MXL){}
    ~FastIO(){flush();}
    template<typename T>void read(T& x)
    {
        x=0,c=getchar();
        while(!isdigit(c))c=getchar();
        while(isdigit(c))x=x*10+c-'0',c=getchar();
    }
    template<typename T>void write(T x)
    {
        bf[tp=1]='\n'-48;
        do bf[++tp]=x%10,x/=10;while(x);
        while(tp)putchar(48+bf[tp--]);
    }
    void puts(char *s)
    {
        int l=strlen(s);
        for(int i=0;i<l;i++)putchar(s[i]);
    }
}IO(stdin,stdout);

struct edge{int to,nxt,f;}e[MXM+MXN<<1];
int n,m,in[MXM],tot=1,head[MXN],cur[MXN],S,T,dep[MXN];
LL ans,flow[MXN];
queue<int> q;

inline void add(int u,int v,int f)
{
    e[++tot]=(edge){v,head[u],f},head[u]=tot;
    e[++tot]=(edge){u,head[v],0},head[v]=tot;
}
inline bool bfs()
{
    int now;
    memset(dep+1,-1,sizeof(int)*T);
    q.push(S),dep[S]=0;
    while(!q.empty())
    {
        now=q.front(),q.pop();
        for(int i=head[now];i;i=e[i].nxt)
            if(!~dep[e[i].to]&&e[i].f)
                dep[e[i].to]=dep[now]+1,q.push(e[i].to);
    }
    return ~dep[T];
}
int dfs(int u,int flow)
{
    int w,used=0;
    if(u==T)return flow;
    for(int &i=cur[u];i;i=e[i].nxt)
        if(dep[e[i].to]==dep[u]+1&&e[i].f)
        {
            w=dfs(e[i].to,min(e[i].f,flow-used));
            used+=w,e[i].f-=w,e[i^1].f+=w;
            if(used==flow)return flow;
        }
    return used;
}
bool Dinic()
{
    while(bfs())
        memcpy(cur+1,head+1,sizeof(int)*T),dfs(S,1e9);
    for(int i=head[S];i;i=e[i].nxt)
        if(e[i].f>0)return 0;
    return 1;
}

int main()
{
    IO.read(n),IO.read(m),T=(S=n+1)+1;
    for(int i=1,s,t,u,l;i<=m;i++)
    {
        IO.read(s),IO.read(t),IO.read(u),IO.read(l);
        in[i]=u,flow[s]-=u,flow[t]+=u;
        add(s,t,l-u);
    }
    for(int i=1;i<=n;i++)
        if(flow[i]>0)add(S,i,flow[i]),ans+=flow[i];
        else if(flow[i]<0)add(i,T,-flow[i]);
    if(Dinic())
    {
        IO.puts("YES\n");
        for(int i=1;i<=m;i++)IO.write(in[i]+e[i<<1|1].f);
    }
    else IO.puts("NO\n");
    return 0;
}