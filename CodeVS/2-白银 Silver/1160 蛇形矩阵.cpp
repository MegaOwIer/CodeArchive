/*题目描述:取一个n行n列数字矩阵(其中n为不超过100的奇数),在矩阵中心从1开始以逆时针方向绕行,逐圈扩大,直到n行n列填满数字,请输出该n行n列正方形矩阵以及其的对角线数字之和.
  输入描述:n（即n行n列）
  输出描述:n+1行，n行为组成的矩阵，最后一行为对角线数字之和
  样例输入:3
  样例输出:5 4 3
           6 1 2
		   7 8 9
		   25*/

#include<iostream>
using namespace std;

int n,a[100][100],l,m,sum;

int main()
{
	cin>>n;
	a[(n+1)/2][(n+1)/2]=1;
	l=m=(n+1)/2;
	for(int i=1;i<=(n-1)/2;i++)
	{
		for(int j=1;j<=2*i-1;j++)  {a[l][m+1]=a[l][m]+1;  m++;}
		for(int j=1;j<=2*i-1;j++)  {a[l-1][m]=a[l][m]+1;  l--;}
		for(int j=1;j<=2*i;j++)  {a[l][m-1]=a[l][m]+1;  m--;}
		for(int j=1;j<=2*i;j++)  {a[l+1][m]=a[l][m]+1;  l++;}
	}
	for(int i=1;i<=n-1;i++)  {a[l][m+1]=a[l][m]+1;  m++;}
	for(int i=1;i<=n;i++)  {for(int j=1;j<=n;j++)  cout<<a[i][j]<<' ';  cout<<endl;}
	for(int i=1;i<=n;i++)  sum+=a[i][i]+a[i][n+1-i];
	cout<<sum-1;
	return 0;
} 
