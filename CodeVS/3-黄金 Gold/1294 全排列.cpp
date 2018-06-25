/*题目描述:给出一个n, 请输出n的所有全排列
  输入描述:读入仅一个整数n   (1<=n<=10)
  输出描述:一共n!行，每行n个用空格隔开的数，表示n的一个全排列。并且按全排列的字典序输出。
  样例输入:3
  样例输出:1 2 3
           1 3 2
		   2 1 3
		   2 3 1
		   3 1 2
		   3 2 1*/

#include<iostream>
using namespace std;

int a[11],b[11],k;

void yz(int i)
{
	int j;
	if(i>k)  {for(int m=1;m<=k;m++)  printf("%d ",a[m]);  printf("\n");}
	else 
	for(j=1;j<=k;j++)  if(b[j]==0)
	                   {
		                   a[i]=j; 
					       b[j]=1;
		                   yz(i+1);
		                   b[j]=0;
		               }
} 

int main()
{
	cin>>k;
	yz(1);
	
	return 0;
}
