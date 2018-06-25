/*题目描述:同学们在做题时常遇到这种函数
           f(x)=5 (x>=0)
           f(x)=f(x+1)+f(x+2)+1 (x<0)
           下面就以这个函数为题做一个递归程序吧
  输入描述:一个数x
  输出描述:一个数表示值
  样例输入:样例一：0
           样例二：-5
  样例输出:样例一：5
           样例二：77*/

#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int x,n;

int f(int x)
{
	if(x>=0)  return 5;
	else return f(x+1)+f(x+2)+1;
}

int main()
{
	cin>>n;
	cout<<f(n);
	
	return 0;
}
