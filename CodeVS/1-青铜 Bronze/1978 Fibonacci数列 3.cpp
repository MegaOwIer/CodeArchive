/*��Ŀ����:쳲������������㣺fn = fn-1 + fn-2
           ����һ������n,��fn
  ��������:һ������n, n<= 40
  �������:һ������fn
  ��������:3
  �������:2
  ���ݷ�Χ����ʾ:n<=40*/ 

#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int a[50],n,i;

int main()
{
   a[1]=1;a[2]=1;
   for(i=3;i<=50;i++)  a[i]=a[i-1]+a[i-2];
   cin>>n;
   cout<<a[n];
   
   return 0;
}
