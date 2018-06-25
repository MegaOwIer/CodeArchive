/*题目描述：给定N(n<=8)个点的地图,以及地图上各点的相邻关系,请输出用4种颜色将地图涂色的所有方案数(要求相邻两点不能涂成相同的颜色)
            数据中0代表不相邻，1代表相邻
  输入描述:第一行一个整数n，代表地图上有n个点
           接下来n行,每行n个整数,每个整数是0或者1.第i行第j列的值代表了第i个点和第j个点之间是相邻的还是不相邻,相邻就是1,不相邻就是0.
		   我们保证a[i][j] = a[j][i]
  输出描述:染色的方案数
  样例输入:8
           0 0 0 1 0 0 1 0 
		   0 0 0 0 0 1 0 1 
		   0 0 0 0 0 0 1 0 
		   1 0 0 0 0 0 0 0 
		   0 0 0 0 0 0 0 0 
		   0 1 0 0 0 0 0 0 
		   1 0 1 0 0 0 0 0 
		   0 1 0 0 0 0 0 0
  样例输出:15552
  数据范围及提示:n<=8*/

#include<iostream>
using namespace std;

int n,a[10][10],c[10];
long cnt;
bool flag;
void dfs(int);

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)  for(int j=1;j<=n;j++)  cin>>a[i][j];
    dfs(1);
    cout<<cnt;
    return 0;
}
void dfs(int v)
{
     if(v>n)  {cnt++;  return;}
     for(int i=1;i<=4;i++)
     {
         flag=0;
         for(int j=1;j<v;j++)  
         if(a[v][j]==1&&c[j]==i)  {flag=1;  break;}
         if(flag)  continue;
         c[v]=i;
         dfs(v+1);
     }
}
