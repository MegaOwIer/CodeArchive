#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int top,buf[22]; 
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do buf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+buf[top--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
const int maxn=10005;

struct Ques{int ps,vl,rk,ty,id,cur,del;}q[maxn<<2];
int n,m,a[maxn],mx,cnt,tot,ans[maxn],mid,tr[maxn];
char op;

inline void upd(int x,int v){for(;x<=n;x+=x&-x)tr[x]+=v;}
inline int sum(int x){int ans=0;for(;x;x-=x&-x)ans+=tr[x];return ans;}
inline bool cmp(Ques& Q)
{
	if(Q.ty==3)
	{
		if(Q.cur+Q.del>=Q.rk)return 1;
		Q.cur+=Q.del,Q.del=0;
		return 0;
	}
	return Q.vl<=mid;
}
inline void solve(int l,int r,int L,int R)
{
	if(l>r)return;
	if(L==R)
	{
		for(int i=l;i<=r;i++)if(q[i].ty==3)ans[q[i].id]=L;
		return;
	}
	mid=L+R>>1;
	for(int i=l;i<=r;i++)
	{
		if(q[i].ty==1&&q[i].vl<=mid)upd(q[i].ps,1);
		if(q[i].ty==2&&q[i].vl<=mid)upd(q[i].ps,-1);
		if(q[i].ty==3)q[i].del=sum(q[i].vl)-sum(q[i].ps-1);
	}
	for(int i=l;i<=r;i++)
	{
		if(q[i].ty==1&&q[i].vl<=mid)upd(q[i].ps,-1);
		if(q[i].ty==2&&q[i].vl<=mid)upd(q[i].ps,1);
	}
	int div=stable_partition(q+l,q+r+1,cmp)-q-1;
	solve(l,div,L,mid),solve(div+1,r,mid+1,R);
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)
	{
		read(a[i]),mx=max(mx,a[i]);
		q[++cnt]=(Ques){i,a[i],0,1,0,0,0};
	}
	for(int i=1,l,r,k;i<=m;i++)
	{
		do op=getchar();while(op!='Q'&&op!='C');
		read(l),read(r);
		if(op=='Q')read(k),q[++cnt]=(Ques){l,r,k,3,++tot,0,0};
		else
		{
			q[++cnt]=(Ques){l,a[l],0,2,0,0,0};
			q[++cnt]=(Ques){l,r,0,1,0,0,0};
			a[l]=r,mx=max(mx,r);
		}
	}
	solve(1,cnt,0,mx);
	for(int i=1;i<=tot;i++)write(ans[i]);
	return 0;
}
