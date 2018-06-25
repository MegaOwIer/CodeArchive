/*题目描述:(此题与队列练习1相比改了2处:1加强了数据 2不保证队空时不会出队)
           给定一个队列(初始为空),只有两种操作入队和出队,现给出这些操作请
		   输出最终的队头元素.操作解释:1表示入队,2表示出队
  输入描述:N(操作个数)
           N个操作(如果是入队则后面还会有一个入队元素)
		   具体见样例(输入保证队空时不会出队)
  输出描述:最终队头元素,若最终队空,或队空时有出队操作,输出"impossible!"(不含引号)
  样例输入:3
           1 2
		   2
		   2
  样例输出:impossible!
  数据范围及提示:对于100%的数据N≤100000元素均为正整数且小于等于10^8*/

#include<iostream>
#include<queue>
using namespace std;

queue<int> q;
int n,ord,no;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    cin>>ord;
	    if((ord-1)&&q.empty())  {cout<<"impossible!";  return 0;}
	    else  if((ord-1)&&!q.empty())  q.pop();
	    else  {cin>>no;  q.push(no);}
	}
	if(q.empty())  cout<<"impossible!";
	else cout<<q.front();
	return 0;
}
