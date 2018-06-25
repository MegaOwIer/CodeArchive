/*题目描述:我们要求找出具有下列性质数的个数(包含输入的自然数n):
           先输入一个自然数n(n<=1000),然后对此自然数按照如下方法进行处理:
           1.不作任何处理;
           2.在它的左边加上一个自然数,但该自然数不能超过原数的一半;
           3.加上数后,继续按此规则进行处理,直到不能再加自然数为止.
  输入描述:一个数n
  输出描述:满足条件的数的个数
  样例输入:6
  样例输出:6
  数据范围及提示:6个数分别是：6,16,26,126,36,136*/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int i,p=0;

void f(int n)
{
	if(n==0)  return;
    p++;
	for(i=1;i<=n/2;i++)  f(i);
}

int main()
{
	int n;
	cin>>n;
	f(n);
	cout<<p;
	
	return 0;
}
