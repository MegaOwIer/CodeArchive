/*��Ŀ����:����n�������������ƴ�����ٸ����硰A+B=C���ĵ�ʽ����ʽ�е�A��B��C���û���ƴ�������������������㣬�����λ������0����
           ע��:1.�Ӻ���ȺŸ�����Ҫ��������
		        2.���A��B����A+B=C��B+A=C��Ϊ��ͬ�ĵ�ʽ��A��B��C>=0��
				3.n����������ȫ������
  ��������:�����ļ���һ�У���һ������n��n<=24����
  �������:����ļ���һ�У���ʾ��ƴ�ɵĲ�ͬ��ʽ����Ŀ��
  ��������:����1:14
           ����2:18
  �������:����1:2
           ����2:9*/

#include<iostream>
#include<cstring>
using namespace std;

int stick[10]={6,2,5,5,4,5,6,3,7,6},cnt,num;
int sum(int);

int main()
{
	cin>>num;
	num-=4;
	for(int i=0;i<999;i++)
	  for(int j=0;j<999;j++)
	    if(sum(i)+sum(j)+sum(i+j)==num)  cnt++;
    cout<<cnt;
}

int sum(int v)
{
	if(v<10)  return  stick[v];
	else if(v<100)  return  stick[v/10]+stick[v%10];
	else  return  stick[v/100]+stick[v/10%10]+stick[v%10];
}
