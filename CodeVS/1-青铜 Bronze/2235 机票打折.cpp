/*题目描述:输入机票原价（3到4位的正整数），再输入机票打折率（小数点后最多一位）。编程计算打折后机票的实际价格（计算结果要四舍五入到十位）
  输入描述:输入只有一行两个数（两数间用一个空格分隔），第一个为整数，表示机票原价，第二个整数或实数（如是实数，小数点后最多1位数字）表示打折率。
  输出描述:输出只有一行一个正整数，表示打折后的机票价格。
  样例输入1：888  7
  样例输出1：620
  样例输入2：1255  7 
  样例输出2：880
  数据范围及提示：原机票价格大于100小于9999，打折率大于1小于9.9。*/ 

#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;
int main()
{
	int x,y,b;
	double a;
	scanf("%d%lf",&x,&a);
	y=x*(a/10.0);
	b=y%10 ;
	if(b>=0&&b<=4)  y=y/10*10;
	else y=y/10*10+10;
	
	printf("%d",y);
	
	return 0;
}
