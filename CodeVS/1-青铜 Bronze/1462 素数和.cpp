/*��Ŀ����:����2������a,b �������֮�䣨����a��b�����������ĺ͡�
  ��������:һ�У�a b(0<=a,b<=65536)
  �������:һ�У�a,b֮��(����a��b)���������ĺ͡�
  ��������:39 1224
  �������:111390
  ���ݷ�Χ����ʾ:ע��û��Ҫ��a<b*/

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

long a,b,ans;
bool prime(int);

int main()
{
    cin>>a>>b;
    if(a>=b)  swap(a,b);
    for(int i=a+1;i<b;i++)  if(prime(i))  ans+=i;
    cout<<ans;
    return 0;
}
bool prime(int v)
{
     double m=sqrt(v);
     for(int i=2;i<=m;i++)  if(v%i==0)  return 0;
     return 1;
}
