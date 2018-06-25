#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int N,K,A,B;
LL ans;

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin>>N>>K>>A>>B;
	if(K==1)
	{
		cout<<(LL)A*(N-1)<<endl;
		return 0;
	}
	while(N>1)
	{
		if(N<K)ans+=(LL)A*(N-1),N=1;
		else if(N%K||K==1)ans+=(LL)A*(N%K),N=N/K*K;
		else ans+=min((LL)B,(LL)A*(N-N/K)),N/=K;
	}
	cout<<ans<<endl;
	return 0;
}
