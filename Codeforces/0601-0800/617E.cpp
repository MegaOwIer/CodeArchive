#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=100005;

int N,M,K,a[MX],pos[MX],B,cnt[1048600];
LL ans[MX],res;

struct Ques
{
	int l,r,id;
	bool operator < (const Ques& a)const{return pos[l]==pos[a.l]?r<a.r:pos[l]<pos[a.l];}
}q[MX];

inline void read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
	read(N),read(M),read(K),B=1+pow(N,0.5);
	for(int i=1;i<=N;i++)read(a[i]),a[i]^=a[i-1];
	for(int i=1;i<=N;i++)pos[i]=i/B;
	for(int i=1,l,r;i<=M;i++)read(l),read(r),q[i]=(Ques){l-1,r,i};
	sort(q+1,q+M+1),cnt[0]=1;
	for(int i=1,l=0,r=0;i<=M;i++)
	{
		while(r<q[i].r)++r,res+=cnt[a[r]^K],cnt[a[r]]++;
		while(r>q[i].r)cnt[a[r]]--,res-=cnt[a[r]^K],r--;
		while(l<q[i].l)cnt[a[l]]--,res-=cnt[a[l]^K],l++;
		while(l>q[i].l)--l,res+=cnt[a[l]^K],cnt[a[l]]++;
		ans[q[i].id]=res;
	}
	for(int i=1;i<=M;i++)printf("%lld\n",ans[i]);
	return 0;
}