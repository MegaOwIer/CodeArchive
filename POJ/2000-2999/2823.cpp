#include<cstdio>
using namespace std;
const int maxn=10000005;

struct data {int pos,val;}a[maxn],que[maxn];
int n,m,l=1,r=1;

inline void read(int& x){x=0;int f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();x*=f;}


int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)read(a[i].val),a[i].pos=i;
	que[1]=a[1];
	for(int i=2;i<=m;i++)  {while(que[r].val>a[i].val&&r)r--;  que[++r]=a[i];}  
	printf("%d ",que[1].val);
	for(int i=m+1;i<=n;i++)
	{
		while(que[l].pos<i-m+1&&l<=r)l++;
		while(l<=r&&que[r].val>a[i].val)r--;
		que[++r]=a[i];
		printf("%d ",que[l].val);
	}
	putchar('\n');
	que[l=r=1]=a[1];
	for(int i=2;i<=m;i++)  {while(que[r].val<a[i].val&&r)r--;  que[++r]=a[i];}  
	printf("%d ",que[1].val);
	for(int i=m+1;i<=n;i++)
	{
		while(que[l].pos<i-m+1&&l<=r)l++;
		while(l<=r&&que[r].val<a[i].val)r--;
		que[++r]=a[i];
		printf("%d ",que[l].val);
	}
	return 0;
}
