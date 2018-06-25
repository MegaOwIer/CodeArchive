#include<bits/stdc++.h>
using namespace std;

int n,q,a,k,v;
char c;
map<int,vector<int> >cnt;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
	while(~scanf("%d%d",&n,&q))
	{
		for(int i=1;i<=n;i++)read(a),cnt[a].push_back(i);
		while(q--)
		{
			read(k),read(v);
			if(cnt[v].size()<k)puts("0");
			else printf("%d\n",cnt[v][k-1]);
		}
	}
	return 0;
}
