#include<iostream>
#include<cmath>
using namespace std;

int N,cnt;

int main()
{
	cin>>N;
	N*=2;
	for(int i=1;i*i<=N;i++)
	{
		if(N%i!=0)  continue;
		if((N/i+1-i)%2==1)  continue;
		cnt++;
	}
	cout<<cnt;
	return 0;
}
