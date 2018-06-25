/*题目描述:一行N个方格,开始每个格子里都有一个整数
           现在动态地提出一些问题和修改:提问的形式是求某一个特定的子区间[a,b]中所有元素的和,修改的规则是指定某一个格子x,加上或者减去一个特定的值A
		   现在要求你能对每个提问作出正确的回答.1<=N<100000,提问和修改的总数m<10000条
  输入描述:输入文件第一行为一个整数N.接下来是n行n个整数.表示格子中原来的整数
           接下一个正整数m,再接下来有m行,表示m个询问,第一个整数表示询问代号,询问代号1表示增加,后面的两个数x和A表示给位置X上的数值增加A
		   询问代号2表示区间求和,后面两个整数表示a和b,表示要求[a,b]之间的区间和
  输出描述:共m行,每个整数
  样例输入:6
           4 
		   5 
		   6 
		   2 
		   1 
		   3
		   4
		   1 3 5
		   2 1 4
		   1 1 9
		   2 2 6
  样例输出:22
           22
  数据范围及提示:1<=N<=100000,m<=10000*/

#include<iostream>
#include<cstdio>
using namespace std;

int n,m,a[100001];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)  scanf("%d",&a[i]);
	cin>>m;
	for(int i=1,aa,bb,cc;i<=m;i++)
	{
		scanf("%d%d%d",&aa,&bb,&cc);
		if(aa==1)  a[bb]+=cc;
		else  {
		          long long ans=0;
		          for(int j=bb;j<=cc;j++)  ans+=a[j];
		          printf("%lld\n",ans);
		      }
	}
	return 0;
}
