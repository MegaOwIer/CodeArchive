/*题目描述:将m进制数n转化成一个十进制数 m<=16,题目保证转换后的十进制数<=100
  输入描述:共一行,n和m
  输出描述:共一个数，表示m进制的n化成十进制的数
  样例输入：1010 2
  样例输出：10*/ 

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
