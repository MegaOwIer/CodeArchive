/*��Ŀ����:��һ�ö�������ǰ���������������ͺ������
  ��������:��һ��һ������n����ʾ������Ľڵ������
           ������n��ÿ��2������L��R����i�е���������Li��Ri������Ϊi�Ľڵ������ӱ�ź��Ҷ��ӱ�š�
  �������:���һ�����У��ֱ�Ϊǰ���������������ͺ�����������֮���ÿո������
  ��������:5
           2 3
		   4 5
		   0 0
		   0 0
		   0 0
  �������:1 2 4 5 3
           4 2 5 1 3
		   4 5 2 3 1
  ���ݷ�Χ����ʾ:n <= 16*/

#include<iostream>
using namespace std;

int root[20],zuo[20],you[20],n;
void xian(int j)
{
	cout<<j<<' ';
	if(zuo[j]!=0)  xian(zuo[j]);
	if(you[j]!=0)  xian(you[j]);	
}
void zhong(int j)
{
    if(zuo[j]!=0)  zhong(zuo[j]);
	cout<<j<<' ';
	if(you[j]!=0)  zhong(you[j]);	
}
void hou(int j)
{
	if(zuo[j]!=0)  hou(zuo[j]);
	if(you[j]!=0)  hou(you[j]);
	cout<<j<<' ';	
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)  {root[i]=i;  cin>>zuo[i]>>you[i];}
	xian(1);cout<<endl;
	zhong(1);cout<<endl;
	hou(1);
	return 0;
}
