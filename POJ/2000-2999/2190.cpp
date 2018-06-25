#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

char ch[13];
int num,sum;
bool fl;

int main()
{
	while(scanf("%s",ch)!=EOF)
	{
		fl=0;
	    for(int i=0;i<10;i++)  
	    {
	        if(ch[i]=='?')  num=i;
		    else  if(ch[i]=='X')  sum+=(10-i)*10;
		          else  sum+=(10-i)*(ch[i]-'0');
	    }
	    sum%=11;  num=10-num;
	    for(int i=0;i<10;i++)  {if(sum%11==0)  {cout<<i<<endl;  fl=1;  break;}  sum+=num;}
	    if(fl)  continue;
	    if(sum%11==0&&num==1)  {cout<<'X'<<endl;  continue;}
	    cout<<-1;
    }
	return 0;
}
