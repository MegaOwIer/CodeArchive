/*题目描述:一个庙里有三根金刚石的棒,第一根上面套着64个圆的金片,最大的一个在底下,其余一个比一个小,依次叠上去.
           庙里的众僧不倦地把它们一个个地从这根棒搬到另一根棒上,规定可利用中间的一根棒作为帮助,但每次只能搬一个,而且大的不能放在小的上面.
		   现在要移动n个圆盘,输出移动次数.
  输入描述:n(n<=100)
  输出描述:移动次数
  样例输入:3
  样例输出:7*/

#include<iostream>
using namespace std;

int a;

int f(int n)
{
	if(n==1)  return 1;
	else  return 2*f(n-1)+1;
}

int main()
{
	cin>>a;
	cout<<f(a)<<endl； 
	return 0;
}
