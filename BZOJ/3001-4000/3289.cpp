#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=50005;

struct file {int val,pos;}a[maxn];
struct Ques {int l,r,id;LL ans;}q[maxn];
int n,block,pos[maxn],m,ord[maxn],c[maxn],cnt;
LL ans;

bool operator < (file a,file b) {return a.val<b.val;}
bool operator < (Ques a,Ques b) {return pos[a.l]<pos[b.l]||(pos[a.l]==pos[b.l]&&a.r<b.r);}
bool operator > (Ques a,Ques b) {return a.id<b.id;}
template<typename T>
inline void read(T& x){x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();}
inline int lowbit(int x) {return x&(-x);}
inline void insert(int id,int d) {for(;id<=n;id+=lowbit(id))c[id]+=d;}
inline LL sum(int id) {LL ans=0;for(;id;id-=lowbit(id))ans+=c[id];return ans;}
inline void updl(int id,bool pl)
{
	if(pl)  ++cnt,insert(ord[id],1),ans+=sum(ord[id]-1);
	else  --cnt,insert(ord[id],-1),ans-=sum(ord[id]-1);
}
inline void updr(int id,bool pl)
{
	if(pl)  ++cnt,insert(ord[id],1),ans+=cnt-sum(ord[id]);
	else  --cnt,insert(ord[id],-1),ans-=cnt-sum(ord[id]);
}
void solve()
{
	insert(ord[1],1),cnt=1;
	for(int i=1,l=1,r=1;i<=m;i++)
	{
		while(r<q[i].r)  updr(++r,1);
		while(l<q[i].l)  updl(l++,0);
		while(l>q[i].l)  updl(--l,1);
		while(r>q[i].r)  updr(r--,0);
		q[i].ans=ans;
	}
}

int main()
{
	read(n),block=sqrt(n),a[0].val=-1;
	for(int i=1;i<=n;i++)  read(a[i].val),a[i].pos=i;
	read(m);
	for(int i=1,l,r;i<=m;i++)  read(l),read(r),q[i]=(Ques){l,r,i};
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)  ord[a[i].pos]=(a[i].val==a[i-1].val)?ord[a[i-1].pos]:ord[a[i-1].pos]+1;
	for(int i=1;i<=n;i++)  pos[i]=i/block;
	sort(q+1,q+m+1);
	solve();
	sort(q+1,q+m+1,greater<Ques>());
	for(int i=1;i<=m;i++)  printf("%lld\n",q[i].ans);
	return 0;
}
