/*题目描述:将整数n分成k份,且每份不能为空,任意两种划分方案不能相同(不考虑顺序)
           例如:n=7,k=3,下面三种划分方案被认为是相同的(1 1 5),(1 5 1),(5 1 1)
		   问有多少种不同的分法
  输入描述:n,k(6<n<=200，2<=k<=6)
  输出描述:一个整数,即不同的分法
  样例输入:7 3
  样例输出:4
  数据范围及提示:四种分法为:(1,1,5)(1,2,4)(1,3,3)(2,2,3)*/

#include<iostream>
using namespace std;

int m,n,cnt;
void divide(int,int,int);

int main()
{
	cin>>m>>n;
	divide(m,n,1);
	cout<<cnt;
	return 0;
}
void divide(int u,int v,int st)
{
	if(v==2)  {cnt+=(u/2-st+1)>0?(u/2-st+1):0;  return;}
	for(int i=st;i<=u/2;i++)  
	divide(u-i,v-1,i);
}
