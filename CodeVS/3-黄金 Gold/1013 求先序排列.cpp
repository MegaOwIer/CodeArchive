/*��Ŀ����:����һ�ö��������������������.���������������(Լ��������ò�ͬ�Ĵ�д��ĸ��ʾ,����<=8).
  ��������:�����ַ���,�ֱ�������ͺ���(ÿ��һ��)
  �������:һ���ַ���,����
  ��������:BADC
           BDCA
  �������:ABCD  */

#include<iostream>
#include<cstring>
using namespace std;

string st1,st2;
void digui(string,string);

int main()
{
	cin>>st1>>st2;
	digui(st1,st2);
	return 0;
}
void digui(string u,string v)
{
	int l=v.length();
	if(l==1)  {cout<<u;  return;}
	cout<<v[l-1];
	int x=u.find(v[l-1]);
	string m,n;
	if(x!=0)  {m=u.substr(0,x);  n=v.substr(0,x);  digui(m,n);}
	if(x!=l-1)  {m=u.substr(x+1,l-1-x);  n=v.substr(x,l-1-x);  digui(m,n);}
}
