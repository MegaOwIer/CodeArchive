#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=32770,mod=998244353,MN=50;
typedef int Array[MX];

namespace FastIO
{
	char c;
	int tp,bf[22];
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		tp=0;
		do bf[++tp]=x%10,x/=10;while(x);
		while(tp)putchar(48+bf[tp--]);
		putchar(' ');
	}
}
using FastIO::read;
using FastIO::write;

int N,P,M,K,X=1,rev[MX],pool[MX],vis[MN],num[MN],G[MX][MN],tmp[MX][MN],res;
LL _x,H[MN],_X;
Array w[2],A,F[MN];

inline int Pow(LL a,int b)
{
	LL ans=1;
	for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
	return ans;
}
inline void FFT(int *A,int r)
{
	for(int i=0;i<X;i++)if(i<rev[i])swap(A[i],A[rev[i]]);
	for(int i=1,l=X>>1;i<X;i<<=1,l>>=1)
		for(int j=0;j<X;j+=i*2)for(int k=0,l0=0;k<i;k++,l0+=l)
			_x=(LL)A[i+j+k]*w[r][l0]%mod,A[i+j+k]=(A[j+k]-_x+mod)%mod,A[j+k]=(A[j+k]+_x)%mod;
	if(r)for(int i=0;i<X;i++)A[i]=A[i]*_X%mod;
}
inline void _2DFFT(int A[][MN],int r)
{
	for(int i=0;i<X;i++)if(i<rev[i])swap(A[i],A[rev[i]]);
	for(int i=1,l=X>>1;i<X;i<<=1,l>>=1)
		for(int j=0;j<X;j+=i*2)for(int k=0,l0=0;k<i;k++,l0+=l)
			for(int u=0;u<P;u++)
			{
				_x=(LL)A[i+j+k][u]*w[r][l0]%mod;
				A[i+j+k][u]=(A[j+k][u]-_x+mod)%mod,A[j+k][u]=(A[j+k][u]+_x)%mod;
			}
	if(r)for(int i=0;i<X;i++)for(int u=0;u<P;u++)A[i][u]=A[i][u]*_X%mod;
}

int main()
{
	read(N),read(P),read(M);
	for(;X<=M+M;X<<=1,K++);
	_X=Pow(X,mod-2);
	for(int i=0;i<X;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<K-1);
	w[0][0]=1,w[0][1]=Pow(3,(mod-1)/X);
	for(int i=2;i<X;i++)w[0][i]=(LL)w[0][i-1]*w[0][1]%mod;
	memcpy(w[1],w[0],sizeof(int)*X),reverse(w[1]+1,w[1]+X);
	
	memset(vis,-1,sizeof(int)*M);
	for(int i=0,x=1%P,len,j;i<N;i++,x=x*10%P)
	{
		if(~vis[x])
		{
			len=i-vis[x];
			for(j=vis[x];j<i;j++)num[pool[j]]+=(N-i)/len;
			for(j=0;j<(N-i)%len;j++)num[pool[j+vis[x]]]++;
			break;
		}
		else vis[x]=i,pool[i]=x,num[x]++;
	}
	for(int i=0;i<P&&i<=M;i++)F[i][0]=1;
	for(int i=0;i<10&&i<=M;i++)A[i]=1;
	for(int i=0;i<=29;i++)
	{
		FFT(A,0);
		for(int w=0;w<P;w++)
		{
			if(num[w]&1)
			{
				FFT(F[w],0);
				for(int i=0;i<X;i++)F[w][i]=(LL)F[w][i]*A[i]%mod;
				FFT(F[w],1);
				memset(F[w]+M+1,0,sizeof(int)*(X-M));
			}
			num[w]>>=1;
		}
		for(int j=0;j<X;j++)A[j]=(LL)A[j]*A[j]%mod;
		FFT(A,1);
		memset(A+M+1,0,sizeof(int)*(X-M));
	}
	G[0][0]=1;
	for(int w=0;w<P;w++)
	{
		for(int i=0;i<=M;i++)tmp[i][i*w%P]=F[w][i];
		_2DFFT(G,0),_2DFFT(tmp,0);
		for(int i=0;i<X;i++)
		{
			memset(H,0,sizeof(LL)*P);
			for(int j=0;j<P;j++)for(int k=0;k<P;k++)
				H[j]=(H[j]+(LL)G[i][k]*tmp[i][(j-k+P)%P])%mod;
			for(int j=0;j<P;j++)G[i][j]=H[j];
		}
		_2DFFT(G,1);
		for(int i=M+1;i<X;i++)memset(G[i],0,sizeof(int)*P);
		for(int i=0;i<X;i++)memset(tmp[i],0,sizeof(int)*P);
	}
	for(int i=0;i<=M;i++)res=(res+G[i][0])%mod,write(res);
	return 0;
}
