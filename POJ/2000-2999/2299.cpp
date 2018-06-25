#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=500005;

struct node {int val,pos;}a[maxn];
int n,c[maxn],ord[maxn];
long long ans;

bool operator < (node a,node b) {return a.val<b.val;}
template<typename T>
inline void read(T& x){x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();}
inline int lowbit(int x){return x&(-x);}
inline void insert(int id){for(;id<=n;id+=lowbit(id))c[id]+=1;}
inline int sum(int id){int ans=0;for(;id;id-=lowbit(id))ans+=c[id];return ans;}

int main()
{
	while(1)
	{
		read(n);
		if(n==0)  return 0;
		memset(c+1,0,n<<2),ans=0LL;
		for(int i=1;i<=n;i++)  read(a[i].val),a[i].pos=i;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)  ord[a[i].pos]=i;
		for(int i=1;i<=n;i++)  insert(ord[i]),ans+=i-sum(ord[i]);
		printf("%lld\n",ans);
	}
}
