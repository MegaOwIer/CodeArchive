#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	static char c;
	template<typename T>
	inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
}
using FastIO::read;
const int maxn=1e5+5;

struct Ques{int l,r,id,ans[4];}q[maxn];
int n,m,pos[maxn],blc,a[maxn],ans[4];

bool operator < (Ques a,Ques b){return pos[a.l]<pos[b.l]||(pos[a.l]==pos[b.l]&&a.r<b.r);}
bool operator > (Ques a,Ques b){return a.id<b.id;}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	blc=sqrt(n)+1;
	for(int i=1;i<=n;i++)pos[i]=i/blc;
	for(int i=1;i<=m;i++)q[i].id=i,read(q[i].l),read(q[i].r);
	sort(q+1,q+m+1);
	for(int i=1,l=0,r=0;i<=m;i++)
	{
		while(r<q[i].r)ans[a[++r]]++;
		while(l>q[i].l)ans[a[--l]]++;
		while(r>q[i].r)ans[a[r--]]--;
		while(l<q[i].l)ans[a[l++]]--;
		for(int j=1;j<4;j++)q[i].ans[j]=ans[j];
	}
	sort(q+1,q+m+1,greater<Ques>());
	for(int i=1;i<=m;i++)printf("%d %d %d\n",q[i].ans[1],q[i].ans[2],q[i].ans[3]);
	return 0;
}
