/*��Ŀ����:��m������nת����һ��ʮ������ m<=16,��Ŀ��֤ת�����ʮ������<=100
  ��������:��һ��,n��m
  �������:��һ��������ʾm���Ƶ�n����ʮ���Ƶ���
  �������룺1010 2
  ���������10*/ 

#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int m,a,i,b=0,c=1;

int main()
{
	string st;
	cin>>st>>m;
	a=st.length();
	if(m<=10)   for(i=1;i<=a;i++)  {b+=(st[a-i]-'0')*c;   c=c*m;}
	  else  for(i=1;i<=a;i++)
	        {
	        	if(st[a-i]=='A')    b+=10*c;
	        	  else if(st[a-i]=='B')    b+=11*c;
	        	       else if(st[a-i]=='C')    b+=12*c;
	        	            else if(st[a-i]=='D')    b+=13*c;
	        	                 else if(st[a-i]=='E')    b+=14*c;
	        	                      else if(st[a-i]=='F')    b+=15*c;
	        	                           else b+=(st[a-i]-'0')*c;
	            c=c*m;
	        }
    cout<<b;
    
    return 0;	
}
