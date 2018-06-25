#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int mod=10007;

int N,L,N24,N25,N26,S,M,tmp,dp[200][200][205];
LL ans;
char s[205];
bool invilad;
struct Matrix
{
	int val[400][400];
	Matrix(){memset(val,0,sizeof(val));}
	int* operator[](int u){return val[u];}
	Matrix operator*(Matrix& a)
	{
		static LL tmp[400][400];
		static Matrix ans;
		for(int i=0;i<S;i++)for(int j=i;j<S;j++)tmp[i][j]=0;
		for(int i=0;i<S;i++)for(int k=i;k<S;k++)for(int j=k;j<S;j++)
			tmp[i][j]+=val[i][k]*a[k][j];
		for(int i=0;i<S;i++)for(int j=i;j<S;j++)ans[i][j]=tmp[i][j]%mod;
		return ans;
	}
	void init(){for(int i=0;i<S;i++)val[i][i]=1;}
}G,F;

inline void read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void prework()
{
	static int i;
	for(i=0;i<N24;i++)G[i][i]=24,G[i][i+1]=1;
	for(;i<N24+N25-1;i++)G[i][i]=25,G[i][i+1]=G[i][i+N25]=1;
	G[i][i]=25,G[i][i+N25]=1,i++;
	for(;i<S;i++)G[i][i]=26;
}
inline void Pow(Matrix a,int b)
{
	F.init();
	for(;b;b>>=1,a=a*a)if(b&1)F=F*a;
}
int DP(int l,int r,int n24)
{
	int& res=dp[l][r][n24];
	if(~res)return res;
	if(l==r)return res=(n24?0:1);
	res=0;
	if(s[l]==s[r])
		if(l+1==r)res=(n24?0:1);
		else res=DP(l+1,r-1,n24);
	else if(n24>0)
		res=DP(l+1,r,n24-1)+DP(l,r-1,n24-1);
	return res%=mod;
}

int main()
{
	cin>>s>>N;
	L=strlen(s),N+=L,M=N+1>>1;
	N24=L-1,N25=N26=L+1>>1;
	S=N24+N25+N26;
	prework(),Pow(G,M-1);
	G=F*G;
	memset(dp,-1,sizeof(dp));
	for(int i=0,j,k;i<L;i++)
	{
		j=(L-i+1)/2,invilad=~(L-i)&1,k=M-i-j;
		if(k<0)continue;
		tmp=DP(0,L-1,i);
		ans+=tmp*G[N24-i][N24+N25+j-1];
		if(invilad&&(N&1))
			ans+=mod*mod-tmp*F[N24-i][N24+j-1];
	}
	cout<<ans%mod<<endl;
	return 0;
}
