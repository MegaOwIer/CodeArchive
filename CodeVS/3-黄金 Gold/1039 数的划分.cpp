/*��Ŀ����:������n�ֳ�k��,��ÿ�ݲ���Ϊ��,�������ֻ��ַ���������ͬ(������˳��)
           ����:n=7,k=3,�������ֻ��ַ�������Ϊ����ͬ��(1 1 5),(1 5 1),(5 1 1)
		   ���ж����ֲ�ͬ�ķַ�
  ��������:n,k(6<n<=200��2<=k<=6)
  �������:һ������,����ͬ�ķַ�
  ��������:7 3
  �������:4
  ���ݷ�Χ����ʾ:���ַַ�Ϊ:(1,1,5)(1,2,4)(1,3,3)(2,2,3)*/

#include<iostream>
using namespace std;

int m,n,cnt;
void divide(int,int,int);

int main()
{
	cin>>m>>n;
	divide(m,n,1);
	cout<<cnt;
	return 0;
}
void divide(int u,int v,int st)
{
	if(v==2)  {cnt+=(u/2-st+1)>0?(u/2-st+1):0;  return;}
	for(int i=st;i<=u/2;i++)  
	divide(u-i,v-1,i);
}
