
/*题目描述:给出两个浮点数，请你判断这两个浮点数是否相等 
  输入描述:输入仅一行，包含两个浮点数 
  输出描述:输出仅一行，如果相等则输出yes，否则输出no。 
  样例输入:2.980000001 2.9800000000001 
  样例输出:yes 
  数据范围及提示:我们一般认为两个浮点数相等，当且仅当他们之间的误差不超过1e-8。*/ 

#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
int main()
{
	double x,y,z;
	scanf("%lf%lf",&x,&y);
	z=x-y;
	if(z>=0)
	  if(z<=1e-8)
	   printf("yes");
	  else 
	   printf("no");
	else
	  if(z>=-1e-8)
	   printf("yes");
	  else
	   printf("no");
	return 0;
  }
