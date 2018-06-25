#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int n,k,id[30],tot,ans[MX];
char s[MX],al[30];
bool used[30];

int main()
{
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;i<=n;i++)used[s[i]-'a']=1;
	for(int i=0;i<26;i++)if(used[i])
		al[tot]='a'+i,id[i]=tot,tot++;
	for(int i=1;i<=n&&i<=k;i++)ans[i]=id[s[i]-'a'];
	if(k<=n)ans[k]++;
	for(int i=k;ans[i]>=tot;i--)ans[i]-=tot,ans[i-1]++;
	for(int i=1;i<=k;i++)putchar(al[ans[i]]);
	return 0;
}
