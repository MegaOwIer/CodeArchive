#include<bits/stdc++.h>
using namespace std;

struct matrix{int a[25][25];}g,e,res;
int n,m,k,next[25],ans;
char a[25];

inline matrix operator * (matrix a,matrix b)
{
	for(int i=0;i<m;i++)for(int j=0;j<m;j++)
	{
		res.a[i][j]=0;
		for(int l=0;l<m;l++)(res.a[i][j]+=a.a[i][l]*b.a[l][j])%=k;
	}
	return res;
}

int main()
{
	scanf("%d%d%d%s",&n,&m,&k,a+1);
	for(int i=2,j=0;i<=m;i++)
	{
		while(j&&a[j+1]!=a[i])j=next[j];
		if(a[j+1]==a[i])j++;
		next[i]=j;
	}
	for(int i=0,t;i<m;i++)for(int j=0;j<10;j++)
	{
		t=i;
		while(t&&a[t+1]-48!=j)t=next[t];
		if(a[t+1]-48==j)t++;
		if(t!=m)g.a[t][i]=(g.a[t][i]+1)%k;
	}
	for(int i=0;i<m;i++)e.a[i][i]=1;
	while(n)
	{
		if(n&1)e=e*g;
		g=g*g,n>>=1;
	}
	for(int i=0;i<m;i++)(ans+=e.a[i][0])%=k;
	printf("%d",ans);
	return 0;
}
