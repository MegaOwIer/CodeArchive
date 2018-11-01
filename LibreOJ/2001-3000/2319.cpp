#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MX=300005;

int N,M,Q,RANGE_MAX;
vector<LL> G[MX];

struct segTree
{
	segTree *l,*r;
	int sum;
	segTree():l(NULL),r(NULL),sum(0){}
	void* operator new (size_t);
}*TR[MX];

segTree Pool[MX*20];
inline void* segTree::operator new (size_t)
{
	static segTree *ptr=Pool;
	return ptr++;
}

int read()
{
	int x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	return x;
}

inline int getNum(segTree *o,int L,int R)
{
	return (R-L+1)-(o?o->sum:0);
}

int Query(segTree *o,int L,int R,int pos)
{
	if(!o)return L+pos-1;
	int mid=L+R>>1,cur=getNum(o->l,L,mid);
	if(cur<pos)return Query(o->r,mid+1,R,pos-cur);
	else return Query(o->l,L,mid,pos);
}

void Modify(segTree *&o,int L,int R,int pos)
{
	if(!o)o=new segTree;
	++o->sum;
	if(L==R)return;
	int mid=L+R>>1;
	if(pos<=mid)Modify(o->l,L,mid,pos);
	else Modify(o->r,mid+1,R,pos);
}

LL DeleteR(int x,LL id)
{
	LL ans;
	int pos=Query(TR[N+1],1,RANGE_MAX,x);
	Modify(TR[N+1],1,RANGE_MAX,pos);
	if(pos<=N)ans=(LL)pos*M;
	else ans=G[N+1][pos-N-1];
	G[N+1].push_back(id==-1?ans:id);
	return ans;
}

LL DeleteL(int x,int y)
{
	LL ans;
	int pos=Query(TR[x],1,RANGE_MAX,y);
	Modify(TR[x],1,RANGE_MAX,pos);
	if(pos<M)ans=LL(x-1)*M+pos;
	else ans=G[x][pos-M];
	G[x].push_back(DeleteR(x,ans));
	return ans;
}

int main()
{
	N=read(),M=read(),Q=read();
	RANGE_MAX=max(N,M)+Q;
	while(Q--)
	{
		int x=read(),y=read();
		printf("%lld\n",y==M?DeleteR(x,-1):DeleteL(x,y));
	}
	return 0;
}
