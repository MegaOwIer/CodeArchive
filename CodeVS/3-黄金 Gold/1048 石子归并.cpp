/*��Ŀ����:��n��ʯ���ų�һ��,ÿ��ʯ����һ������w[i],ÿ�κϲ����Ժϲ����ڵ�����ʯ��,һ�κϲ��Ĵ���Ϊ����ʯ�ӵ�������w[i]+w[i+1]
           �ʰ��������ĺϲ�˳��,�ܹ�ʹ���ܺϲ����۴ﵽ��С
  ��������:��һ��һ������n(n<=100)
           �ڶ���n������w1,w2...wn (wi<=100)
  �������:һ��������ʾ��С�ϲ�����
  ��������:4
           4 1 1 4
  �������:18*/

#include<iostream>
#include<algorithm>
using namespace std;

int n,w[101],sum[101],p[101][101];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)  {cin>>w[i];  sum[i]=sum[i-1]+w[i];}
	for(int i=1;i<n;i++)  for(int j=1;i+j<=n;j++)
	{
		p[j][i+j]=0x7fffffff;
		for(int k=0;k<i;k++)  
		p[j][i+j]=min(p[j][i+j],p[j][j+k]+p[j+k+1][i+j]+sum[i+j]-sum[j-1]);
	}
	cout<<p[1][n];
	return 0;
}
