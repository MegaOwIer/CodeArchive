/*题目描述:小明是个很爱思考的孩子，有一天他发现一种数字，这种数字只能被1和本身整除，例如
           2,3,5,7，现在给出一段数字，你能帮他判断是否是这种数吗？如果是就输出1不然输出0
  样例输入:样例1:5
                 2 3 4 5 6
		   样例2:10
		         5 6 15 87 2 2 5 5 4 2 
  样例输出:输出1:1 1 0 1 0
           输出2: 1 0 0 1 1 1 1 1 0 1
  数据范围及提示:1<=n<=100000*/ 

#include<iostream>
#include<cmath>
using namespace std;

int n,a;

int prime(int v)
{
    if(v==2)  return 1;
    if(v<=1)  return 0;
    else  {
              int m=sqrt(a),fl=0;
              for(int j=2;j<=m;j++)  if(a%j==0)  return 0;
          }
    return 1;
} 
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        cout<<prime(a)<<' ';
    }
    return 0;
}
