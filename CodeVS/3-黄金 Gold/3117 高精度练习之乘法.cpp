/*��Ŀ����:��������������A��B,����A*B��ֵ��֤A��B��λ��������500λ
  ��������:���������ÿո������������
  �������:���A*B��ֵ
  ��������:3 12
  �������:36
  ���ݷ�Χ����ʾ:������������λ��������500λ*/

#include<iostream>
#include<cstring>
using namespace std;

string aa,bb;
int la,lb,a[501],b[501],c[1010];

int main()
{
	cin>>aa;  la=aa.length();
	cin>>bb;  lb=bb.length();
	for(int i=0;i<la;i++)  a[i]=aa[la-1-i]-'0';
	for(int i=0;i<lb;i++)  b[i]=bb[lb-1-i]-'0';
	for(int i=0;i<la+lb;i++)  for(int j=0;j<=i;j++)  c[i]+=a[j]*b[i-j];
	for(int i=0;i<1010;i++)  if(c[i]>9)  {c[i+1]+=c[i]/10;  c[i]%=10;}
	int m=1009;
	while(c[m]==0)  m--;
	for(int i=m;i>=0;i--)  cout<<c[i];
	return 0;
}
