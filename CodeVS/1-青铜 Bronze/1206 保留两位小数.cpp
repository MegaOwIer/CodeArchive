/*题目描述:保留两位小数输出一个浮点数。
  输入描述:一个浮点数。double范围内。 
  输出描述:保留两位小数输出
  样例输入:11
  样例输出:11.00
  数据范围及提示:使用 printf("%.2lf",a);使用double类型，不要使用float,real,extended类型。*/ 

#include<cstdio>
#include<cstring>

using namespace std;
int main()
{
	double x;
	scanf("%lf",&x);
	printf("%.2lf",x);

	return 0;
	
} 
