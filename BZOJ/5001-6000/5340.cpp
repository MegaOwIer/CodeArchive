#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=205,mod=998244353;

namespace FastIO
{
	const int MXL=200000;
	struct FastIn
	{
		char bf[MXL],*p1,*p2,c;
		FILE *I;
		FastIn(FILE *I):p1(bf),p2(bf),I(I){}
		char getchar(){return p1==p2?(p2=(p1=bf)+fread(bf,1,MXL,I),p1==p2?EOF:*p1++):*p1++;}
		int operator () ()
		{
			static int c,x;
			x=0,c=getchar();
			while(!isdigit(c))c=getchar();
			while(isdigit(c))x=x*10+c-'0',c=getchar();
			return x;
		}
	};
	struct FastOut
	{
		char bf[MXL],*p1,*p2;
		FILE *O;
		FastOut(FILE *O):p1(bf),p2(bf+MXL),O(O){}
		~FastOut(){flush(),fclose(O);}
		void flush(){fwrite(bf,1,p1-bf,O),p1=bf;}
		void putchar(char c){*p1++=c;if(p1==p2)flush();}
		void operator () (int x,int f=0)
		{
			static int top,bf[12];
			bf[top=1]=(f?' ':'\n')-48;
			do bf[++top]=x%10,x/=10;while(x);
			while(top)putchar(48+bf[top--]);
		}
	};
}

int N,Q,inv[MX],dp[MX][103],f[205],g[205],id[205];
FastIO::FastIn IN(stdin);
FastIO::FastOut OUT(stdout);

int getinv(int u)
{
	if(u<=1)return u;
	return LL(mod-mod/u)*getinv(mod%u)%mod;
}
inline int getval(int u,int v){return (LL)u*getinv(v)%mod;}
void update(int *dp,int p)
{
    int _p=mod+1-p;
    for(int i=1;i<=100;i++)
    {
        dp[i-1]=(dp[i-1]+(LL)dp[i]*p)%mod;
        dp[i]=(LL)dp[i]*_p%mod;
    }
}
int calc(int u,int N)
{
    int ans=0,p,_p;
    _p=dp[u][0],p=mod+1-_p;
    if(!_p)memcpy(g,f+1,sizeof(int)*N);
    else
    {
        int inv=getinv(_p);
        g[0]=(LL)f[0]*inv%mod;
        for(int i=0;i<N;i++)
            g[i]=(f[i]-(LL)g[i-1]*p%mod+mod)*inv%mod;
    }
    for(int i=0;i<N;i++)
        ans=(ans+(LL)p*inv[i+1]%mod*g[i])%mod;
    return ans;
}
void solve(int N)
{
    for(int i=1;i<=N;i++)id[i]=IN();
    memset(f+1,0,sizeof(int)*N),f[0]=1;
    for(int i=1,p,_p;i<=N;i++)
    {
        _p=dp[id[i]][0],p=1+mod-_p;
        for(int j=i-1;j>=0;j--)
        {
            f[j+1]=(f[j+1]+(LL)f[j]*p)%mod;
            f[j]=(LL)f[j]*_p%mod;
        }
    }
    for(int i=1;i<=N;i++)OUT(calc(id[i],N),i!=N);
}

int main()
{
	N=IN();
	inv[1]=1;
	for(int i=2;i<=N;i++)inv[i]=LL(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=N;i++)dp[i][IN()]=1;
	Q=IN();
	for(int i=1,id,u,v;i<=Q;i++)
		if(IN())solve(IN());
		else id=IN(),u=IN(),v=IN(),update(dp[id],getval(u,v));
	for(int i=1;i<=N;i++)
    {
        LL ans=0;
        for(int j=0;j<=100;j++)ans+=(LL)dp[i][j]*j;
        OUT(ans%mod,i!=N);
    }
	return 0;
}