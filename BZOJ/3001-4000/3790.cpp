#include<bits/stdc++.h>
using namespace std;
namespace FastIO
{
	char c;
	int top,bf[22];
	template<typename T>inline void read(T& x)
	{
		c=getchar(),x=0;
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
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
typedef pair<int,int> pii;
const int maxn=50005;
#define mp make_pair
#define st first
#define nd second

int n,ans,f[maxn<<1],tr[maxn],tot;
char s[maxn<<1];
pii a[maxn<<1];

inline void add(int u,int v)
{
	u=u/2+1,v=v/2-1;
	if(u<=v)a[++tot]=mp(v,u);
}
inline void manacher()
{
	int m=n<<1|1,mx=0,id=0;
	memset(f,0,sizeof(int)*(m+1));
	for(int i=n;i;i--)s[i<<1|1]='#',s[i<<1]=s[i];
	s[1]=s[0]='#';
	for(int i=1;i<=m;i++)
	{
		if(mx>i)f[i]=min(f[id*2-i],mx-i);
		else f[i]=1;
		while(s[i-f[i]]==s[i+f[i]])f[i]++;
		if(i+f[i]>mx)id=i,mx=i+f[i];
		add(i-f[i],i+f[i]);
	}
	sort(a+1,a+tot+1);
}
inline int ask(int x)
{
	if(!x)return 0;
	int ans=2147483647;
	for(;x<=n;x+=x&-x)ans=min(ans,tr[x]);
	return ans;
}
inline void insert(int u,int x){for(;u;u-=u&-u)tr[u]=min(tr[u],x);}

int main()
{
	while(~scanf("%s",s+1))
	{
		n=strlen(s+1);
		memset(tr+1,0x3f,sizeof(int)*n);
		tot=0,ans=2147483647;
		manacher();
		for(int i=1,x;i<=tot;i++)
		{
			x=ask(a[i].nd-1)+1;
			insert(a[i].st,x);
			if(a[i].st==n)ans=min(ans,x);
		}
		write(ans-1);
	}
	return 0;
}
