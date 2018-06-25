#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;

int n,k,p,lst[maxn],cnt,a[maxn],nxt[maxn],ans;
char c;
bool inq[maxn];
priority_queue<pair<int,int>,vector<pair<int,int> > > q;

inline void read(int& x)
{
	x=0,c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}

int main()
{
	read(n),read(k),read(p);
	for(int i=1;i<=n;i++)lst[i]=p+1;
	for(int i=1;i<=p;i++)read(a[i]);
	for(int i=p;i;i--)nxt[i]=lst[a[i]],lst[a[i]]=i;
	for(int i=1;i<=p;i++)
	{
		if(inq[a[i]]){q.push(make_pair(nxt[i],a[i]));continue;}
		if(k)ans++,q.push(make_pair(nxt[i],a[i])),inq[a[i]]=1,k--;
		else
		{
			while(!inq[q.top().second])q.pop();
			inq[q.top().second]=0,q.pop();
			ans++,q.push(make_pair(nxt[i],a[i]));
			inq[a[i]]=1;
		}
	}
	printf("%d",ans);
	return 0;
}
