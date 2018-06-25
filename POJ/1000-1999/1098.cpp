#include<iostream>
using namespace std;

int n,a[105],ar,sum,m,cnt;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)  {cin>>a[i];  sum+=a[i];}
	ar=sum/n;
	m=n/2;
	for(int i=1;i<=m;i++)
	{
		if(a[i]==ar)  continue;
		a[i+1]+=a[i]-ar;
		cnt++;
	}
	for(int i=1;i<=m;i++)
	{
		if(a[n+1-i]==ar)  continue;
		a[n-i]+=a[n+1-i]-ar;
		cnt++;
	}
	cout<<cnt;
	return 0;
}
