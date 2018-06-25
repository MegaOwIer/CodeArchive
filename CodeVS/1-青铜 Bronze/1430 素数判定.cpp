/*输入描述:第一行输入一个正整数n，n<=30000
  输出描述:如果该数是质数，则输出\t,否则输出\n
  输入样例１:13
  样例输出１:\t
  输入样例２:8
  样例输出２:\n
  数据范围及提示:c或c++的初学者注意，"＼"的意思*/

#include<cstdio>
#include<cmath>
#include<iostream> 

using namespace std;

int main()
{
    int n,i,x,f=0;
    double a;
    scanf("%d",&n);
    a=sqrt(n);
    for(i=2;i<=a;i++)
    { 
        x=n%i;
        if(x==0) {std::cout << "\\n";f=1;break;}
    }
    if(f==0) std::cout << "\\t";

    return 0;
}
