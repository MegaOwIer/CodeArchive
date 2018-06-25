/*题目描述:实现从小到大排序。
  输入描述:第一行一个整数n
           第二行n个整数，每个用空隔隔开。
  输出描述:从小到大依次数据，每行一个，共n行。
  样例输入:6
           1
		   2
		   5
		   4
		   3
		   2
  样例输出:1
           2
		   2
		   3
		   4
		   5
  数据范围及提示:最简单的排序，供初学者练习，不要想太复杂,n<=12*/

#include<iostream>
#include<algorithm>
using namespace std;

int n,a[15];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>a[i];
    sort(a+1,a+n+1,less<int>());
    for(int i=1;i<=n;i++)  cout<<a[i]<<endl;
    return 0;
}
