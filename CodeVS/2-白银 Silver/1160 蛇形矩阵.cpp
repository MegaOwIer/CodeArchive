/*��Ŀ����:ȡһ��n��n�����־���(����nΪ������100������),�ھ������Ĵ�1��ʼ����ʱ�뷽������,��Ȧ����,ֱ��n��n����������,�������n��n�������ξ����Լ���ĶԽ�������֮��.
  ��������:n����n��n�У�
  �������:n+1�У�n��Ϊ��ɵľ������һ��Ϊ�Խ�������֮��
  ��������:3
  �������:5 4 3
           6 1 2
		   7 8 9
		   25*/

#include<iostream>
using namespace std;

int n,a[100][100],l,m,sum;

int main()
{
	cin>>n;
	a[(n+1)/2][(n+1)/2]=1;
	l=m=(n+1)/2;
	for(int i=1;i<=(n-1)/2;i++)
	{
		for(int j=1;j<=2*i-1;j++)  {a[l][m+1]=a[l][m]+1;  m++;}
		for(int j=1;j<=2*i-1;j++)  {a[l-1][m]=a[l][m]+1;  l--;}
		for(int j=1;j<=2*i;j++)  {a[l][m-1]=a[l][m]+1;  m--;}
		for(int j=1;j<=2*i;j++)  {a[l+1][m]=a[l][m]+1;  l++;}
	}
	for(int i=1;i<=n-1;i++)  {a[l][m+1]=a[l][m]+1;  m++;}
	for(int i=1;i<=n;i++)  {for(int j=1;j<=n;j++)  cout<<a[i][j]<<' ';  cout<<endl;}
	for(int i=1;i<=n;i++)  sum+=a[i][i]+a[i][n+1-i];
	cout<<sum-1;
	return 0;
} 
