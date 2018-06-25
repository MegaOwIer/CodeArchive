/*题目描述:给定一组整数，求其中位数
  输入描述:两行
           第一行为数的个数n
		   第二行为n个数，每两个数之间由一个空格隔开
  输出描述:一行，为其中位数如果是整数，输出整数；如果是小数，保留一位
  样例输入:4
           1 3 2 4
  样例输出:2.5
  数据范围及提示:对于100%的数据:0<n<=20000,-10000<=a[n]<=10000*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int n,a[25000];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>a[i];
    sort(a+1,a+n+1);
    if(n%2==1)  cout<<a[n/2+1];
    else  printf("%.1lf",(a[n/2]+a[n/2+1])/2.0);
    return 0;
}
