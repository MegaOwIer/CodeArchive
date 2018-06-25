#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=200005;

class FastIO
{
private:
	static const int MXL=200000;
	FILE *I,*O;
	char IBF[MXL],*p1,*p2,OBF[MXL],*p3,c,*const ED;
	int tp,bf[22];
	char getchar(){return p1==p2?(p2=(p1=IBF)+fread(IBF,1,MXL,I)),p1==p2?EOF:*p1++:*p1++;}
	void putchar(char c){if(p3==ED)flush();*p3++=c;}
	void flush(){fwrite(OBF,1,p3-OBF,O),p3=OBF;}
public:
	FastIO(FILE *I,FILE *O):I(I),O(O),p1(IBF),p2(IBF),p3(OBF),ED(MXL+OBF){}
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
#define read(x) IO.read(x)
#define write(x) IO.write(x)

struct Node
{
	int id;
	LL val;
	bool operator < (const Node& a)const{return val>a.val;}
}a[MX];
int N,tp,cnt,siz[MX],mxsz[MX],stk[MX],top,fa[MX];
vector<pair<int,LL> > G[MX];
LL w,p[MX],q[MX],lim[MX],dis[MX],dp[MX];
bool used[MX];
#define to first
#define val second

void dfs1(int u){for(auto i:G[u])dis[i.to]=dis[u]+i.val,dfs1(i.to);}
void getG(int u,int totsiz,int& O)
{
	siz[u]=1,mxsz[u]=0;
	for(auto i:G[u])if(!used[i.to])
		getG(i.to,totsiz,O),siz[u]+=siz[i.to],mxsz[u]=max(mxsz[u],siz[i.to]);
	mxsz[u]=max(mxsz[u],totsiz-siz[u]);
	if(mxsz[u]<=totsiz/2)O=u;
}
void dfs2(int u)
{
	a[++cnt]=(Node){u,dis[u]-lim[u]};
	for(auto i:G[u])if(!used[i.to])dfs2(i.to);
}
inline double getK(int x,int y){return (double)(dp[x]-dp[y])/(dis[x]-dis[y]);}
void solve(int root,int totsiz)
{
	int rt,l,r,mid;
	if(totsiz==1)return;
	getG(root,totsiz,rt);
	for(auto i:G[rt])used[i.to]=1;
	solve(root,totsiz-siz[rt]+1);
	cnt=0;
	for(auto i:G[rt])dfs2(i.to);
	sort(a+1,a+cnt+1);
	for(int i=1,x,j=rt,top=0;i<=cnt;i++)
	{
		x=a[i].id;
		while(j!=fa[root]&&dis[j]>=dis[x]-lim[x])
		{
			while(top>1&&getK(j,stk[top])>=getK(stk[top],stk[top-1]))top--;
			stk[++top]=j,j=fa[j];
		}
		if(!top)continue;
		l=1,r=top;
		while(l<r)
		{
			mid=l+r+1>>1;
			if(getK(stk[mid],stk[mid-1])>=p[x])l=mid;
			else r=mid-1;
		}
		dp[x]=min(dp[x],dp[stk[l]]+p[x]*(dis[x]-dis[stk[l]])+q[x]);
	}
	for(auto i:G[rt])solve(i.to,siz[i.to]);
}

int main()
{
	read(N),read(tp),dp[0]=-1e18;
	for(int i=2;i<=N;i++)
	{
		read(fa[i]),read(w);
		G[fa[i]].push_back(make_pair(i,w));
		read(p[i]),read(q[i]),read(lim[i]);
		dp[i]=1e18;
	}
	dfs1(1),solve(1,N);
	for(int i=2;i<=N;i++)write(dp[i]);
	return 0;
}