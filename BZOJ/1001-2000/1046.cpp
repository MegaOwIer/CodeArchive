#include<bits/stdc++.h>
using namespace std;
const int MX=10005;

int N,a[MX],ls[MX],cnt,tmp[MX],ans,M,l[MX];

inline void read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
	read(N);
	for(int i=1;i<=N;i++)read(a[i]),ls[i]=a[i];
	sort(ls+1,ls+N+1),cnt=unique(ls+1,ls+N+1)-ls;
	for(int i=1;i<=N;i++)a[i]=lower_bound(ls+1,ls+cnt,a[i])-ls;
	tmp[0]=2147483647;
	for(int i=N;i;i--)
	{
		l[i]=lower_bound(tmp,tmp+ans+1,a[i],greater<int>())-tmp;
		ans=max(ans,l[i]);
		tmp[l[i]]=max(tmp[l[i]],a[i]);
	}
	read(M);
	for(int i=1,it,x,tmp;i<=M;i++)
	{
		read(x);
		if(x>ans)puts("Impossible");
		else
		{
			tmp=0,it=1;
			while(x--)
			{
				while(a[it]<=tmp||l[it]<=x)it++;
				tmp=a[it],printf("%d ",ls[a[it]]);
			}
			putchar('\n');
		}
	}
	return 0;
}
