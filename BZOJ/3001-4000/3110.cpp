#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=50001;
#define lsn p[id].son[0]
#define rsn p[id].son[1]

struct node{int son[2];LL sum,tag;}p[maxn*360];
int n,m,root[maxn<<1],lson[maxn<<1],rson[maxn<<1],l,r,cnt,mid,cnt0,cntn,kkk,opt[maxn],a[maxn],b[maxn],f;
LL c[maxn],val[maxn],src;
char ch;

template<typename T>
inline void read(T& x)
{
	x=0,ch=getchar(),f=1;
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;
}
inline void pushdown(int l,int r,int id)
{
	if(!p[id].tag||l==r)return;
	if(!lsn)lsn=++cntn;
	if(!rsn)rsn=++cntn;
	p[lsn].tag+=p[id].tag,p[rsn].tag+=p[id].tag;
	int mid=l+r>>1;
	p[lsn].sum+=p[id].tag*(mid-l+1),p[rsn].sum+=p[id].tag*(r-mid);
	p[id].tag=0;
}
inline void pushup(int id){p[id].sum=p[lsn].sum+p[rsn].sum;}
inline void insert(int L,int R,int l,int r,int& id)
{
	if(!id)id=++cntn;
	if(L==l&&R==r){p[id].tag++,p[id].sum+=r-l+1;return;}
	pushdown(L,R,id);
	int mid=L+R>>1;
	if(mid>=r)insert(L,mid,l,r,lsn);
	else if(l>mid)insert(mid+1,R,l,r,rsn);
	else insert(L,mid,l,mid,lsn),insert(mid+1,R,mid+1,r,rsn);
	pushup(id);
}
inline LL sum(int L,int R,int l,int r,int id)
{
	if(!id)return 0;
	if(L==l&&R==r)return p[id].sum;
	pushdown(L,R,id);
	int mid=L+R>>1;
	if(mid>=r)return sum(L,mid,l,r,lsn);
	else if(l>mid)return sum(mid+1,R,l,r,rsn);
	else return sum(L,mid,l,mid,lsn)+sum(mid+1,R,mid+1,r,rsn);
}

int main()
{
	read(n),read(m),root[cnt=1]=cntn=1;
	for(int i=1;i<=m;i++)
	{
		read(opt[i]),read(a[i]),read(b[i]),read(c[i]);
		if(opt[i]&1)val[++cnt0]=c[i];
	}
	sort(val+1,val+cnt0+1),cnt0=unique(val+1,val+cnt0+1)-val-1;
	for(int i=1;i<=m;i++)if(opt[i]&1)c[i]=lower_bound(val+1,val+cnt0+1,c[i])-val;
	for(int i=1;i<=m;i++)
	{
		if(opt[i]&1)
		{
			l=1,r=cnt0,kkk=1;
			while(1)
			{
				insert(1,n,a[i],b[i],root[kkk]);
				if(l==r)break;
				mid=l+r>>1;
				if(mid>=c[i])
				{
					if(!lson[kkk])lson[kkk]=++cnt,root[cnt]=++cntn;
					r=mid,kkk=lson[kkk];
				}
				else
				{
					if(!rson[kkk])rson[kkk]=++cnt,root[cnt]=++cntn;
					l=mid+1,kkk=rson[kkk];
				}
			}
		}
		else
		{
			l=1,r=cnt0,kkk=1;
			while(l!=r)
			{
				mid=l+r>>1;
				src=sum(1,n,a[i],b[i],root[rson[kkk]]);
				if(src<c[i])r=mid,kkk=lson[kkk],c[i]-=src;
				else l=1+mid,kkk=rson[kkk];
			}
			printf("%lld\n",val[l]);
		}
	}
	return 0;
}
