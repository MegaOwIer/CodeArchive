/*��Ŀ����:(�����������ϰ1��ȸ���2��:1��ǿ������ 2����֤�ӿ�ʱ�������)
           ����һ������(��ʼΪ��),ֻ�����ֲ�����Ӻͳ���,�ָ�����Щ������
		   ������յĶ�ͷԪ��.��������:1��ʾ���,2��ʾ����
  ��������:N(��������)
           N������(������������滹����һ�����Ԫ��)
		   ���������(���뱣֤�ӿ�ʱ�������)
  �������:���ն�ͷԪ��,�����նӿ�,��ӿ�ʱ�г��Ӳ���,���"impossible!"(��������)
  ��������:3
           1 2
		   2
		   2
  �������:impossible!
  ���ݷ�Χ����ʾ:����100%������N��100000Ԫ�ؾ�Ϊ��������С�ڵ���10^8*/

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
	    if((ord-1)&&q.empty())  {cout<<"impossible!";  return 0;}
	    else  if((ord-1)&&!q.empty())  q.pop();
	    else  {cin>>no;  q.push(no);}
	}
	if(q.empty())  cout<<"impossible!";
	else cout<<q.front();
	return 0;
}
