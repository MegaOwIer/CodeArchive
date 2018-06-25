#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=10005;

struct Ques {int l,r,id,t,ans;}q[maxn];
struct Chan {int id,col;}ch[1005];
int N,M,cl[maxn],cntq,cntc,blc,pos[maxn],cnt[1000005],tot;
char op;

bool operator < (Ques a,Ques b) {return pos[a.l]<pos[b.l]||(pos[a.l]==pos[b.l]&&pos[a.r]<pos[b.r])||(pos[a.l]==pos[b.l]&&pos[a.r]==pos[b.r]&&a.t<b.t);}
bool operator > (Ques a,Ques b) {return a.id<b.id;}
inline void read(int& x)
{
	x=0;  char c=getchar();
	while(c<'0'||c>'9')  c=getchar();
	while(c>='0'&&c<='9')  x=x*10+c-'0',c=getchar();
}
inline void getalpha(char& c) {do c=getchar();  while(c>'Z'||c<'A');}
inline void upd(int id,bool plus)
{
	if(plus)
	{
		if(!cnt[cl[id]])  tot++;
		cnt[cl[id]]++;
	}
	else
	{
		cnt[cl[id]]--;
		if(!cnt[cl[id]])  tot--;
	}
}
inline void cng(int t,int l,int r)
{
	if(ch[t].id>=l&&ch[t].id<=r)  upd(ch[t].id,0);
	swap(cl[ch[t].id],ch[t].col);
	if(ch[t].id>=l&&ch[t].id<=r)  upd(ch[t].id,1);
}
void solve()
{
	upd(1,1);
	for(int i=1,l=1,r=1,x=0;i<=cntq;i++)
	{
		while(r<q[i].r)  upd(++r,1);
		while(r>q[i].r)  upd(r--,0);
		while(l<q[i].l)  upd(l++,0);
		while(l>q[i].l)  upd(--l,1);
		while(x<q[i].t)  cng(++x,l,r);
		while(x>q[i].t)  cng(x--,l,r);
		q[i].ans=tot;
	}
}

int main()
{
	read(N),read(M);
	for(int i=1;i<=N;i++)  read(cl[i]);
	for(int i=1,l,r;i<=M;i++)
	{
		getalpha(op),read(l),read(r);
		if(op=='Q')  q[++cntq]=(Ques){l,r,cntq,cntc,0};
		else  ch[++cntc]=(Chan){l,r};
	}
	blc=(int)pow(N,2/3.0)+1;
	for(int i=1;i<=N;i++)  pos[i]=i/blc;
	sort(q+1,q+cntq+1);
	solve();
	sort(q+1,q+cntq+1,greater<Ques>());
	for(int i=1;i<=cntq;i++)  printf("%d\n",q[i].ans);
	return 0;
}
