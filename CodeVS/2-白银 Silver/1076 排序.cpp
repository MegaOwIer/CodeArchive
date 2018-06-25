/*题目描述:给出n和n个整数，希望你从小到大给他们排序
  输入描述:第一行一个正整数n,第二行n个用空格隔开的整数
  输出描述:输出仅一行，从小到大输出n个用空格隔开的整数
  样例输入:3
           3 1 2
  样例输出:1 2 3
  数据范围及提示:1<=n<=100000*/

#include<cstdio>
#include<algorithm>

using namespace std;

bool com(int a,int b)
{
     return a<b;
}

int main()
{
    int a[100000],n,i;
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)  scanf("%d",&a[i]);
    sort(a,a+n,com);
    for(i=0;i<=n-1;i++)  printf("%d ",a[i]);

    return 0;
}
