/*题目描述:给出两个正整数A和B,计算A*B的值保证A和B的位数不超过500位
  输入描述:读入两个用空格隔开的正整数
  输出描述:输出A*B的值
  样例输入:3 12
  样例输出:36
  数据范围及提示:两个正整数的位数不超过500位*/

#include<iostream>
#include<cstring>
using namespace std;

string aa,bb;
int la,lb,a[501],b[501],c[1010];

int main()
{
	cin>>aa;  la=aa.length();
	cin>>bb;  lb=bb.length();
	for(int i=0;i<la;i++)  a[i]=aa[la-1-i]-'0';
	for(int i=0;i<lb;i++)  b[i]=bb[lb-1-i]-'0';
	for(int i=0;i<la+lb;i++)  for(int j=0;j<=i;j++)  c[i]+=a[j]*b[i-j];
	for(int i=0;i<1010;i++)  if(c[i]>9)  {c[i+1]+=c[i]/10;  c[i]%=10;}
	int m=1009;
	while(c[m]==0)  m--;
	for(int i=m;i>=0;i--)  cout<<c[i];
	return 0;
}
