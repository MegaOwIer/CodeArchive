/*��Ŀ����:����һ��Ӣ����ӣ�ϣ����Ѿ�����ĵ���˳�򶼷�ת����
  ��������:�������һ��Ӣ����ӡ�
  �������:�����ʵ�˳��ѵ��ʵ������
  ��������:I love you
  �������:you love I*/

#include<cstring>
#include<iostream>
using namespace std;

int main()
{
	int m,n=0,cnt1=0,cnt2=0,cnt3=0;
	string st,str[100];
	getline(cin,st);
	m=st.length();
	for(int i=0;i<m;i++)
	{
	    cnt3++;
		if(st[i]==' ')
		{
		    cnt1++;
			str[cnt1]=st.substr(cnt2,cnt3-1);
			cnt2=i+1;
			cnt3=0;
        }
    }
    cnt1++;
	str[cnt1]=st.substr(cnt2,m-1);
    for(int i=cnt1;i>0;i--)  cout<<str[i]<<' ';
	return 0;
}
