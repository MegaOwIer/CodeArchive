#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

char now[205];
int m,ans;

int main()
{
	scanf("%d",&m);
	while(m--)
	{
		ans=0;
		scanf("%s",now);
		int lth=strlen(now);
		for(int i=0;i<lth;i++)  now[lth+i]=now[i];
		for(int i=1;i<lth;i++)  
		{
			bool fl=0;
		    for(int j=0;j<lth;j++)
			{
			    if(now[i+j]<now[ans+j])  {ans=i;  fl=1;  break;}
			    if(now[i+j]>now[ans+j])  break;
			}
		    if(fl)  continue;
		}
		for(int i=0;i<lth;i++)  printf("%c",now[ans+i]);
		printf("\n");   
	}
	return 0;
}
