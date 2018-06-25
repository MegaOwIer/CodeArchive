/*题目描述:判断函数y=x^n次方的奇偶性若是奇函数就输出ji,偶函数输出ou
  输入描述:一行输入n
  输出描述:一行,输出答案
  样例输入:2
  样例输出:ou
  数据范围及提示:n为正整数*/

#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

string n;

int main()
{
    cin>>n;
    int m=n.length();
    int x=n[m-1];
    if(x%2==0)  cout<<"ou";
    else  cout<<"ji";
    return 0;
}
