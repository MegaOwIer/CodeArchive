#include<bits/stdc++.h>
using namespace std;
const int MX=1000005;

int d[MX],ans=1e9,X;

int main()
{
	cin>>X;
	for(int i=2;i<=X;i++)if(!d[i])
		for(int j=i;j<=X;j+=i)d[j]=i;
	for(int i=X-d[X]+1;i<=X;i++)
		if(d[i]!=i)ans=min(ans,i-d[i]+1);
	cout<<ans<<endl;
	return 0;
}
