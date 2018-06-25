#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int N,m,k,p[505],fl[505],lt;
long long rt;

int main()
{
	scanf("%d",&N);
	while(N--)
	{
		memset(p,0,sizeof(p));  rt=0LL;  memset(fl,0,sizeof(fl));  lt=0;
		scanf("%d%d",&m,&k);
		for(int i=1;i<=m;i++)  {scanf("%d",p+i);  rt+=p[i];  lt=max(lt,p[i]);}
		int cnt;
		while(lt!=rt)
		{
			long long mid=(lt+rt)>>1;  int sum=0;  cnt=0;
			for(int i=1;i<=m;i++)
			{
				if(sum+p[i]>mid)  cnt++,sum=0;
				sum+=p[i];
			}
			cnt++;
			if(cnt<=k)  rt=mid;
			else  lt=mid+1;
		}
		cnt=k;
		long long sum=0LL;  fl[m+1]=cnt;
		for(int i=m;i;i--)
		{
			if(sum+p[i]>lt)  cnt--,sum=0;
			fl[i]=cnt;  sum+=p[i];
		}
		int f=fl[1]-1;
		for(int i=1;i<m;i++)
		{
			if(f&&fl[i]==fl[i+1])  {printf("%d / ",p[i]);  f--;  continue;}
			printf("%d ",p[i]);
			if(fl[i]!=fl[i+1])  printf("/ ");
		}
		printf("%d",p[m]);
		puts("");
	}
	return 0;
}
