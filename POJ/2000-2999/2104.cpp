#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
const int maxn=100005;

struct node {int l,r,ls,rs,val,cnt;}p[maxn*20];
struct data {int val,pos,ord;}d[maxn];
int n,m,root[maxn],cnt,f;

bool operator < (data a,data b){return a.val<b.val;}
bool operator > (data a,data b){return a.pos<b.pos;}
template<typename T>
inline void read(T& x){x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();x*=f;}
inline void pushup(int id){p[id].cnt=p[p[id].ls].cnt+p[p[id].rs].cnt;}
inline void build(int l,int r,int& id)
{
    id=cnt++,p[id].val=0,p[id].l=l,p[id].r=r;
    if(l==r)return;
    int mid=l+r>>1;
    build(l,mid,p[id].ls),build(mid+1,r,p[id].rs);
}
inline void insert(int now,int pos,int val,int& id)
{
    id=cnt++,p[id]=p[now];
    if(p[id].l==p[id].r){p[id].cnt++,p[id].val=val;return;}
    int mid=p[id].l+p[id].r>>1;
    if(mid>=pos)insert(p[now].ls,pos,val,p[id].ls);
    else insert(p[now].rs,pos,val,p[id].rs);
    pushup(id);
}
inline int ask(int id1,int id2,int k)
{
    if(p[id1].l==p[id1].r)return p[id2].val;
    int del=p[p[id2].ls].cnt-p[p[id1].ls].cnt;
    if(del>=k)return ask(p[id1].ls,p[id2].ls,k);
    else return ask(p[id1].rs,p[id2].rs,k-del);
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        cnt=0;
        for(int i=1;i<=n;i++)read(d[i].val),d[i].pos=i;
        sort(d+1,d+n+1);
        for(int i=1;i<=n;i++)d[i].ord=i;
        sort(d+1,d+n+1,greater<data>());
        build(1,n,root[0]);
        for(int i=1;i<=n;i++)insert(root[i-1],d[i].ord,d[i].val,root[i]);
        for(int i=1,a,b,c;i<=m;i++)
        {
            read(a),read(b),read(c);
            printf("%d\n",ask(root[a-1],root[b],c));
        }
    }
    return 0;
}
