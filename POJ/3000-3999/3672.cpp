#include<cstdio>
#include<cctype>

int m,t,u,f,d,tot;
char ch;

int main()
{
	scanf("%d%d%d%d%d",&m,&t,&u,&f,&d);
	for(int i=1;i<=t;i++)
	{
		do ch=getchar();  while(!isalpha(ch));
		if(ch=='f')  tot+=f<<1;
		else  tot+=u+d;
		if(tot>m)  {printf("%d",i-1);  return 0;}
		if(i==t||tot==m)  {printf("%d",i);  return 0;}
	}
}
