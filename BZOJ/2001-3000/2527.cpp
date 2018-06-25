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
typedef long long LL;
const int maxn=3e5+5;

int n,m,k,goal[maxn],l[maxn],r[maxn],val[maxn],id[maxn],tmp[maxn],ans[maxn],T;
vector<int> pos[maxn];
vector<int>::iterator it;
bool mark[maxn];
LL tr[maxn];

inline LL ask(int x){LL ans=0;for(;x;x-=x&-x)ans+=tr[x];return ans;}
inline void add(int x,int val){for(;x<=m;x+=x&-x)tr[x]+=val;}
inline void opera(int k,int f)
{
	if(l[k]<=r[k])add(l[k],f*val[k]),add(r[k]+1,-f*val[k]);
	else add(1,f*val[k]),add(r[k]+1,-f*val[k]),add(l[k],f*val[k]);
}
inline void solve(int l,int r,int L,int R)
{
	if(l>r)return;
	if(L==R)
	{
		for(int i=l;i<=r;i++)ans[id[i]]=L;
		return;
	}
	int mid=L+R>>1;
	while(T<=mid)opera(++T,1);
	while(T>mid)opera(T--,-1);
	int cnt=0,now;
	LL tot;
	for(int i=l;i<=r;i++)
	{
		tot=0,now=id[i];
		for(it=pos[now].begin();it!=pos[now].end();++it)
		{
			tot+=ask(*it);
			if(tot>goal[now])break;
		}
		if(tot>=goal[now])mark[now]=1,cnt++;
		else mark[now]=0;
	}
	int l1=l,l2=l+cnt;
	for(int i=l;i<=r;i++)
		if(mark[id[i]])tmp[l1++]=id[i];
		else tmp[l2++]=id[i];
	for(int i=l;i<=r;i++)id[i]=tmp[i];
	solve(l,l1-1,L,mid),solve(l1,l2-1,mid+1,R);
}

int main()
{
	read(n),read(m);
	for(int i=1,x;i<=m;i++)read(x),pos[x].push_back(i);
	for(int i=1;i<=n;i++)read(goal[i]);
	read(k),k++;
	for(int i=1;i<k;i++)read(l[i]),read(r[i]),read(val[i]);
	l[k]=1,r[k]=n,val[k]=1e9;
	for(int i=1;i<=n;i++)id[i]=i;
	solve(1,n,1,k);
	for(int i=1;i<=n;i++)ans[i]==k?puts("NIE"):printf("%d\n",ans[i]);
	return 0;
}
