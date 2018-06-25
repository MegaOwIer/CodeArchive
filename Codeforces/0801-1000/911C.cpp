#include<bits/stdc++.h>
using namespace std;
#define OK return puts("YES"),0
#define NO return puts("NO"),0

int k[5];

int main()
{
	for(int i=1;i<=3;i++)scanf("%d",k+i);
	sort(k+1,k+4);
	if(k[1]==1)OK;
	if(k[1]>=4)NO;
	if(k[1]==3)
	{
		if(k[2]==3&&k[3]==3)OK;
		else NO;
	}
	if(k[2]==2)OK;
	if(k[2]==4&&k[3]==4)OK;
	NO;
}
