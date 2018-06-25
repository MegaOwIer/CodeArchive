/*题目描述:设有n个正整数（n≤20），将它们联接成一排，组成一个最大的多位整数。
  输入描述:第一行一个正整数n。第二行n个正整数，空格隔开。
  输出描述:连接成的多位数。
  样例输入:Sample 1:3
                    13 312 343
		   Sample 2:4
		            7 13 4 246
  样例输出:Sample 1:34331213
           Sample 2:7424613
  数据范围及提示:n≤20*/

#include<iostream>
#include<cstring>
using namespace std;

string st[25],a;
int m;

int main()
{
	cin>>m;
	for(int i=1;i<=m;i++)  cin>>st[i];
	for(int i=1;i<=m;i++)
	{
	    int lg1=st[i].length();
		for(int j=i+1;j<=m;j++)
	    {
	  	    int lg2=st[j].length();
	  	    int m=lg1<lg2?lg1:lg2;
	  	    if(lg1>lg2)  {a=st[i];  st[i]=st[j];  st[j]=a;}
	  	    lg2=st[j].length();
	  	    for(int k=0;k<=m;k++)
	  	    {
	  	    	if((k==m)&&(st[j][0]<st[j][lg2-1]))  {a=st[i];  st[i]=st[j];  st[j]=a;  break;}
	  	    	if((k==m)&&(st[j][0]>st[j][lg2-1]))  break;
				if(st[i][k]==st[j][k])  continue;
	  	    	if(st[i][k]>st[j][k])  break;
	  	    	if(st[i][k]<st[j][k])  {a=st[i];  st[i]=st[j];  st[j]=a;  break;}
	  	    } 
	  	}
	}
	for(int i=1;i<=m;i++)  cout<<st[i];
	return 0;
}
