/*题目描述：求n个数的和
  输入描述：第一行一个整数n
            接下来一行n个整数
  输出描述：所有数的和
  样例输入：4
            1 2 3 4
  样例输出：10
  数据范围及提示：n<=100，所有数的和<=231-1*/

#include<cstdio> 
#include<cstring>
#include<cstdlib>
#include<cmath>

using namespace std;
int main()
{
	int n,m,s,i;
	scanf("%d",&n);
	s=0;
	for(i=1;i<=n;i++)
	{scanf("%d",&m);
	 s=s+m;
	}
	printf("%d",s);
	
	return 0;
}

