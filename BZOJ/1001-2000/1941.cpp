#include<bits/stdc++.h>
using namespace std;
const int MX=500005,D=2;
void read(int&);

struct nulltag{};
struct Node
{
	Node *son[D];
	int pos[D],id,mn[D],mx[D];
	Node(){}
	Node(nulltag)
	{
		son[0]=son[1]=this;
		mn[0]=mn[1]=100000000;
		mx[0]=mx[1]=0;
	}
	void init(int i){read(pos[0]),read(pos[1]),id=i;}
	void maintain()
	{
		mn[0]=min(pos[0],min(son[0]->mn[0],son[1]->mn[0]));
		mx[0]=max(pos[0],max(son[0]->mx[0],son[1]->mx[0]));
		mn[1]=min(pos[1],min(son[0]->mn[1],son[1]->mn[1]));
		mx[1]=max(pos[1],max(son[0]->mx[1],son[1]->mx[1]));
	}
}*root,*null=new Node(nulltag()),p[MX];
int N,nowd,ans,ans_mx,ans_mn;

inline void read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline bool cmp(const Node& a,const Node& b){return a.pos[nowd]<b.pos[nowd];}
Node* build(int l,int r,int s)
{
	if(l>r)return null;
	int mid=l+r>>1;
	nowd=s%D,nth_element(p+l,p+mid,p+r+1,cmp);
	p[mid].son[0]=build(l,mid-1,s+1);
	p[mid].son[1]=build(mid+1,r,s+1);
	p[mid].maintain();
	return &p[mid];
}
inline int get_max(Node *o,int id)
{
	return max(abs(p[id].pos[0]-o->mn[0]),abs(p[id].pos[0]-o->mx[0]))+
		   max(abs(p[id].pos[1]-o->mn[1]),abs(p[id].pos[1]-o->mx[1]));
}
inline void query_max(Node *o,int id)
{
	if(o==null)return;
	int dis=abs(o->pos[0]-p[id].pos[0])+abs(o->pos[1]-p[id].pos[1]);
	int v0=get_max(o->son[0],id),v1=get_max(o->son[1],id);
	if(o->id!=p[id].id)ans_mx=max(ans_mx,dis);
	if(v0<v1)swap(o->son[0],o->son[1]),swap(v0,v1);
	if(v0>ans_mx)query_max(o->son[0],id);
	if(v1>ans_mx)query_max(o->son[1],id);
}
inline int get_min(Node *o,int id)
{
	return max(p[id].pos[0]-o->mx[0],0)+max(o->mn[0]-p[id].pos[0],0)+
		   max(p[id].pos[1]-o->mx[1],0)+max(o->mn[1]-p[id].pos[1],0);
}
inline void query_min(Node *o,int id)
{
	if(o==null)return;
	int dis=abs(o->pos[0]-p[id].pos[0])+abs(o->pos[1]-p[id].pos[1]);
	int v0=get_min(o->son[0],id),v1=get_min(o->son[1],id);
	if(o->id!=p[id].id)ans_mn=min(ans_mn,dis);
	if(v0>v1)swap(o->son[0],o->son[1]),swap(v0,v1);
	if(v0<ans_mn)query_min(o->son[0],id);
	if(v1<ans_mn)query_min(o->son[1],id);
}

int main()
{
	read(N);
	for(int i=1;i<=N;i++)p[i].init(i);
	root=build(1,N,1);
	ans=2147483647;
	for(int i=1;i<=N;i++)
	{
		ans_mx=2147483648,ans_mn=2147483647;
		query_min(root,i),query_max(root,i);
		ans=min(ans,ans_mx-ans_mn);
	}
	printf("%d",ans);
	return 0;
}
