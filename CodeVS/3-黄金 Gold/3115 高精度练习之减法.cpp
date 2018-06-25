/*题目描述:给出两个正整数A和B，计算A-B的值。保证A和B的位数不超过500位。
  输入描述:读入两个用空格隔开的正整数
  输出描述:输出A-B的值
  样例输入:3 12
  样例输出:-9
  数据范围及提示:两个正整数的位数不超过500位*/

#include<iostream>
#include<cstring>
using namespace std;

string st1,st2;
char ch1[600],ch2[600],ch3[600];
int lg1,lg2,n;
bool flag;

int main()
{
	cin>>st1>>st2;
	lg1=st1.length();
	lg2=st2.length();
    for(int i=0;i<600;i++)  ch1[i]=ch2[i]=ch3[i]='0';
    if(lg1<lg2||(lg1==lg2 && st1[0]<st2[0]))  {
                                                  string aa=st1;  st1=st2;  st2=aa;  flag=true;
                                                  int aaa=lg1;  lg1=lg2;  lg2=aaa;
                                              }
    if(flag)  cout<<"-";
	for(int i=0;i<lg1;i++)  ch1[599-i]=st1[lg1-1-i];
	for(int i=0;i<lg2;i++)  ch2[599-i]=st2[lg2-1-i];
	n=lg1>lg2?lg1:lg2;
	for(int i=599;i>595-n;i--)
	{
		ch3[i]+=ch1[i]-ch2[i];
		if(ch3[i]<'0')  {ch3[i]+=10;  ch3[i-1]--;}
	}
	int i=0;
	while(ch3[i]=='0')  i++;
	for(int j=i;j<600;j++)  cout<<ch3[j];
	return 0;
}
