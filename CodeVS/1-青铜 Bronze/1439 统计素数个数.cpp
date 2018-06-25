/*题目描述:输入区间(L, R),寻找在此区间内的质数
  输入描述:开区间(L, R)中的整数L,R
  输出描述:在此区间中所有质数的个数n
  样例输入:0 100
  样例输出:25
  数据范围及提示:对于所有数据,L,R<=21000,区间长度R-L<=4000*/

#include<iostream>
#include<cmath>
using namespace std;

int a,b,ans;

int prime(int v)
{
    if(v==2)  return 1;
    if(v<=1)  return 0;
    else  {
              int m=sqrt(v),fl=0;
              for(int j=2;j<=m;j++)  if(v%j==0)  return 0;
          }
    return 1;
}

int main()
{
    cin>>a>>b;
    for(int i=a+1;i<b;i++)  ans+=prime(i);
    cout<<ans;
    return 0;
}
