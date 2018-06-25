/*题目描述:在n×n格的棋盘上放置彼此不受攻击的n个皇后。按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
           n后问题等价于再n×n的棋盘上放置n个皇后，任何2个皇后不妨在同一行或同一列或同一斜线上。
  输入描述:给定棋盘的大小n
  输出描述:输出整数表示有多少种放置方法。
  样例输入:8
  样例输出:92
  数据范围及提示:n<=13（时限提高了，不用打表了）*/

#include<iostream>
using namespace std;

int x[15],a[100],b[100],c[100],n,p=0;

void search(int i)
{
	if(i>n)  p++;
	else
	for(int j=1;j<=n;j++)
	{
		if(a[i-j+30]==0&b[i+j]==0&&c[j]==0)
		{
		x[i]=j;
		a[i-j+30]=b[i+j]=c[j]=1;
		search(i+1);
		a[i-j+30]=b[i+j]=c[j]=0;
	    }
	}
}

int main()
{
	cin>>n;
	search(1);
	cout<<p;
	
	return 0; 
} 
