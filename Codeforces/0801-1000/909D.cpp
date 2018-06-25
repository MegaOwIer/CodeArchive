#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;

int l[maxn],r[maxn],n,ans;
char s[maxn];
vector<int> q,q2;
bool vis[maxn];

inline bool chk(int i){return (l[i]&&s[l[i]]!=s[i])||(r[i]<=n&&s[r[i]]!=s[i]);}
inline void clr(int i){r[l[i]]=r[i],l[r[i]]=l[i];}

int main()
{
	scanf("%s",s+1),n=strlen(s+1);
	r[0]=1,l[n+1]=n,vis[0]=vis[n+1]=1;
	for(int i=1;i<=n;i++)l[i]=i-1,r[i]=i+1;
	for(int i=1;i<=n;i++)if(chk(i))
		q.push_back(i),vis[i]=1;
	while(!q.empty())
	{
		++ans;
		for(auto i:q)q2.push_back(l[i]),q2.push_back(r[i]),clr(i);
		q.clear();
		for(auto i:q2)if(i&&i<=n&&!vis[i]&&chk(i))
			vis[i]=1,q.push_back(i);
		q2.clear();
	}
	return printf("%d",ans),0;
}
