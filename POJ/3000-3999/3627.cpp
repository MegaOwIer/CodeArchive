#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,b,a[20001];
bool cmp(int a,int b)  {return a>b;}

int main()
{
	while(scanf("%d%d",&n,&b)!=EOF)
	{
		memset(a,0,sizeof(a));
	    for(int i=1;i<=n;i++)  scanf("%d",&a[i]);
	    sort(a+1,a+n+1,cmp);
	    int i=1;
	    while(b>0)  b-=a[i++];
	    printf("%d",i-1);
    }
	return 0;
}
