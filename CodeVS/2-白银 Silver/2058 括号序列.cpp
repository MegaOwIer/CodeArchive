/*题目描述:定义满足以下规则字符串为规则序列,否则不是规则序列:
           1.空序列是规则序列
		   2.如果S是规则序列,那么(S),[S],{S}和<S>也是规则序列
		   3.如果A和B都是规则序列,那么AB也是规则序列
		   例如,下面的字符串都是规则序列:
		   ()  []  (())  ([])  ()[]  ()[()]  {{}}<>  ([]<>{{}})  <<{}>>
		   而以下几个则不是:
		   (  [  ]  )(  ())  ([()  <<  {(})  <{}>)
		   现在,给你一些由"(".")"."["."]"."{"."}"."<".">"构成的字符串,请判断该字符串是否为规则序列
  输入描述:第一行:一个正整数N,表示测试数据组数
           接下来N行:每行一个括号序列(长度不超过L)
  输出描述:共N行,对于每一个括号序列,判断其是否规则
           规则输出TRUE,否则输出FALSE.
  样例输入:2
           {()}<<>>
		   {{{{{}}}}
  样例输出:TRUE
           FALSE
  数据范围及提示:对于40%数据,有N=1,0<L<=20;
                 对于80%数据,有0<N<=5,0<L<=10^3;
				 对于100%数据,有0<N<=10,0<L<=2*10^6.*/

#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

int n;
string st;

int main()
{
	cin>>n;
	while(n--)
	{
		bool f=0;
		stack<char> s;
		s.push(0);
		cin>>st;
		int x=st.length();
		for(int i=0;i<x;i++)
		{
			if(st[i]=='('||st[i]=='['||st[i]=='{'||st[i]=='<')  s.push(st[i]);
			else  if(st[i]==')'&&s.top()=='(')  s.pop();
			      else  if(st[i]==']'&&s.top()=='[')  s.pop();
			            else  if(st[i]=='}'&&s.top()=='{')  s.pop();
			                  else  if(st[i]=='>'&&s.top()=='<')  s.pop();
			                        else  {cout<<"FALSE"<<endl;  f=1;  break;}
		}
		if(f)  continue;
		if(s.top()==0)  cout<<"TRUE"<<endl;
		else  cout<<"FALSE"<<endl;
	}
	return 0;
}
