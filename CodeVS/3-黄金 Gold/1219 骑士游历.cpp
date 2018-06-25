/*题目描述:设有一个n*m的棋盘(2<=n<=50,2<=m<=50),棋盘上有一个中国象棋马.
           规定:1)马只能走日字
		        2)马只能向右跳
		   问给定起点x1,y1和终点x2,y2，求出马从x1,y1出发到x2,y2的合法路径条数.
  输入描述:第一行2个整数n和m
           第二行4个整数x1,y1,x2,y2
  输出描述:输出方案数
  样例输入:30 30
           1 15 3 15
  样例输出:2
  数据范围及提示:2<=n,m<=50*/

#include<iostream>
using namespace std;

long long n,m,x1,x2,y1,y2,dx[]={0,1,2,2,1},dy[]={0,2,1,-1,-2};
long long g[100][100];

int main()
{
    cin>>n>>m>>x1>>y1>>x2>>y2;
    g[x1+10][y1+10]=1;
    for(int i=11;i<=n+10;i++)  for(int j=11;j<=m+10;j++)
      for(int k=1;k<5;k++)  g[i][j]+=g[i-dx[k]][j-dy[k]];
    cout<<g[x2+10][y2+10];
    return 0;
}
