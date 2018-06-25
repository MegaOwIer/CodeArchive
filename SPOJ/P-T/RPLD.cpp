#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

namespace FastIO
{
	char c;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
}
using FastIO::read;

int T,N,R;
pair<int,int> p[MX];
bool flag;

int main()
{
	read(T);
	for(int i=1;i<=T;i++)
	{
		printf("Scenario #%d: ",i);
		read(N),read(R),flag=0;
		for(int i=1,u,v;i<=R;i++)
			read(u),read(v),p[i]=make_pair(u,v);
		sort(p+1,p+R+1);
		for(int i=2;i<=R;i++)if(p[i]==p[i-1]){flag=1;break;}
		puts(flag?"impossible":"possible");
	}
}