/*题目描述:给出一棵二叉树的中序与后序排列.求出它的先序排列(约定树结点用不同的大写字母表示,长度<=8).
  输入描述:两个字符串,分别是中序和后序(每行一个)
  输出描述:一个字符串,先序
  样例输入:BADC
           BDCA
  样例输出:ABCD  */

#include<iostream>
#include<cstring>
using namespace std;

string st1,st2;
void digui(string,string);

int main()
{
	cin>>st1>>st2;
	digui(st1,st2);
	return 0;
}
void digui(string u,string v)
{
	int l=v.length();
	if(l==1)  {cout<<u;  return;}
	cout<<v[l-1];
	int x=u.find(v[l-1]);
	string m,n;
	if(x!=0)  {m=u.substr(0,x);  n=v.substr(0,x);  digui(m,n);}
	if(x!=l-1)  {m=u.substr(x+1,l-1-x);  n=v.substr(x,l-1-x);  digui(m,n);}
}
