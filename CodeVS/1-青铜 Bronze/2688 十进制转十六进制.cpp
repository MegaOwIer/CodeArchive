/*输入描述:输入一个十进制n。
  输出描述:输出一个十六进制x。
  样例输入:20
  样例输出:14
  数据范围及提示:n<=1000000*/

#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int a,i;
string b;

int main()
{
    cin>>a;
    while(a!=0)
    {
       i++;
       int m=a%16;
       if(m<10)  b[i]='0'+m;
       else switch(m)
            {
                case 10: b[i]='A';  break;
                case 11: b[i]='B';  break;
                case 12: b[i]='C';  break;
                case 13: b[i]='D';  break;
                case 14: b[i]='E';  break;
                case 15: b[i]='F';  break;
            }
       a/=16;
    }
    for(int j=i;j>0;j--)  cout<<b[j];
    return 0;
}
