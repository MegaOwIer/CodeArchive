/*��Ŀ����:����n������n<=100���ҵ�������С������������
  ��������:��һ��һ������n,������һ��n��������ÿ������������2^31 -1
  �������:��С��������
  ��������:4
           1 2 3 4
  �������:1 4*/

#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;
int main()
{
	int n,a,max,min,i;
	scanf("%d%d",&n,&a);
	max=a;
	min=a;
	for(i=1;i<=n-1;i++)
	{scanf("%d",&a);
	 if(a>max) max=a;
	 else if(a<min) min=a;
	      else min=min;
	}

	printf("%d %d",min,max);
	
	return 0;
} 
