/*��Ŀ��������������A��B�����Լ���� 1<=A,B<=2^31-1
  ������������������A��B
  ������������Լ��gcd(A,B)
  �������룺8 12
  ���������4*/ 

#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;

int main()
{
    int a,b,c,r,i;
    scanf("%d%d",&b,&c);
    if(b>c) {a=b;b=c;}
    else {a=c;b=b;}
    r=a%b;
    while(r!=0) {a=b;b=r;r=a%b;}
    printf("%d",b);
    
    return 0;
} 
