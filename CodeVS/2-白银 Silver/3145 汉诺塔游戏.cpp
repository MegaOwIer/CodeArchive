#include<iostream>
using namespace std;

int a,sum,cnt,flag;

int main()
{
	for(int i=1;i<=12;i++)
	{
		cin>>a;
		sum+=(300-a);
		cnt+=(sum/100);
		sum-=(sum/100*100);
		if(sum<0)  {cout<<-i;  flag=1;  break;}
	}
	if(flag==0)  cout<<sum+cnt*120;

	return 0;
}
