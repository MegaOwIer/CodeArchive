/*题目描述:(此题与栈练习1相比改了2处:1加强了数据 2不保证栈空时不会出栈)给定一个栈(初始为空,元素类型为整数,且小于等于100),只有两个操作:入栈和出栈
           先给出这些操作,请输出最终栈的栈顶元素.操作解释:1表示入栈,2表示出栈
  输入描述:N(操作个数)
           N个操作(如果是入栈则后面还会有一个入栈元素)
		   具体见样例(输入不保证栈空时不会出栈)
  输出描述:最终栈顶元素,若最终栈空,或栈空时有出栈操作,输出"impossible!"(不含引号)
  样例输入:3
           1 2
		   2
		   2
  样例输出:impossible!
  数据范围及提示:对于100%的数据N<=100000元素均为正整数且小于等于10^8  */

#include<iostream>
#include<stack>
using namespace std;

int a,b,n;
stack<int> s;

int main()
{
    cin>>n;
    while(n--)
    {
        cin>>a;
        if(a==2&&s.empty())  {cout<<"impossible!";  return 0;}
        if(a==2&&!s.empty())  s.pop();
        if(a==1)  {cin>>b;  s.push(b);}
    }
    if(s.empty())  cout<<"impossible!";
    else  cout<<s.top();
    return 0;
}
