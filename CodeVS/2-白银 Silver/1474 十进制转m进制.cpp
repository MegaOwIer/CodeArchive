/*��Ŀ����:��ʮ������nת����m������ m<=16 n<=100
  ��������:��һ��,n��m
  �������:��һ����,��ʾn��m����
  ��������:����1��10 2
           ����2:100 15
  �������:����1��1010
           ����2:6A
  ���ݷ�Χ����ʾ:�÷���ȡ�෨*/

#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int d[1000];

int main()
{
    int x,i=0,j,n;
    scanf("%d%d",&x,&n);
	while(x!=0)
    {
        i++;
        d[i]=x%n;
        x=x/n;
	}
    for(j=i;j>0;j--)  
	{
		if(d[j]<10)  	printf("%d",d[j]);
		else if(d[j]==10)  	cout<<"A";
		     else if(d[j]==11)  	cout<<"B";
		          else if(d[j]==12)  	cout<<"C";
		               else if(d[j]==13)  	cout<<"D";
		                    else if(d[j]==14)  	cout<<"E";
		                         else  cout<<"F";
	}
    return 0;
}
