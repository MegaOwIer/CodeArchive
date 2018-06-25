#include<bits/stdc++.h>
using namespace std;
const int MX=105;

int N,a[MX],ans=2147483647,d;

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin>>N>>d;
	for(int i=1;i<=N;i++)cin>>a[i];
	a[++N]=2147483647;
	sort(a+1,a+N+1);
	for(int i=1;i<N;i++)
		ans=min(ans,(i-1)+N-(upper_bound(a+1,a+N+1,a[i]+d)-a));
	cout<<ans<<endl;
	return 0;
}
