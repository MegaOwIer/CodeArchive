/*��Ŀ����:ͬѧ��������ʱ���������ֺ���
           f(x)=5 (x>=0)
           f(x)=f(x+1)+f(x+2)+1 (x<0)
           ��������������Ϊ����һ���ݹ�����
  ��������:һ����x
  �������:һ������ʾֵ
  ��������:����һ��0
           ��������-5
  �������:����һ��5
           ��������77*/

#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int x,n;

int f(int x)
{
	if(x>=0)  return 5;
	else return f(x+1)+f(x+2)+1;
}

int main()
{
	cin>>n;
	cout<<f(n);
	
	return 0;
}
