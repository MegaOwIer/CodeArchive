/*题目描述:给你n根火柴棍，你可以拼出多少个形如“A+B=C”的等式？等式中的A、B、C是用火柴棍拼出的整数（若该数非零，则最高位不能是0）。
           注意:1.加号与等号各自需要两根火柴棍
		        2.如果A≠B，则A+B=C与B+A=C视为不同的等式（A、B、C>=0）
				3.n根火柴棍必须全部用上
  输入描述:输入文件共一行，有一个整数n（n<=24）。
  输出描述:输出文件共一行，表示能拼成的不同等式的数目。
  样例输入:样例1:14
           样例2:18
  样例输出:样例1:2
           样例2:9*/

#include<iostream>
#include<cstring>
using namespace std;

int stick[10]={6,2,5,5,4,5,6,3,7,6},cnt,num;
int sum(int);

int main()
{
	cin>>num;
	num-=4;
	for(int i=0;i<999;i++)
	  for(int j=0;j<999;j++)
	    if(sum(i)+sum(j)+sum(i+j)==num)  cnt++;
    cout<<cnt;
}

int sum(int v)
{
	if(v<10)  return  stick[v];
	else if(v<100)  return  stick[v/10]+stick[v%10];
	else  return  stick[v/100]+stick[v/10%10]+stick[v%10];
}
