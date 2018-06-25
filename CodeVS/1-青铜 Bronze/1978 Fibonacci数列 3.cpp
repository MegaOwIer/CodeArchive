/*题目描述:斐波纳契数列满足：fn = fn-1 + fn-2
           输入一个整数n,求fn
  输入描述:一个整数n, n<= 40
  输出描述:一个整数fn
  样例输入:3
  样例输出:2
  数据范围及提示:n<=40*/ 

#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int a[50],n,i;

int main()
{
   a[1]=1;a[2]=1;
   for(i=3;i<=50;i++)  a[i]=a[i-1]+a[i-2];
   cin>>n;
   cout<<a[n];
   
   return 0;
}
