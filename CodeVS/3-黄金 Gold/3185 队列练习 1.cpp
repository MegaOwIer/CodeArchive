/*��Ŀ����:����һ������(��ʼΪ��),ֻ�����ֲ�����Ӻͳ���,�ָ�����Щ������������յĶ�ͷԪ��.��������:1��ʾ���,2��ʾ����
  ��������:N(��������)
           N������(������������滹����һ�����Ԫ��)
		   ���������(���뱣֤�ӿ�ʱ�������)
  �������:���ն�ͷԪ��,�����նӿ�,���"impossible!"(��������)
  ��������:3
           1 2
		   1 9
		   2
  �������:9
  ���ݷ�Χ����ʾ:����100%������N<=1000Ԫ�ؾ�Ϊ��������С�ڵ���100*/

#include<iostream>
#include<queue>
using namespace std;

queue<int> q;
int n,ord,no;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    cin>>ord;
	    if(ord-1)  q.pop();
	    else  {cin>>no;  q.push(no);}
	}
	if(q.empty())  cout<<"impossible!";
	else cout<<q.front();
	return 0;
}
