/*��Ŀ����:�������������x0,y0(2<=x0<100000,2<=y0<=1000000),�������������������P,Q�ĸ�����ʹ��P,Q��x0Ϊ���Լ��,��y0Ϊ��С������.
  ��������������������x0,y0
  ����������������������п��ܵ������������ĸ���
  �������룺3 60
  ���������4*/

#include<cstdio>
#include<cmath>

using namespace std;

int gys(int b,int c)
{
    int a,r,i;
    if(b>c) {a=b;b=c;}
    else {a=c;b=b;}
    r=a%b;
    while(r!=0) {a=b;b=r;r=a%b;}
    return b;
} 

int main()
{
	int x0,y0,x,y,i,a,q=0;
	scanf("%d%d",&x0,&y0);
    x=x0*y0;
    y=sqrt(x);
    for(i=1;i<=y;i++)
    {
    	if(x%i==0)
    	{
    		a=x/i;
    		if(gys(a,i)==x0) q++;
    	}
    }
    printf("%d",q*2);
	return 0;
}
