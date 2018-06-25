#include<bits/stdc++.h>
using namespace std;

int N,ans,T;
priority_queue<int> q;
struct data
{
	int t,ed;
	bool operator<(const data& a)const{return ed<a.ed;}
}d[150005];

inline void read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
	read(N);
	for(int i=1;i<=N;i++)read(d[i].t),read(d[i].ed);
	sort(d+1,d+N+1);
	for(int i=1;i<=N;i++)
		if(T+d[i].t<=d[i].ed)
			ans++,T+=d[i].t,q.push(d[i].t);
		else if(d[i].t<q.top())
			T-=q.top()-d[i].t,q.pop(),q.push(d[i].t);
	printf("%d\n",ans);
	return 0;
}
