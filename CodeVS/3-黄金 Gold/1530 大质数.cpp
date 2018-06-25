/*��Ŀ����:�ҳ���n������
  ��������:һ��������n(1<=n<=100000)
  �������:��n������
  ��������:����1:2
           ����2:65
		   ����3:20133
  �������:����1:3
           ����2:313
		   ����3:226381*/

#include<iostream>
#include<cmath>
using namespace std;

const int maxn=100005;
int n[maxn],m,cnt=5;
bool prime(int);

int main()
{
	cin>>m;
	n[1]=2;n[2]=3;n[3]=5;n[4]=7;
	for(int i=11;cnt<=m;i+=2)  if(prime(i))  n[cnt++]=i;
	cout<<n[m];
	return 0;
}
bool prime(int v)
{
	int m=sqrt(v);
	for(int i=2;n[i]<=m;i++)  if(v%n[i]==0)  return 0;
	return 1;
}
