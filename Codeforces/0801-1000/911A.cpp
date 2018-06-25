#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;

int n,a[maxn],mn=2e9,ans=2e6;
vector<int> q;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),mn=min(mn,a[i]);
	for(int i=1;i<=n;i++)if(a[i]==mn)q.push_back(i);
	for(int i=1;i<q.size();i++)ans=min(ans,q[i]-q[i-1]);
	printf("%d",ans);
	return 0;
}
