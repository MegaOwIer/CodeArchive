/*��Ŀ����:С���Ǹ��ܰ�˼���ĺ��ӣ���һ��������һ�����֣���������ֻ�ܱ�1�ͱ�������������
           2,3,5,7�����ڸ���һ�����֣����ܰ����ж��Ƿ���������������Ǿ����1��Ȼ���0
  ��������:����1:5
                 2 3 4 5 6
		   ����2:10
		         5 6 15 87 2 2 5 5 4 2 
  �������:���1:1 1 0 1 0
           ���2: 1 0 0 1 1 1 1 1 0 1
  ���ݷ�Χ����ʾ:1<=n<=100000*/ 

#include<iostream>
#include<cmath>
using namespace std;

int n,a;

int prime(int v)
{
    if(v==2)  return 1;
    if(v<=1)  return 0;
    else  {
              int m=sqrt(a),fl=0;
              for(int j=2;j<=m;j++)  if(a%j==0)  return 0;
          }
    return 1;
} 
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        cout<<prime(a)<<' ';
    }
    return 0;
}
