/*��Ŀ����:��С��Ĵʻ�����С������ÿ����Ӣ��ѡ�����ʱ�򶼺�ͷ�ۡ��������ҵ���һ�ַ����������ַ���ȥѡ��ѡ���ʱ��ѡ�Եļ��ʷǳ���
           ���ַ����ľ����������£�����maxn�ǵ����г��ִ���������ĸ�ĳ��ִ�����minn�ǵ����г��ִ������ٵ���ĸ�ĳ��ִ�����
		   ���maxn-minn��һ����������ô��С�����Ϊ���Ǹ�Lucky Word�������ĵ��ʺܿ��ܾ�����ȷ�Ĵ𰸡�
  ��������:ֻ��һ�У���һ�����ʣ�����ֻ���ܳ���Сд��ĸ�����ҳ���С��100��
  �������:�����У���һ����һ���ַ�������������ĵĵ�����Lucky Word����ô�����Lucky Word�����������"No Answer";
           �ڶ�����һ��������������뵥����Lucky Word�����maxn-minn��ֵ���������0��
  ��������:����һ:error
           ������:olympic
  �������:����һ:Lucky Word
                  2
		   ������:No Answer
		          0*/

#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int a[30],mi=999,mx=-999,n;
string st;
int prime(int);

int main()
{
	cin>>st;
	for(int i=0;i<st.length();i++)  a[st[i]-'a'+1]++;
    for(int i=1;i<=26;i++)
    {
    	if(a[i]==0)  continue;
    	if(a[i]>mx)  mx=a[i];
    	if(a[i]<mi)  mi=a[i];
    }
    n=mx-mi;
	if(prime(n))  cout<<"Lucky Word"<<endl<<n;
	else  cout<<"No Answer\n0";
	return 0;
}
int prime(int v)
{
	if(v<2)  return 0;
	int u=sqrt(v);
	for(int i=2;i<=u;i++)  if(v%i==0)  return 0;
	return 1;
}
