/*题目描述:有n堆石子排成一列,每堆石子有一个重量w[i],每次合并可以合并相邻的两堆石子,一次合并的代价为两堆石子的重量和w[i]+w[i+1]
           问安排怎样的合并顺序,能够使得总合并代价达到最小
  输入描述:第一行一个整数n(n<=100)
           第二行n个整数w1,w2...wn (wi<=100)
  输出描述:一个整数表示最小合并代价
  样例输入:4
           4 1 1 4
  样例输出:18*/

#include<iostream>
#include<algorithm>
using namespace std;

int n,w[101],sum[101],p[101][101];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)  {cin>>w[i];  sum[i]=sum[i-1]+w[i];}
	for(int i=1;i<n;i++)  for(int j=1;i+j<=n;j++)
	{
		p[j][i+j]=0x7fffffff;
		for(int k=0;k<i;k++)  
		p[j][i+j]=min(p[j][i+j],p[j][j+k]+p[j+k+1][i+j]+sum[i+j]-sum[j-1]);
	}
	cout<<p[1][n];
	return 0;
}
