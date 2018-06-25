#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=50005;

struct Ques{int l,r,id;LL ans;}q[maxn];
int n,m,k,blc,pos[maxn],cnt[maxn],a[maxn];
LL now;

bool operator < (Ques a,Ques b)  {return pos[a.l]<pos[b.l]||(pos[a.l]==pos[b.l]&&a.r<b.r);}
bool operator > (Ques a,Ques b)  {return a.id<b.id;}
inline int read()
{
	int ans=0;  char ch=getchar();
	while(ch<'0'||ch>'9')  ch=getchar();
	while(ch>='0'&&ch<='9')  ans=ans*10+ch-'0',ch=getchar();
	return ans;
}
inline void upd(int id,bool fl)
{
	if(fl)  now+=cnt[a[id]]<<1|1,cnt[a[id]]++;
	else  now-=(cnt[a[id]]<<1)-1,cnt[a[id]]--;
}
void solve()
{
	upd(1,1);
	for(int l=1,r=1,i=1;i<=m;i++)
	{
		while(l<q[i].l)  upd(l++,0);
		while(l>q[i].l)  upd(--l,1);
		while(r>q[i].r)  upd(r--,0);
		while(r<q[i].r)  upd(++r,1);
		q[i].ans=now;
	}
}

int main()
{
	n=read(),m=read(),k=read();
	blc=(int)sqrt(n);
	for(int i=1;i<=n;i++)  pos[i]=i/blc;
	for(int i=1;i<=n;i++)  a[i]=read();
	for(int i=1;i<=m;i++)  q[i].l=read(),q[i].r=read(),q[i].id=i;
	sort(q+1,q+m+1);
	solve();
	sort(q+1,q+m+1,greater<Ques>());
	for(int i=1;i<=m;i++)  printf("%lld\n",q[i].ans);
	return 0;
}
