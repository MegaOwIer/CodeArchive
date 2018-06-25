#include<bits/stdc++.h>
using namespace std;
const int MX=500005;
typedef pair<int,int> pii;
#define mp make_pair
#define st first
#define nd second

int n,k,p,lst[MX],cnt,a[MX],nxt[MX],ans,ls[MX];
char c;
bool inq[MX];
priority_queue<pii,vector<pii> > q;

inline void read(int& x)
{
	x=0,c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}

int main()
{
	read(p),read(k);
	for(int i=1;i<=p;i++)read(a[i]),ls[i]=a[i];
	sort(ls+1,ls+p+1);
	n=unique(ls+1,ls+p+1)-ls-1;
	for(int i=1;i<=p;i++)a[i]=lower_bound(ls+1,ls+n+1,a[i])-ls;
	for(int i=1;i<=n;i++)lst[i]=p+1;
	for(int i=p;i;i--)nxt[i]=lst[a[i]],lst[a[i]]=i;
	for(int i=1;i<=p;i++)
	{
		if(inq[a[i]]){q.push(mp(nxt[i],a[i]));continue;}
		if(k)ans++,q.push(mp(nxt[i],a[i])),inq[a[i]]=1,k--;
		else
		{
			while(!inq[q.top().nd])q.pop();
			inq[q.top().nd]=0,q.pop();
			ans++,q.push(mp(nxt[i],a[i]));
			inq[a[i]]=1;
		}
	}
	printf("%d",ans);
	return 0;
}
