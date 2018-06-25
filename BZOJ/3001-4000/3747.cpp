#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	char c;
	int top,bf[22];
	template<typename T>inline void read(T& x)
	{
		c=getchar(),x=0;
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do bf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+bf[top--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
typedef long long LL;
const int maxn=1000005;
#define tag(i) Pool[i][0]
#define mx(i) Pool[i][1]

int n,m,f[maxn],w[maxn],lst[maxn],nxt[maxn];
LL Pool[maxn<<2][2],ans;

inline void pushdown(int id)
{
	if(!tag(id))return;
	tag(id<<1)+=tag(id),tag(id<<1|1)+=tag(id);
	mx(id<<1)+=tag(id),mx(id<<1|1)+=tag(id);
	tag(id)=0;
}
inline void insert(int id,int l,int r,int val,int L=1,int R=n)
{
	if(L==l&&r==R){tag(id)+=val,mx(id)+=val;return;}
	pushdown(id);
	int mid=L+R>>1;
	if(r<=mid)insert(id<<1,l,r,val,L,mid);
	else if(l>mid)insert(id<<1|1,l,r,val,mid+1,R);
	else insert(id<<1,l,mid,val,L,mid),insert(id<<1|1,mid+1,r,val,mid+1,R);
	mx(id)=max(mx(id<<1),mx(id<<1|1));
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)read(f[i]);
	for(int i=1;i<=m;i++)read(w[i]);
	for(int i=n;i;i--)nxt[i]=lst[f[i]],lst[f[i]]=i;
	for(int i=1;i<=m;i++)if(lst[i])
	{
		if(!nxt[lst[i]])insert(1,lst[i],n,w[i]);
		else insert(1,lst[i],nxt[lst[i]]-1,w[i]);
	}
	for(int i=1,tmp;i<=n;i++)
	{
		ans=max(ans,mx(1));
		tmp=nxt[i];
		if(tmp)
		{
			insert(1,i,tmp-1,-w[f[i]]);
			if(nxt[tmp])insert(1,tmp,nxt[tmp]-1,w[f[i]]);
			else insert(1,tmp,n,w[f[i]]);
		}
		else insert(1,i,n,-w[f[i]]);
	}
	write(ans);
	return 0;
}
