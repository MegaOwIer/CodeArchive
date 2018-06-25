/*题目描述:津津的零花钱一直都是自己管理。每个月的月初妈妈给津津300元钱，津津会预算这个月的花销，并且总能做到实际花销和预算的相同。
           为了让津津学习如何储蓄，妈妈提出，津津可以随时把整百的钱存在她那里，到了年末她会加上20％还给津津。
		   因此津津制定了一个储蓄计划：每个月的月初，如果她预计到这个月的月末手中还会有多于100元或恰好100元，她就会把整百的钱存在妈妈那里，剩余的钱留在自己手中。
		   津津发现这个储蓄计划的主要风险是，存在妈妈那里的钱在年末之前不能取出。有可能在某个月的月初，津津手中的钱加上这个月妈妈给的钱，不够这个月的原定预算。
		   如果出现这种情况，津津将不得不在这个月省吃俭用，压缩预算。
		   现在请你根据2004年1月到12月每个月津津的预算，判断会不会出现这种情况。如果不会，计算到2004年年末，妈妈将津津平常存的钱加上20％还给津津之后，津津手中会有多少钱。
  输入描述:输入包括12行数据，每行包含一个小于350的非负整数，分别表示1月到12月津津的预算。
  输出描述:输出包括一行，只包含一个整数。如果储蓄计划实施过程中出现某个月钱不够用的情况，输出-X，X表示出现这种情况的第一个月；否则输出到年末津津手中会有多少钱。
  样例输入:样例1:290
                 230
				 280
				 200
				 300
				 170
				 340
				 50 
				 90 
				 80 
				 200
				 60 
           样例2:290
		         230 
				 280 
				 200 
				 300 
				 170 
				 330 
				 50 
				 90 
				 80 
				 200 
				 60 
  样例输出:样例1:-7 
           样例2:1580*/

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
