/*题目描述:设有一个长度为N的数字串，要求选手使用K个乘号将它分成K+1个部分，找出一种分法，使得这K+1个部分的乘积能够为最大。
           例如，有一个数字串：312， 当N=3，K=1时会有以下两种分法：1)  3*12=36
		                                                           2)  31*2=62
		   这时，符合题目要求的结果是：31*2=62
  输入描述:程序的输入共有两行：第一行共有2个自然数N,K(6≤N≤40,1≤K≤6),第二行是一个长度为N的数字串。
  输出描述:结果显示在屏幕上，相对于输入，应输出所求得的最大乘积（一个自然数）。
  样例输入:4 2
           1231
  样例输出:62*/

#include<iostream>
#include<string>
using namespace std;

string str,st1,st2;
long mx,f[100][100],n,km;

int zhuan(int u,int v)
{
	int y=0;
	for(int i=u;i<=v;i++)  y=y*10+str[i]-'0';
	return y;
}

int main()
{
	cin>>n>>km>>str;
	for(int i=1;i<n;i++)
	{
		mx=0;
		for (int j=0;j<i;j++)
		{
			long q=zhuan(0,j)*zhuan(j+1,i);
		    mx=q>mx?q:mx;
		}
	    f[1][i]=mx;
	}
	for(int s=2;s<=n;s++)
	{
		for(int i=s;i<=n;i++)
		{
			mx=0;
			for(int j=1;j<=i;j++)
			{
				long q=f[s-1][j]*zhuan(j+1,i);
				mx=q>mx?q:mx;
			}
		    f[s][i]=mx;
		}
	}
	cout<<f[km][n-1];
    return 0;
}
