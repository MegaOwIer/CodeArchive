/*��Ŀ����:ʵ�ִ�С��������
  ��������:��һ��һ������n
           �ڶ���n��������ÿ���ÿո�������
  �������:��С�����������ݣ�ÿ��һ������n�С�
  ��������:6
           1
		   2
		   5
		   4
		   3
		   2
  �������:1
           2
		   2
		   3
		   4
		   5
  ���ݷ�Χ����ʾ:��򵥵����򣬹���ѧ����ϰ����Ҫ��̫����,n<=12*/

#include<iostream>
#include<algorithm>
using namespace std;

int n,a[15];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>a[i];
    sort(a+1,a+n+1,less<int>());
    for(int i=1;i<=n;i++)  cout<<a[i]<<endl;
    return 0;
}
