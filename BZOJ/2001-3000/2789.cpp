#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1000005;
#define lb(x) x&(-x)

int n,tr[maxn],a[maxn];
LL ans;
queue<int> id[30];
char s[maxn],ch;

inline void getalpha(char& c){do c=getchar();while(c<'A'||c>'Z');}
inline void add(int x,int f){while(x<=n)tr[x]+=f,x+=lb(x);}
inline int sum(int x){int ans=0;while(x)ans+=tr[x],x-=lb(x);return ans;}

int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)getalpha(ch),id[ch-'A'].push(i);
	for(int i=1;i<=n;i++)a[i]=id[s[i]-'A'].front(),id[s[i]-'A'].pop();
	for(int i=n;i;i--)add(a[i],1),ans+=sum(a[i]-1);
	printf("%lld",ans);
	return 0;
}
