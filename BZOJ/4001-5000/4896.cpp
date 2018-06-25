#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct node
{
	node *son[10];
	int num;
	vector<int>v;
	node(){v.clear(),num=0;for(int i=0;i<10;i++)son[i]=0;}
}*root=new node;
int n,opt,ans;
LL a,b,c;
char s[65];

inline void insert(int cnt)
{
	node* tmp=root;
	for(int i=1;s[i];i++)
	{
		if(!tmp->son[s[i]-'a'])tmp->son[s[i]-'a']=new node;
		tmp=tmp->son[s[i]-'a'],tmp->num++;
		if(tmp->v.size()<tmp->num)tmp->v.push_back(cnt);
	}
}
inline void clear()
{
	node* tmp=root;
	for(int i=1;s[i];i++)
		tmp=tmp->son[s[i]-'a'],tmp->num--;
}
inline void ask(LL u)
{
	node* tmp=root;
	for(int i=1;s[i];i++)
	{
		if(!tmp->son[s[i]-'a']){ans=-1;return;}
		tmp=tmp->son[s[i]-'a'];
	}
	if(tmp->v.size()<=u){ans=-1;return;}
	ans=tmp->v[u];
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%s",&opt,s+1);
		if(opt==1)insert(i);
		else if(opt==2)clear();
		else scanf("%lld%lld%lld",&a,&b,&c),ask((a*abs(ans)+b)%c),printf("%d\n",ans);
	}
	return 0;
}
