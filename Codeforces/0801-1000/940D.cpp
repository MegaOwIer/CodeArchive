#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int N,a[MX],l=-1e9,r=1e9;
char s[MX];

inline bool check1(int u){return s[u-1]&&s[u-2]&&s[u-3]&&s[u-4]&&!s[u];}
inline bool check0(int u){return !(s[u-1]||s[u-2]||s[u-3]||s[u-4])&&s[u];}

int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)scanf("%d",a+i);
	scanf("%s",s+1);
	for(int i=1;i<=N;i++)s[i]-=48;
	for(int i=5;i<=N;i++)
		if(check1(i))r=min(r,-1+*min_element(a+i-4,a+i+1));
		else if(check0(i))l=max(l,1+*max_element(a+i-4,a+i+1));
	printf("%d %d\n",l,r);
	return 0;
}
