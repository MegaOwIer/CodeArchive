#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct matrix
{
	LL a[3][3];
	matrix(){memset(a,0,sizeof(a));}
	void init()
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<3;i++)a[i][i]=1;
	}
}g,ans,mrs;
int mod;
LL n,tmp[3];
char c;

template<typename T>
inline void read(T& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
matrix operator * (matrix a,matrix b)
{
	for(int i=0;i<3;i++)for(int j=0;j<3;j++)
	{
		mrs.a[i][j]=0;
		for(int k=0;k<3;k++)mrs.a[i][j]+=a.a[i][k]*b.a[k][j];
		mrs.a[i][j]%=mod;
	}
	return mrs;
}
inline void Pow(matrix A,LL b)
{
	while(b)
	{
		if(b&1)ans=A*ans;
		A=A*A,b>>=1;
	}
}

int main()
{
	read(n),read(mod),n++;
	ans.init();
	g.a[0][1]=g.a[1][1]=g.a[1][2]=g.a[2][2]=1;
	for(LL now=10,pre=1;;pre=now,now*=10)
	{
		g.a[0][0]=now%mod;
		Pow(g,min(now,n)-pre);
		if(now>=n)break;
	}
	printf("%lld",(ans.a[0][1]+ans.a[0][2])%mod);
	return 0;
}
