/*��Ŀ����:����һ������ΪN�����ִ���Ҫ��ѡ��ʹ��K���˺Ž����ֳ�K+1�����֣��ҳ�һ�ַַ���ʹ����K+1�����ֵĳ˻��ܹ�Ϊ���
           ���磬��һ�����ִ���312�� ��N=3��K=1ʱ�����������ַַ���1)  3*12=36
		                                                           2)  31*2=62
		   ��ʱ��������ĿҪ��Ľ���ǣ�31*2=62
  ��������:��������빲�����У���һ�й���2����Ȼ��N,K(6��N��40,1��K��6),�ڶ�����һ������ΪN�����ִ���
  �������:�����ʾ����Ļ�ϣ���������룬Ӧ�������õ����˻���һ����Ȼ������
  ��������:4 2
           1231
  �������:62*/

#include<iostream>
#include<string>
using namespace std;

string str,st1,st2;
long mx,f[100][100],n,km;

int zhuan(int u,int v)
{
	int y=0;
	for(int i=u;i<=v;i++)  y=y*10+str[i]-'0';
	return y;
}

int main()
{
	cin>>n>>km>>str;
	for(int i=1;i<n;i++)
	{
		mx=0;
		for (int j=0;j<i;j++)
		{
			long q=zhuan(0,j)*zhuan(j+1,i);
		    mx=q>mx?q:mx;
		}
	    f[1][i]=mx;
	}
	for(int s=2;s<=n;s++)
	{
		for(int i=s;i<=n;i++)
		{
			mx=0;
			for(int j=1;j<=i;j++)
			{
				long q=f[s-1][j]*zhuan(j+1,i);
				mx=q>mx?q:mx;
			}
		    f[s][i]=mx;
		}
	}
	cout<<f[km][n-1];
    return 0;
}
