/*��������:��һ������һ��������n��n<=30000
  �������:��������������������\t,�������\n
  ����������:13
  ���������:\t
  ����������:8
  ���������:\n
  ���ݷ�Χ����ʾ:c��c++�ĳ�ѧ��ע�⣬"��"����˼*/

#include<cstdio>
#include<cmath>
#include<iostream> 

using namespace std;

int main()
{
    int n,i,x,f=0;
    double a;
    scanf("%d",&n);
    a=sqrt(n);
    for(i=2;i<=a;i++)
    { 
        x=n%i;
        if(x==0) {std::cout << "\\n";f=1;break;}
    }
    if(f==0) std::cout << "\\t";

    return 0;
}
