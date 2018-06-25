/*题目描述:已知Sn= 1＋1／2＋1／3＋…＋1／n。对于任意一个整数K，当n足够大的时候，Sn大于K。现给出一个整数K（1<=k<=15），要求计算出一个最小的n，使得Sn＞K。
  输入描述:键盘输入 k
  输出描述:屏幕输出 n
  样例输入:1
  样例输出:2*/

#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int i=0,n;
	double s=0;
	cin>>n;
	while(s<=n)
	{
		i++;
		s+=1.0/i;
	}
	cout<<i;
	
	return 0;
}
