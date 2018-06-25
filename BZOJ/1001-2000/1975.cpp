#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MXN=5005,MXM=200005;

class FastIO
{
private:
    static const int MXL=200000;
    char IBF[MXL],*p1,*p2,OBF[MXL],*p3,c;
    char *const ED;
    int tp,bf[22],cnt;
    FILE *I,*O;
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
        if(c=='.')
        {
            cnt=0,c=getchar();
            while(isdigit(c))x=x*10+c-'0',c=getchar(),cnt++;
            while(cnt--)x/=10;
        }
    }
    template<typename T>void write(T x)
    {
        bf[tp=1]='\n'-48;
        do bf[++tp]=x%10,x/=10;while(x);
        while(tp)putchar(48+bf[tp--]);
    }
}IO(stdin,stdout);
#define read(x) IO.read(x)
#define write(x) IO.write(x)

struct edge{int to,nxt;double w;}e[MXM];
struct node
{
    int id;
    double H,f;
    bool operator < (const node& a)const{return H>a.H;}
}tmp,q[MXM*10];
int n,m,tot,head[MXN],u[MXM],v[MXM],ans,top;
double E,w[MXM],dis[MXN];
bool vis[MXN];

inline void add(int u,int v,double w)
{
    e[++tot]=(edge){v,head[u],w},head[u]=tot;
}
void Dijkstra()
{
    typedef pair<double,int> sta;
    int now;
    priority_queue<sta,vector<sta>,greater<sta> > q;
    for(int i=1;i<n;i++)dis[i]=1e20;
    q.push(make_pair(0.0,n));
    while(!q.empty())
    {
        now=q.top().second,q.pop();
        if(vis[now])continue;
        vis[now]=1;
        for(int i=head[now];i;i=e[i].nxt)
            if(dis[e[i].to]>dis[now]+e[i].w)
            {
                dis[e[i].to]=dis[now]+e[i].w;
                q.push(make_pair(dis[e[i].to],e[i].to));
            }
    }
}
void Astar()
{
    q[++top]=node{1,dis[1],0};
    push_heap(q+1,q+1+top);
    while(top)
    {
        tmp=q[1],pop_heap(q+1,q+1+top),top--;
        if(tmp.id==n)
        {
            if(E<tmp.f)return;
            E-=tmp.f,ans++;
        }
        for(int i=head[tmp.id];i;i=e[i].nxt)
        {
            q[++top]=(node){e[i].to,tmp.f+e[i].w+dis[e[i].to],tmp.f+e[i].w};
            push_heap(q+1,q+1+top);
        }
    }
}

int main()
{
    read(n),read(m),read(E);
    for(int i=1;i<=m;i++)read(u[i]),read(v[i]),read(w[i]);
    for(int i=1;i<=m;i++)add(v[i],u[i],w[i]);
    Dijkstra();
    tot=0,memset(head+1,0,sizeof(int)*n);
    for(int i=1;i<=m;i++)add(u[i],v[i],w[i]);
    Astar();
    write(ans);
    return 0;
}
/*
4 6 15.0
1 2 1.5
2 1 1.5
1 3 3
2 3 1.5
3 4 1.5
1 4 1.5
*/