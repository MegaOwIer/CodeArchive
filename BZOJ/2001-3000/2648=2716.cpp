#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=1000005;
void read(int&);

int N,M,nowd,ans;
struct nulltag{};
struct KD_Tree
{
	KD_Tree *son[2];
	int pos[2],mn[2],mx[2];
	bool operator<(const KD_Tree& a)const{return pos[nowd]<a.pos[nowd];}
	void init()
	{
		read(pos[0]),mx[0]=mn[0]=pos[0];
		read(pos[1]),mx[1]=mn[1]=pos[1];
		son[0]=son[1]=NULL;
	}
	void update(const KD_Tree& a)
	{
		mn[0]=min(mn[0],a.mn[0]),mx[0]=max(mx[0],a.mx[0]);
		mn[1]=min(mn[1],a.mn[1]),mx[1]=max(mx[1],a.mx[1]);
	}
	void maintain()
	{
		if(son[0])update(*son[0]);
		if(son[1])update(*son[1]);
	}
}Node[MX],*root;

inline void read(int& x)
{
	static char c;
	static int f=0;
	x=0,c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	if(f)x=-x,f=0;
}
KD_Tree* build(int L,int R,int s)
{
	if(L>R)return 0;
	int mid=L+R>>1;
	nowd=s,nth_element(Node+L,Node+mid,Node+R+1);
	Node[mid].son[0]=build(L,mid-1,s^1);
	Node[mid].son[1]=build(mid+1,R,s^1);
	Node[mid].maintain();
	return &Node[mid];
}
inline void insert(KD_Tree *p)
{
	KD_Tree *o=root;
	int D=1;
	while(1)
	{
		o->update(*p);
		if(p->pos[D]<o->pos[D])
			if(o->son[0])o=o->son[0];
			else {o->son[0]=p;break;}
		else
			if(o->son[1])o=o->son[1];
			else {o->son[1]=p;break;}
		D^=1;
	}
}
inline int get(KD_Tree *o,int x,int y)
{
	if(!o)return 2147483647;
	return max(o->mn[0]-x,0)+max(x-o->mx[0],0)+
		   max(o->mn[1]-y,0)+max(y-o->mx[1],0);
}
void query(KD_Tree *o,int x,int y)
{
	if(!o)return;
	int dis=abs(o->pos[0]-x)+abs(o->pos[1]-y);
	int v0=get(o->son[0],x,y),v1=get(o->son[1],x,y);
	ans=min(ans,dis);
	if(v0<v1)
	{
		if(v0<ans)query(o->son[0],x,y);
		if(v1<ans)query(o->son[1],x,y);
	}
	else
	{
		if(v1<ans)query(o->son[1],x,y);
		if(v0<ans)query(o->son[0],x,y);
	}
}

int main()
{
	read(N),read(M);
	for(int i=1;i<=N;i++)Node[i].init();
	root=build(1,N,1);
	for(int i=1,op,x,y;i<=M;i++)
	{
		read(op);
		if(op==1)Node[++N].init(),insert(&Node[N]);
		else
		{
			read(x),read(y),ans=2147483647;
			query(root,x,y);
			printf("%d\n",ans);
		}
//		fprintf(stderr,"%d\n",i);
	}
	return 0;
}
