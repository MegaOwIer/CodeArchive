#include<bits/stdc++.h>
#include"rts.h"
using namespace std;
const int MX=300005;

int id[MX];
bool vis[MX];
struct Node
{
    Node *son[2],*fa,*L,*R;
    int id;
    Node():fa(NULL),L(this),R(this){son[0]=son[1]=NULL;}
    bool isroot(){return !fa||fa->son[0]!=this&&fa->son[1]!=this;}
    int dir(){return this==fa->son[1];}
    Node* pre(){return son[0]?son[0]->R:NULL;}
    Node* nxt(){return son[1]?son[1]->L:NULL;}
    void maintain()
    {
        L=son[0]?son[0]->L:this;
        R=son[1]?son[1]->R:this;
    }
}p[MX],*now,*nxt;

inline void rotate(Node* o)
{
    static Node *p;
    static int d;
    p=o->fa,d=o->dir();
    if(!p->isroot())p->fa->son[p->dir()]=o;
    o->fa=p->fa;
    p->son[d]=o->son[d^1];
    if(o->son[d^1])o->son[d^1]->fa=p;
    o->son[d^1]=p,p->fa=o;
    p->maintain();
}
inline void splay(Node* o)
{
    static Node *p;
    while(!o->isroot())
    {
        p=o->fa;
        if(!p->isroot())
        	rotate(o->dir()==p->dir()?p:o);
        rotate(o);
    }
    o->maintain();
}

void play(int n,int,int dataType)
{
    srand(time(NULL));
    for(int i=1;i<=n;i++)id[i]=i;
    random_shuffle(id+2,id+n+1);
    vis[1]=1;
    if(dataType==3)
    {
    	int L=1,R=1,l=1,targ;
		while(1)
		{
		    while(vis[id[l]])l++;
		    if(l>n)break;
		    targ=explore(L,id[l]);
		    if(vis[targ])swap(L,R),targ=explore(L,id[l]);
		    while(targ!=id[l])
		        vis[targ]=1,L=targ,targ=explore(L,id[l]);
		    vis[L=targ]=1;
		}
		return;
    }
    for(int i=1;i<=n;i++)p[i].id=i;
    for(int i=2;i<=n;i++)if(!vis[id[i]])
    {
        now=p+1;
        while(now!=p+id[i])
        {
            splay(now);
            while(1)
            {
                nxt=p+explore(now->id,id[i]);
                if(nxt==now->pre())now=now->son[0];
                else if(nxt==now->nxt())now=now->son[1];
                else
                {
                    if(!vis[nxt->id])vis[nxt->id]=1,nxt->fa=now;
                    now=nxt;
                    break;
                }
            }
        }
        for(nxt=0;now;nxt=now,now=now->fa)
			splay(now),now->son[1]=nxt,now->maintain();
    }
}

