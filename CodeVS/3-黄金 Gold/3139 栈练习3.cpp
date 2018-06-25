/*题目描述:比起第一题,本题加了另外一个操作,访问栈顶元素(编号3,保证访问栈顶元素时或出栈时栈不为空),现在给出这N此操作,输出结果。
  输入描述:N
           N次操作(1入栈,2出栈,3访问栈顶)
  输出描述:K行(K为输入中询问的个数)每次的结果
  样例输入:6
           1 7
		   3
		   2
		   1 9
		   1 7
		   3
  样例输出:7
           7
  数据范围及提示:对于50%的数据N<=1000入栈元素<=200
                 对于100%的数据N<=100000入栈元素均为正整数且小于等于10^4   */

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
        if(a==2)  s.pop();
        if(a==1)  {cin>>b;  s.push(b);}
        if(a==3)  cout<<s.top()<<endl;
    }
    return 0;
}

