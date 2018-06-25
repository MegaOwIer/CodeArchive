/*题目描述:求一棵二叉树的前序遍历，中序遍历和后序遍历
  输入描述:第一行一个整数n，表示这棵树的节点个数。
           接下来n行每行2个整数L和R。第i行的两个整数Li和Ri代表编号为i的节点的左儿子编号和右儿子编号。
  输出描述:输出一共三行，分别为前序遍历，中序遍历和后序遍历。编号之间用空格隔开。
  样例输入:5
           2 3
		   4 5
		   0 0
		   0 0
		   0 0
  样例输出:1 2 4 5 3
           4 2 5 1 3
		   4 5 2 3 1
  数据范围及提示:n <= 16*/

#include<iostream>
using namespace std;

int root[20],zuo[20],you[20],n;
void xian(int j)
{
	cout<<j<<' ';
	if(zuo[j]!=0)  xian(zuo[j]);
	if(you[j]!=0)  xian(you[j]);	
}
void zhong(int j)
{
    if(zuo[j]!=0)  zhong(zuo[j]);
	cout<<j<<' ';
	if(you[j]!=0)  zhong(you[j]);	
}
void hou(int j)
{
	if(zuo[j]!=0)  hou(zuo[j]);
	if(you[j]!=0)  hou(you[j]);
	cout<<j<<' ';	
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)  {root[i]=i;  cin>>zuo[i]>>you[i];}
	xian(1);cout<<endl;
	zhong(1);cout<<endl;
	hou(1);
	return 0;
}
