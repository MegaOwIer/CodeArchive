/*题目描述:将十进制数n转换成m进制数 m<=16 n<=100
  输入描述:共一行,n和m
  输出描述:共一个数,表示n的m进制
  样例输入:样例1：10 2
           样例2:100 15
  样例输出:样例1：1010
           样例2:6A
  数据范围及提示:用反向取余法*/

#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int d[1000];

int main()
{
    int x,i=0,j,n;
    scanf("%d%d",&x,&n);
	while(x!=0)
    {
        i++;
        d[i]=x%n;
        x=x/n;
	}
    for(j=i;j>0;j--)  
	{
		if(d[j]<10)  	printf("%d",d[j]);
		else if(d[j]==10)  	cout<<"A";
		     else if(d[j]==11)  	cout<<"B";
		          else if(d[j]==12)  	cout<<"C";
		               else if(d[j]==13)  	cout<<"D";
		                    else if(d[j]==14)  	cout<<"E";
		                         else  cout<<"F";
	}
    return 0;
}
