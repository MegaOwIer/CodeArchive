/*题目描述:给出一个二叉树，输出它的最大宽度和高度。
  输入描述:第一行一个整数n.下面n行每行有两个数,对于第i行的两个数,代表编号为i的节点所连接的两个左右儿子的编号.如果没有某个儿子为空,则为0.
  输出描述:输出共一行，输出二叉树的最大宽度和高度，用一个空格隔开。
  样例输入:5
           2 3
		   4 5
		   0 0
		   0 0
		   0 0
  样例输出:2 3
  数据范围及提示:n<16*/

#include<iostream>
#include<algorithm>
using namespace std;

int root[20],zuo[20],you[20],n,fa[20],h=1,w[20],f[20];

int main()
{
	cin>>n;
	f[1]=1; 
	for(int i=1;i<=n;i++)  
	{
	    root[i]=i;
		cin>>zuo[i]>>you[i];
		if(zuo[i]!=0)  {fa[zuo[i]]=i;  f[zuo[i]]=f[i]+1;}
		if(you[i]!=0)  {fa[you[i]]=i;  f[you[i]]=f[i]+1;}
	}
	sort(f+1,f+n+1,greater<int>());
    for(int i=1;i<=n;i++)  w[f[i]]++;
    sort(w+1,w+n+1,greater<int>());
    cout<<w[1]<<' '<<f[1];
    
    return 0;
}
