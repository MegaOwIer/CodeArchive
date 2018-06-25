#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=200005,maxm=10005;
#define lowbit(x) x&(-x)

struct oper{int k,t,id,x,y,f;}d[maxn],tmp[maxn];
int f,s,n,opt,id,x,y,w,z,tot,ans[maxm],tr[2000005],p1,p2;
char c;

inline bool operator < (oper a,oper b){return a.x<b.x||(a.x==b.x&&a.y<b.y)||(a.x==b.x&&a.y==b.y&&a.k<b.k);}
inline void read(int& x)
{
	x=0,f=1,c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();x*=f;
}
inline void add(int x,int val){for(;x<=n;x+=lowbit(x))tr[x]+=val;}
inline int sum(int x){int ans=0;for(;x;x-=lowbit(x))ans+=tr[x];return ans;}
inline void cdq(int l,int r)
{
	if(l==r)return;
	int mid=l+r>>1;
	for(int i=l;i<=r;i++)
		if(d[i].k==1&&d[i].t<=mid) add(d[i].y,d[i].f);
		else if(d[i].k==2&&d[i].t>mid) ans[d[i].id]+=sum(d[i].y)*d[i].f;
	for(int i=l;i<=r;i++) if(d[i].k==1&&d[i].t<=mid) add(d[i].y,-d[i].f);
	p1=l,p2=mid;
	for(int i=l;i<=r;i++)
		if(d[i].t<=mid) tmp[p1++]=d[i];
		else tmp[++p2]=d[i];
	for(int i=l;i<=r;i++)d[i]=tmp[i];
	cdq(l,mid),cdq(mid+1,r);
}

int main()
{
	read(s),read(n);
	while(1)
	{
		read(opt);
		if(opt==3)break;
		if(opt==1)read(x),read(y),read(w),d[++tot]=(oper){1,tot,0,x,y,w};
		if(opt==2)
		{
			read(x),read(y),read(z),read(w),id++;
			d[++tot]=(oper){2,tot,id,z,w,1};
			d[++tot]=(oper){2,tot,id,x-1,y-1,1};
			d[++tot]=(oper){2,tot,id,x-1,w,-1};
			d[++tot]=(oper){2,tot,id,z,y-1,-1};
		}
	}
	sort(d+1,d+tot+1),cdq(1,tot);
	for(int i=1;i<=id;i++)printf("%d\n",ans[i]);
	return 0;
}
