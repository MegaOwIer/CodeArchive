/*题目描述:克拉兹问题也被叫做hailstone问题、3n+1问题、Hasse算法问题、Kakutani算法问题、Thwaites猜想或者Ulam问题。
           问题如下：
           （1）输入一个正整数n；
           （2）如果n=1则结束；
           （3）如果n是奇数，则n变为3n+1，否则n变为n/2；
           （4）转入第（2）步。
           克拉兹问题的特殊之处在于：尽管很容易将这个问题讲清楚，但至今没有人证明对所有的正整数该过程都终止。
  输入描述：第一行是一个整数T.表示输入数据的组数,第二行是T个正整数n.
  输出描述:对于每个正整数n，每行输出一个数s，表示n通过多少步变换会变成1，如果n无法变成1，则输出-1.
  样例输入:3
           1 2 3
  样例输出:0
           1
           7
  数据范围及提示:1 <= T <= 100
                 1 <= n <= 10000*/

#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int x,T,n[105],i,p[105];

int f(int x)
{
	if(x%2==1)   return 3*x+1;
	else return x/2;
}

int main()
{
	cin>>T;
	for(i=1;i<=T;i++)
	{
		cin>>n[i];
		p[i]=0;
		while(n[i]!=1)  {p[i]++;  n[i]=f(n[i]);} 
	}
	for(i=1;i<=T;i++)  cout<<p[i]<<'\n';
	
	return 0;
}
