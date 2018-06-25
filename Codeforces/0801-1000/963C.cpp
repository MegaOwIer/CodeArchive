#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pll;
const int MX=200005;

int N,cx,cy;
map<LL,int> dx,dy;
map<int,LL> cnt[MX];
LL a,b,c,d1,d2;

inline LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
inline int solve(LL a,LL b,LL P)
{
	int ans=0;
	for(LL i=1,j;i*i<=P;i++)if(P%i==0)
	{
		j=P/i;
		if(a%i==0&&b%j==0)ans++;
		if(i!=j&&a%j==0&&b%i==0)ans++;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>a>>b>>c;
		if(!dx.count(a))dx[a]=++cx;
		if(!dy.count(b))dy[b]=++cy;
		cnt[dx[a]][dy[b]]=c;
	}
	for(int i=1;i<=cx;i++)if(cnt[i].size()!=cy)return puts("0"),0;
	for(int i=1;i<=cx;i++)for(int j=1;j<=cy;j++)
	{
		LL p00=cnt[1][1],p10=cnt[i][1],p01=cnt[1][j],p11=cnt[i][j];
		LL d0=gcd(p00,p10),d1=gcd(p01,p11);
		if(p00/d0!=p01/d1||p10/d0!=p11/d1)
			return puts("0"),0;
	}
	d1=d2=cnt[1][1];
	for(int i=1;i<=cx;i++)d1=gcd(d1,cnt[i][1]);
	for(int i=1;i<=cy;i++)d2=gcd(d2,cnt[1][i]);
	cout<<solve(d1,d2,cnt[1][1])<<endl;
	return 0;
}