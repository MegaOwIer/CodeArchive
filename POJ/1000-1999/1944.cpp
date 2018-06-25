#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,pr,num,pa[10005][3],ans=0x7fffffff,lr[5005],rr[5005],fl[5005];
void build(int,int,int);
void insert(int,int,int);
int ask(int,int,int);

int main()
{
	scanf("%d%d",&n,&pr);
	build(1,n,1);
	for(int i=1,a,b;i<=pr;i++)  {scanf("%d%d",&a,&b);  pa[i][1]=min(a,b);  pa[i][2]=max(a,b);}
	for(int i=1;i<=n;i++)
	{
		memset(fl,0,sizeof(fl));
		for(int j=1;j<=pr;j++)
		{
			if(pa[j][1]<=i&&pa[j][2]>i)  {insert(pa[j][2],n,1);  
			insert(1,pa[j][1]-1,1);}
			else  insert(pa[j][1],pa[j][2]-1,1);
		}
		ans=min(ans,ask(1,n,1));
	}
	printf("%d",ans);
	return 0;
}
void build(int l,int r,int i)
{
	lr[i]=l,rr[i]=r;
	if(l==r)  return;
	int mid=(l+r)>>1;
	build(l,mid,i<<1);  build(mid+1,r,i<<1|1);
}
void insert(int l,int r,int i)
{
	if(l>r||fl[i])  return;
	if(lr[i]==l&&rr[i]==r)  {fl[i]=1;  return;}
	int mid=(lr[i]+rr[i])>>1;
	if(mid>=r)  insert(l,r,i<<1);
	else  if(mid<l)  insert(l,r,i<<1|1);
	      else  {insert(l,mid,i<<1);  insert(mid+1,r,i<<1|1);}
}
int ask(int l,int r,int i)
{
	if(fl[i])  return r-l+1;
	if(l==r)  return 0;
	int mid=(l+r)>>1;
	return ask(l,mid,i<<1)+ask(mid+1,r,i<<1|1);
}
