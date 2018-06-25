/*题目描述:给定2个整数a,b 求出它们之间（不含a，b）所有质数的和。
  输入描述:一行，a b(0<=a,b<=65536)
  输出描述:一行，a,b之间(不含a，b)所有素数的和。
  样例输入:39 1224
  样例输出:111390
  数据范围及提示:注意没有要求a<b*/

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

long a,b,ans;
bool prime(int);

int main()
{
    cin>>a>>b;
    if(a>=b)  swap(a,b);
    for(int i=a+1;i<b;i++)  if(prime(i))  ans+=i;
    cout<<ans;
    return 0;
}
bool prime(int v)
{
     double m=sqrt(v);
     for(int i=2;i<=m;i++)  if(v%i==0)  return 0;
     return 1;
}
