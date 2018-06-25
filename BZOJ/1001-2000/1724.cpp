#include<bits/stdc++.h>
using namespace std;

int n,a,t1,t2;
long long ans;
char c;
priority_queue<int,vector<int>,greater<int> > q;

inline void read(int& x)
{
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a),q.push(a);
	for(int i=1;i<n;i++)
	t1=q.top(),q.pop(),t2=q.top(),q.pop(),ans+=t1+t2,q.push(t1+t2);
	printf("%lld",ans);
	return 0;
}
