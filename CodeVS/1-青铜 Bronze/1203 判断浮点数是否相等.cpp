
/*��Ŀ����:���������������������ж��������������Ƿ���� 
  ��������:�����һ�У��������������� 
  �������:�����һ�У������������yes���������no�� 
  ��������:2.980000001 2.9800000000001 
  �������:yes 
  ���ݷ�Χ����ʾ:����һ����Ϊ������������ȣ����ҽ�������֮���������1e-8��*/ 

#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
int main()
{
	double x,y,z;
	scanf("%lf%lf",&x,&y);
	z=x-y;
	if(z>=0)
	  if(z<=1e-8)
	   printf("yes");
	  else 
	   printf("no");
	else
	  if(z>=-1e-8)
	   printf("yes");
	  else
	   printf("no");
	return 0;
  }
