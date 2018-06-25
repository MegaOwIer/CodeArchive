/*题目描述:现代数学的著名证明之一是Georg Cantor证明了有理数是可枚举的.他是用下面这一张表来证明这一命题的:
           1/1 1/2 1/3 1/4 1/5 … 
		   2/1 2/2 2/3 2/4 … 
		   3/1 3/2 3/3 … 
		   4/1 4/2  …
		   5/1 … 
		   我们以Z字形给上表的每一项编号。第一项是1/1，然后是1/2，2/1，3/1，2/2，…
  输入描述:整数N（1≤N≤10000000）
  输出描述:表中的第N项
  样例输入:7
  样例输出:1/4*/

#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int n,a,b,i=1;

int main()
{
   cin>>n;
   while(n>i)  {n-=i;   i++;}
   i++;
   if(i%2==0)  {b=n;   a=i-n;}
   else {a=n;   b=i-n;}
   
   cout<<a<<'/'<<b;
   
   return 0;
}
