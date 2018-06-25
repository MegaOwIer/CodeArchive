/*题目描述:把自然数Ｎ分解为若干个自然数之和，输出方案数。
  输入描述:N（1<=n<=50）
  输出描述:方案数
  样例输入:5
  样例输出:7
  数据范围及提示:5可分为1 1 1 1 1
                        1 1 1 2
						1 1 3
						1 2 2
						1 4
						2 3
						5*/ 

#include<iostream>
using namespace std;

int a[1000],p;

void chai(int k)
{
	int ha=a[k];
	p++;
	for(int j=a[k-1];j<=ha/2;j++)
	{
		
		a[k]=j;
		a[k+1]=ha-j;
		chai(k+1);
	}
}

int main()
{
    int n;
    cin>>n;
    a[0]=n;
	for(int l=1;l<=n/2;l++) 
	{
		a[1]=l;
		a[2]=n-l;
	    chai(2);
	}
	cout<<p+1;
	
	return 0;
}
