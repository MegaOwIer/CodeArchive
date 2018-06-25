#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	static int buf[22],top;
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
}
using FastIO::read;
const int mod=10260817,maxn=100005;

struct Ques{int id,l,r,hash;}q[maxn];
int N,M,K,a[maxn],cnt,num[maxn],ord,pos[maxn],blc;
unsigned pw=1,hash[maxn],ls[maxn],tmp;
bool ans[maxn];

inline bool operator < (Ques a,Ques b){return pos[a.l]<pos[b.l]||(pos[a.l]==pos[b.l]&&a.r<b.r);}

int main()
{
	read(N),read(M),read(K),blc=sqrt(N)+1;
	for(int i=1;i<=N;i++)read(a[i]),pos[i]=i/blc;
	for(int i=1;i<=K;i++)pw*=mod;
	for(int i=1;i<=N;i++)hash[i]=hash[i-1]*mod+a[i];
	for(int i=K;i<=N;i++)ls[i-K+1]=hash[i]-hash[i-K]*pw;
	for(int i=1;i<=N-K+1;i++)hash[i]=ls[i];
	sort(ls+1,ls+N-K+2);
	for(int i=1;i<=N-K+1;i++)hash[i]=lower_bound(ls+1,ls+N-K+2,hash[i])-ls;
	for(int i=1,l,r,e;i<=M;i++)
	{
		read(l),read(r),tmp=0;
		for(int j=1;j<=K;j++)read(e),tmp=tmp*mod+e;
		ord=lower_bound(ls+1,ls+N-K+2,tmp)-ls;
		if(ls[ord]==tmp)q[++cnt]=(Ques){i,l,r-K+1,ord};
	}
	for(int i=1,l=0,r=0;i<=cnt;i++)
	{
		while(l<q[i].l)num[hash[l++]]--;
		while(l>q[i].l)num[hash[--l]]++;
		while(r<q[i].r)num[hash[++r]]++;
		while(r>q[i].r)num[hash[r--]]--;
		ans[q[i].id]=num[q[i].hash];
	}
	for(int i=1;i<=M;i++)puts(!ans[i]?"Yes":"No"); 
	return 0;
}
