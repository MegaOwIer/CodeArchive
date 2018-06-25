/*题目描述:给一个数组a1, a2 ... an，找到最长的上升降子序列ab1<ab2< .. <abk，其中b1<b2<..bk.输出长度即可。
  输入描述:第一行,一个整数N
           第二行,N个整数(N < = 5000)
  输出描述:输出K的极大值,即最长不下降子序列的长度
  样例输入:5
           9 3 6 2 7
  样例输出:3
  样例解释:最长不下降子序列为3,6,7*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n,a[5001],ans[5001];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)  cin>>a[i];
	ans[1]=1;
	for(int i=2;i<=n;i++)  for(int j=1;j<i;j++)  if(a[j]<a[i])
	{
		int m=ans[j]+1;
		ans[i]=m>ans[i]?m:ans[i];
	}
	sort(ans+1,ans+n+1,greater<int>());
	cout<<ans[1];
	return 0;
}
