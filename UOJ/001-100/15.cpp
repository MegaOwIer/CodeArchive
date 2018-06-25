#include<cstdio>
using namespace std;

int a[205],b[205],ta,tb,rd,sca,scb;

int main()
{
	scanf("%d%d%d",&rd,&ta,&tb);
	for(int i=1;i<=ta;i++)scanf("%d",a+i);
	for(int i=1;i<=tb;i++)scanf("%d",b+i);
	for(int i=1;i<=rd;i++)
	{
		int m=a[(i-1)%ta+1],n=b[(i-1)%tb+1];
		if(m==n)continue;
		switch(m)
		{
			case 0:if(n==2||n==3)sca++;else scb++;continue;
			case 1:if(n==0||n==3)sca++;else scb++;continue;
			case 2:if(n==1||n==4)sca++;else scb++;continue;
			case 3:if(n==2||n==4)sca++;else scb++;continue;
			case 4:if(n==0||n==1)sca++;else scb++;continue;
		}
    }
    cout<<sca<<' '<<scb;
    return 0;
}
