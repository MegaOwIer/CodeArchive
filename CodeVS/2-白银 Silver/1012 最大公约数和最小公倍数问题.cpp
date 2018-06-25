/*题目描述:输入二个正整数x0,y0(2<=x0<100000,2<=y0<=1000000),求出满足条件的正整数P,Q的个数，使得P,Q以x0为最大公约数,以y0为最小公倍数.
  输入描述：二个正整数x0,y0
  输出描述：满足条件的所有可能的两个正整数的个数
  样例输入：3 60
  样例输出：4*/

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
