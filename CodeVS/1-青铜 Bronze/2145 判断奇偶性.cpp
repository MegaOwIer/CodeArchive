/*��Ŀ����:�жϺ���y=x^n�η�����ż�������溯�������ji,ż�������ou
  ��������:һ������n
  �������:һ��,�����
  ��������:2
  �������:ou
  ���ݷ�Χ����ʾ:nΪ������*/

#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

string n;

int main()
{
    cin>>n;
    int m=n.length();
    int x=n[m-1];
    if(x%2==0)  cout<<"ou";
    else  cout<<"ji";
    return 0;
}
