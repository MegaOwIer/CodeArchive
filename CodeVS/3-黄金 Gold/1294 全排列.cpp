/*��Ŀ����:����һ��n, �����n������ȫ����
  ��������:�����һ������n   (1<=n<=10)
  �������:һ��n!�У�ÿ��n���ÿո������������ʾn��һ��ȫ���С����Ұ�ȫ���е��ֵ��������
  ��������:3
  �������:1 2 3
           1 3 2
		   2 1 3
		   2 3 1
		   3 1 2
		   3 2 1*/

#include<iostream>
using namespace std;

int a[11],b[11],k;

void yz(int i)
{
	int j;
	if(i>k)  {for(int m=1;m<=k;m++)  printf("%d ",a[m]);  printf("\n");}
	else 
	for(j=1;j<=k;j++)  if(b[j]==0)
	                   {
		                   a[i]=j; 
					       b[j]=1;
		                   yz(i+1);
		                   b[j]=0;
		               }
} 

int main()
{
	cin>>k;
	yz(1);
	
	return 0;
}
