/*��Ŀ����:��������(L, R),Ѱ���ڴ������ڵ�����
  ��������:������(L, R)�е�����L,R
  �������:�ڴ����������������ĸ���n
  ��������:0 100
  �������:25
  ���ݷ�Χ����ʾ:������������,L,R<=21000,���䳤��R-L<=4000*/

#include<iostream>
#include<cmath>
using namespace std;

int a,b,ans;

int prime(int v)
{
    if(v==2)  return 1;
    if(v<=1)  return 0;
    else  {
              int m=sqrt(v),fl=0;
              for(int j=2;j<=m;j++)  if(v%j==0)  return 0;
          }
    return 1;
}

int main()
{
    cin>>a>>b;
    for(int i=a+1;i<b;i++)  ans+=prime(i);
    cout<<ans;
    return 0;
}
