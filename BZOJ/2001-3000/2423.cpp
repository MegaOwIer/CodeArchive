#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	char c;
	int top,bf[22];
	template<typename T>inline void read(T& x)
	{
		c=getchar(),x=0;
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do bf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+bf[top--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;
const int MX=5005,mod=100000000;

int n,m,f[2][MX],g[2][MX];
char A[MX],B[MX];

int main()
{
	scanf("%s%s",A+1,B+1);
	n=strlen(A+1)-1;
	m=strlen(B+1)-1;
	for(int i=0;i<=m;i++)g[0][i]=1;
	g[1][0]=1;
	for(int i=1,nw,l;i<=n;i++)
	{
		nw=i&1,l=nw^1;
		for(int j=1;j<=m;j++)
		{
			if(A[i]==B[j])
			{
				f[nw][j]=f[l][j-1]+1;
				g[nw][j]=g[l][j-1];
				if(f[nw][j]==f[l][j])g[nw][j]+=g[l][j];
				if(f[nw][j]==f[nw][j-1])g[nw][j]+=g[nw][j-1];
			}
			else
			{
				f[nw][j]=max(f[l][j],f[nw][j-1]);
				g[nw][j]=0;
				if(f[nw][j]==f[l][j])g[nw][j]+=g[l][j];
				if(f[nw][j]==f[nw][j-1])g[nw][j]+=g[nw][j-1];
				if(f[nw][j]==f[l][j-1])g[nw][j]+=mod-g[l][j-1];
			}
			g[nw][j]%=mod;
		}
	}
	write(f[n&1][m]),write(g[n&1][m]);
	return 0;	
}
