/*��Ŀ����:����һ��������������λ��
  ��������:����
           ��һ��Ϊ���ĸ���n
		   �ڶ���Ϊn������ÿ������֮����һ���ո����
  �������:һ�У�Ϊ����λ���������������������������С��������һλ
  ��������:4
           1 3 2 4
  �������:2.5
  ���ݷ�Χ����ʾ:����100%������:0<n<=20000,-10000<=a[n]<=10000*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int n,a[25000];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>a[i];
    sort(a+1,a+n+1);
    if(n%2==1)  cout<<a[n/2+1];
    else  printf("%.1lf",(a[n/2]+a[n/2+1])/2.0);
    return 0;
}
