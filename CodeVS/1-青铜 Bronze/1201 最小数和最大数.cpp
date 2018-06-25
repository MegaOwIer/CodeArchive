/*题目描述:输入n个数，n<=100，找到其中最小的数和最大的数
  输入描述:第一行一个整数n,接下来一行n个整数，每个整数不超过2^31 -1
  输出描述:最小和最大的数
  样例输入:4
           1 2 3 4
  样例输出:1 4*/

#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;
int main()
{
	int n,a,max,min,i;
	scanf("%d%d",&n,&a);
	max=a;
	min=a;
	for(i=1;i<=n-1;i++)
	{scanf("%d",&a);
	 if(a>max) max=a;
	 else if(a<min) min=a;
	      else min=min;
	}

	printf("%d %d",min,max);
	
	return 0;
} 
