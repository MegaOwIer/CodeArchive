#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;

int n,a[maxn],ans;
char c;
bool ism[maxn];

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}
inline void check()
{
	for(int i=2;i<n;i++)
	{
		if(ism[i-1]+ism[i]>a[i])return;
		else if(ism[i-1]+ism[i]==a[i])ism[i+1]=0;
		else if(ism[i-1]+ism[i]==a[i]-1)ism[i+1]=1;
		else return;
	}
	if(a[n]==ism[n]+ism[n-1])ans++;
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	if(a[1]==0)ism[1]=0,ism[2]=0,check();
	if(a[1]==1)ism[1]=0,ism[2]=1,check();
	if(a[1]==1)ism[1]=1,ism[2]=0,check();
	if(a[1]==2)ism[1]=1,ism[2]=1,check();
	printf("%d",ans);
	return 0;
}
