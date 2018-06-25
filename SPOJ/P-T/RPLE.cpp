#include<bits/stdc++.h>
using namespace std;
const int MX=1005;

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
char l[MX],r[MX];
bool flag;

int main()
{
	read(T);
	for(int i=1;i<=T;i++)
	{
		printf("Scenario #%d: ",i);
		read(N),read(R),flag=0;
		memset(l+1,0,sizeof(char)*N);
		memset(r+1,0,sizeof(char)*N);
		for(int i=1,u,v;i<=R;i++)
			read(u),read(v),l[u]=1,r[v]=1;
		for(int i=1;i<=N;i++)if(l[i]&&r[i]){flag=1;break;}
		puts(flag?"spied":"spying");
	}
}