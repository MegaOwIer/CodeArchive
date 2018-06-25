#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int n,m,k,cnt,cnt2,left;
bool fl[25];

int main()
{
	while(scanf("%d%d%d",&n,&k,&m)==3&&n)
	{
		memset(fl,0,sizeof(fl));  cnt=0,cnt2=n+1,left=n;
		while(left)
		{
		    for(int i=1;i<=k;i++)
		    {
			    do  {cnt++;  if(cnt>n)  cnt-=n;}
			    while(fl[cnt]);
		    }
		    for(int i=1;i<=m;i++)
		    {
			    do  {cnt2--;  if(!cnt2)  cnt2+=n;}
			    while(fl[cnt2]);
		    }
		    fl[cnt2]=fl[cnt]=1;
		    if(cnt==cnt2)  {left--;  printf("%3d",cnt);}
		    else  {left-=2;  printf("%3d%3d",cnt,cnt2);}
		    printf(left?",":"\n");
		}
	}
	return 0;
}
