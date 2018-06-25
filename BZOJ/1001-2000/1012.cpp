#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;

int m,cnt,pos[200005];
LL d,q,ans;
char c;
struct node {LL mx;int l,r;}p[800000];

void build(int l,int r,int id)
{
	p[id].l=l,p[id].r=r,p[id].mx=0;
	if(l==r)  {pos[l]=id;  return;}
	int mid=(l+r)>>1;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
}
void insert(int l,LL w)
{
	int now=pos[cnt];
	p[now].mx=w;
	while(now)
	{
		now>>=1;
		if(p[now].mx>=w)  break;
		p[now].mx=w;
	}
}
LL ask(int l,int r,int id)
{
	if(l==r)  return p[pos[l]].mx;
	if(p[id].l==l&&p[id].r==r)  return p[id].mx;
	int mid=(p[id].l+p[id].r)>>1;
	if(mid>=r)  return ask(l,r,id<<1);
	else  if(mid<l)  return ask(l,r,id<<1|1);
	      else  return max(ask(l,mid,id<<1),ask(mid+1,r,id<<1|1));
}

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d%lld",&m,&d);
	build(1,m,1);
	while(m--)
	{
		getchar();  c=getchar();
		scanf("%lld",&q);
		if(c=='A')  insert(++cnt,(q+ans)%d);
		else  {ans=ask(cnt-q+1,cnt,1);  printf("%lld\n",ans);}
	}
	return 0;
}
