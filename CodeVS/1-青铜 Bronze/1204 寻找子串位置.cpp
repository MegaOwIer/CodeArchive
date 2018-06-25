/*题目描述：给出字符串a和字符串b，保证b是a的一个子串，请你输出b在a中第一次出现的位置。
  输入描述：仅一行包含两个字符串a和b
  输出描述：仅一行一个整数
  样例输入：abcd bc
  样例输出：2
  数据范围及提示：字符串的长度均不超过100*/


#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;
int main()
{
	int x;
	string st1,st2;
	cin>>st1>>st2;
	x=1+st1.find(st2);
	printf("%d",x);
	
	return 0;
	 
}
