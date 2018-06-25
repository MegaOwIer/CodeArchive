#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=300005;

char Pool[200000000],*pointer=Pool;
inline void* operator new (size_t siz){return (pointer+=siz)-siz;}
inline void operator delete(void*){}

class FastIO
{
private:
    static const int MXL=200000;
    char IBF[MXL],*p1,*p2,OBF[MXL],*p3,*const ED,c;
    int bf[22],tp;
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
    }
    template<typename T>void write(T x)
    {
        bf[tp=1]='\n'-48;
        do bf[++tp]=x%10,x/=10;while(x);
        while(tp)putchar(48+bf[tp--]);
    }
}IO(stdin,stdout);
#define read(X) IO.read(X)
#define write(x) IO.write(x)

struct edge{int to,nxt;}e[MX<<1];
int n,q,dep[MX],siz[MX],head[MX],tot,id,k;
struct Segment
{
	Segment *l,*r;
	int siz;
	LL sum;
	Segment():l(NULL),r(NULL),siz(0),sum(0){}
	void maintain()
	{
		sum=siz=0;
		if(l)sum+=l->sum,siz+=l->siz;
		if(r)sum+=r->sum,siz+=r->siz;
	}
}*rt[MX];
LL ans[MX];
vector<pair<int,int> > Ques[MX];

inline void add(int u,int v)
{
	e[++tot]=(edge){v,head[u]},head[u]=tot;
	e[++tot]=(edge){u,head[v]},head[v]=tot;
}
void insert(Segment* &o,int pos,int L=1,int R=n)
{
	if(!o)o=new Segment;
	if(L==R)
	{
		o->siz++,o->sum+=pos;
		return;
	}
	int mid=L+R>>1;
	if(pos<=mid)insert(o->l,pos,L,mid);
	else insert(o->r,pos,mid+1,R);
	o->maintain();
}
void merge(Segment* &o,Segment *p)
{
	if(!o){o=p;return;}
	if(!p)return;
	o->siz+=p->siz,o->sum+=p->sum;
	merge(o->l,p->l),merge(o->r,p->r);
}
LL getsiz(Segment *o,int l,int r,int L=1,int R=n)
{
	if(!o)return 0;
	if(L==l&&r==R)return o->siz;
	int mid=L+R>>1;
	if(r<=mid)return getsiz(o->l,l,r,L,mid);
	else if(l>mid)return getsiz(o->r,l,r,mid+1,R);
	else return getsiz(o->l,l,mid,L,mid)+getsiz(o->r,mid+1,r,mid+1,R);
}
LL getsum(Segment *o,int l,int r,int L=1,int R=n)
{
	if(!o)return 0;
	if(L==l&&r==R)return o->sum;
	int mid=L+R>>1;
	if(r<=mid)return getsum(o->l,l,r,L,mid);
	else if(l>mid)return getsum(o->r,l,r,mid+1,R);
	else return getsum(o->l,l,mid,L,mid)+getsum(o->r,mid+1,r,mid+1,R);
}
void dfs(int u,int f)
{
	siz[u]=1;
	for(int i=head[u];i;i=e[i].nxt)if(e[i].to!=f)
	{
		dep[e[i].to]=dep[u]+1,dfs(e[i].to,u);
		siz[u]+=siz[e[i].to];
		merge(rt[u],rt[e[i].to]);
	}
	insert(rt[u],dep[u]);
	for(vector<pair<int,int> >::iterator i=Ques[u].begin();i!=Ques[u].end();i++)
	{
		id=i->first,k=i->second;
		ans[id]=(LL)(siz[u]-1)*min(k,dep[u]-1);
		int l=dep[u]+1,r=dep[u]+k+1;
		if(l<=n)
		{
			if(r>=n)ans[id]+=getsum(rt[u],l,n)-getsiz(rt[u],l,n)*l;
			else ans[id]+=getsum(rt[u],l,r)-getsiz(rt[u],l,r)*l+getsiz(rt[u],r+1,n)*k;
		}
	}
}

int main()
{
	read(n),read(q),dep[1]=1;
	for(int i=1,u,v;i<n;i++)read(u),read(v),add(u,v);
	for(int i=1,u,v;i<=q;i++)read(u),read(v),Ques[u].push_back(make_pair(i,v));
	dfs(1,-1);
	for(int i=1;i<=q;i++)write(ans[i]);
	return 0;
}
