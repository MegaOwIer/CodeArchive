#include<bits/stdc++.h>
using namespace std;
const int maxn=30010;

namespace FastIO
{
	char c;
	int top,bf[22];
	template<typename T>inline void read(T& x)
	{
		c=getchar(),x=0;
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-48,c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		top=0;
		do bf[++top]=x%10,x/=10;while(x);
		while(top)putchar(48+bf[top--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;

namespace AC_Automation
{
	struct Trie
	{
		Trie *son[2],*fail;
		bool flag,vis,bo;
		Trie():flag(0),vis(0),bo(0){son[0]=son[1]=NULL,fail=this;}
	}*root=new Trie();
	queue<Trie*> q;

	inline void insert(char* s)
	{
		int lth=strlen(s+1);
		Trie* tmp=root;
		for(int i=1;i<=lth;i++)
		{
			if(!tmp->son[s[i]-48])tmp->son[s[i]-48]=new Trie;
			tmp=tmp->son[s[i]-48];
		}
		tmp->flag=1;
	}
	void build_fail()
	{
		Trie* tmp;
		q.push(root);
		register int i;
		while(!q.empty())
		{
			tmp=q.front(),q.pop();
			for(i=0;i<2;i++)
			{
				if(tmp->son[i])
				{
					q.push(tmp->son[i]);
					tmp->son[i]->fail=(tmp==root)?root:tmp->fail->son[i];
					tmp->son[i]->flag|=tmp->son[i]->fail->flag;
				}
				else tmp->son[i]=(tmp==root)?root:tmp->fail->son[i];
			}
		}
	}
	inline bool dfs(Trie* o)
	{
		o->vis=1;
		for(int i=0;i<2;i++)
		{
			if(o->son[i]->vis)return 1;
			if(o->son[i]->flag||o->son[i]->bo)continue;
			o->son[i]->bo=1;
			if(dfs(o->son[i]))return 1;
		}
		o->vis=0;
		return 0;
	}
}
using AC_Automation::root;

int n;
char s[maxn];

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		AC_Automation::insert(s);
	}
	AC_Automation::build_fail();
	puts(AC_Automation::dfs(root)?"TAK":"NIE");
	return 0;
}