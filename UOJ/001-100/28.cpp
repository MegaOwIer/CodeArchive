#include"friend.h" 
#include<algorithm>
using namespace std;
const int maxn=100005;

int f[maxn],g[maxn];

int findSample(int n,int c[],int h[],int p[])
{
	for(int i=0;i<n;i++)f[i]=c[i];
	for(int i=n-1;i;i--)
	{
		if(!p[i])f[h[i]]+=g[i],g[h[i]]+=max(f[i],g[i]);
		else if(p[i]==1)f[h[i]]=max(f[h[i]]+max(f[i],g[i]),g[h[i]]+f[i]),g[h[i]]+=g[i];
		else f[h[i]]=max(f[h[i]]+g[i],g[h[i]]+f[i]),g[h[i]]+=g[i];
	}
	return max(f[0],g[0]);
}
