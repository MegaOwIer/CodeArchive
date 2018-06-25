#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int h1=89,h2=133;
bool ha1[20050000],ha2[20050000];
struct cpu
{
	int x,y,t;
	cpu(int x,int y,int t):x(max(x,y)),y(min(x,y)),t(t) {}
	cpu() {}
}que[10000000];
int now,t=1,n;
void add(cpu);

int main()
{
	scanf("%d",&n);
	que[1]=cpu(1,0,0);  ha1[h1]=ha2[h2]=1;
	if(n==1)  return puts("0"),0;
	while(++now)
	{
		int a=que[now].x,b=que[now].y,c=que[now].t;
		if(2*a==n||2*b==n||a+b==n||abs(a-b)==n)  {printf("%d",c+1);  return 0;}
		if(a<=n)
		{
			add(cpu(a,2*a,c+1));
		    add(cpu(b,2*a,c+1));
	    	add(cpu(a,2*b,c+1));
		    add(cpu(b,2*b,c+1));
	    }
		if(a+b<=2*n)
		{
			add(cpu(a,a+b,c+1));
		    add(cpu(b,a+b,c+1));
	    }
		if(a-b)
		{
			add(cpu(a,abs(a-b),c+1));
		    add(cpu(b,abs(a-b),c+1));
	    }
	}
	return 0;
}
void add(cpu u)
{
	if(u.y>=200)  return;
	if(!ha1[u.x*h1+u.y]&&!ha2[u.x*h1+u.y])  que[++t]=u;
	ha1[u.x*h1+u.y]=ha2[u.x*h1+u.y]=1;
}
