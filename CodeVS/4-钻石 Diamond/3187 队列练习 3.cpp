/*题目描述:比起第一题,本题加了另外一个操作,访问队头元素(编号3,保证访问队头元素时或出队时队不为空),现在给出这N此操作,输出结果
  输入描述:N
           N次操作(1入队,2出队,3访问队头)
  输出描述:K行(K为输入中询问的个数)每次的结果
  样例输入:6
           1 7
		   3
		   2
		   1 9
		   1 7
		   3
  样例输出:7
           9
  数据范围及提示:对于50%的数据N≤1000入队元素≤200
                 对于100%的数据N≤100000入队元素均为正整数且小于等于10^4*/

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
        if(ord==2)  q.pop();
	    else  if(ord==1)  {cin>>no;  q.push(no);}
	    else  cout<<q.front()<<endl;
	}
	return 0;
}
