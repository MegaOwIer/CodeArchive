/*题目描述:编程找出输入的n个整数中的次大值(即第二大的值)。
  输入描述:第一行一个正整数n，表示灯会一共要输入n个整数。第二行为n个用空格分隔的整数。
  输出描述:一行一个整数，表示输入n个整数中第二大的那个数的值。
  样例输入:5
           8 9 12 33 2
  样例输出:12
  数据范围及提示:2<=n<=100，每个整数的绝对值不超过10000.*/

#include<iostream>
#include<algorithm>
using namespace std;

int n,a[105];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    cout<<a[2];
    return 0;
}
