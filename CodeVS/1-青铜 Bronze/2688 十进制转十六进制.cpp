/*��������:����һ��ʮ����n��
  �������:���һ��ʮ������x��
  ��������:20
  �������:14
  ���ݷ�Χ����ʾ:n<=1000000*/

#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int a,i;
string b;

int main()
{
    cin>>a;
    while(a!=0)
    {
       i++;
       int m=a%16;
       if(m<10)  b[i]='0'+m;
       else switch(m)
            {
                case 10: b[i]='A';  break;
                case 11: b[i]='B';  break;
                case 12: b[i]='C';  break;
                case 13: b[i]='D';  break;
                case 14: b[i]='E';  break;
                case 15: b[i]='F';  break;
            }
       a/=16;
    }
    for(int j=i;j>0;j--)  cout<<b[j];
    return 0;
}
