#include<bits/stdc++.h>
using namespace std;
const int MX=200005;

int N,a[MX],B,nxt[MX],stp[MX],Q,ans;

inline void read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
	read(N),B=1+sqrt(N);
	for(int i=0;i<N;i++)read(a[i]);
	for(int i=0,j=B-1;i<N;i=j+1,j=min(j+B,N-1))
		for(int k=j;k>=i;k--)
			if(k+a[k]>j)stp[k]=1,nxt[k]=k+a[k];
			else stp[k]=1+stp[k+a[k]],nxt[k]=nxt[k+a[k]];
	read(Q);
	for(int i=1,op,x,y;i<=Q;i++)
	{
		read(op),read(x);
		if(op==1)
		{
			ans=0;
			for(y=x;y<N;y=nxt[y])ans+=stp[y];
			printf("%d\n",ans);
		}
		else
		{
			read(y),a[x]=y;
			for(y=x;;y--)
			{
				if(y+a[y]>=y/B*B+B)stp[y]=1,nxt[y]=y+a[y];
				else stp[y]=1+stp[y+a[y]],nxt[y]=nxt[y+a[y]];
				if(y%B==0)break;
			}
		}
	}
	return 0;
}
