#include<cstdio>
#include<algorithm>
using namespace std;

int n,q,mx,mn;
struct node
{
	int l,r,h,s;
}po[200000];
void build(int l,int r,int st)
{
	po[st].l=l;po[st].r=r;
	if(l==r)  {scanf("%d",&po[st].h);  po[st].s=po[st].h;  return;}
	int mid=(l+r)/2;
	build(l,mid,2*st);
	build(mid+1,r,2*st+1);
}
void init(int st)
{
	if(po[st].l!=po[st].r)
	{
	    init(2*st);
	    init(2*st+1);
	}
	if(po[st].l==po[st].r)  return;
	po[st].h=max(po[st*2].h,po[st*2+1].h);
	po[st].s=min(po[st*2].s,po[st*2+1].s);
}
void ask(int l,int r,int st)
{
	if(po[st].l==l&&po[st].r==r)  {mx=max(mx,po[st].h);  mn=min(mn,po[st].s);  return;}
	int mid=(po[st].l+po[st].r)/2;
	if(mid>=r)  ask(l,r,st*2);
	else  if(mid<l)  ask(l,r,st*2+1);
	      else  {ask(l,mid,st*2);  ask(mid+1,r,st*2+1);}
}

int main()
{
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		build(1,n,1);
		init(1);
		for(int i=1,c,d;i<=q;i++)  {scanf("%d%d",&c,&d);  mx=0;  mn=1000001;  
		ask(c,d,1);  printf("%d\n",mx-mn);}
	}
	return 0;
}
