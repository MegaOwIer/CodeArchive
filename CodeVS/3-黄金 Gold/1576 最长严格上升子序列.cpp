/*��Ŀ����:��һ������a1, a2 ... an���ҵ����������������ab1<ab2< .. <abk������b1<b2<..bk.������ȼ��ɡ�
  ��������:��һ��,һ������N
           �ڶ���,N������(N < = 5000)
  �������:���K�ļ���ֵ,������½������еĳ���
  ��������:5
           9 3 6 2 7
  �������:3
  ��������:����½�������Ϊ3,6,7*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n,a[5001],ans[5001];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)  cin>>a[i];
	ans[1]=1;
	for(int i=2;i<=n;i++)  for(int j=1;j<i;j++)  if(a[j]<a[i])
	{
		int m=ans[j]+1;
		ans[i]=m>ans[i]?m:ans[i];
	}
	sort(ans+1,ans+n+1,greater<int>());
	cout<<ans[1];
	return 0;
}
