/*��Ŀ����:��֪Sn= 1��1��2��1��3������1��n����������һ������K����n�㹻���ʱ��Sn����K���ָ���һ������K��1<=k<=15����Ҫ������һ����С��n��ʹ��Sn��K��
  ��������:�������� k
  �������:��Ļ��� n
  ��������:1
  �������:2*/

#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	int i=0,n;
	double s=0;
	cin>>n;
	while(s<=n)
	{
		i++;
		s+=1.0/i;
	}
	cout<<i;
	
	return 0;
}
