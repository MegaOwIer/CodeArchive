/*题目描述:找出第n个质数
  输入描述:一个正整数n(1<=n<=100000)
  输出描述:第n个质数
  样例输入:样例1:2
           样例2:65
		   样例3:20133
  样例输出:样例1:3
           样例2:313
		   样例3:226381*/

#include<iostream>
#include<cmath>
using namespace std;

const int maxn=100005;
int n[maxn],m,cnt=5;
bool prime(int);

int main()
{
	cin>>m;
	n[1]=2;n[2]=3;n[3]=5;n[4]=7;
	for(int i=11;cnt<=m;i+=2)  if(prime(i))  n[cnt++]=i;
	cout<<n[m];
	return 0;
}
bool prime(int v)
{
	int m=sqrt(v);
	for(int i=2;n[i]<=m;i++)  if(v%n[i]==0)  return 0;
	return 1;
}
