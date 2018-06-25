#include<bits/stdc++.h>
using namespace std;
const int maxn=40005;

int T,n,a[maxn],t[maxn],lth,mid;

inline void read(int& x){x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();}
inline int BS(int x)
{
	int l=1,r=lth;
	while(l<r)
	{
		mid=l+r>>1;
		if(t[mid]>x)r=mid;
		else l=mid+1;
	}
	return l;
}

int main()
{
	read(T);
	while(T--)
	{
		read(n),lth=0;
		for(int i=1;i<=n;i++)
		{
			read(a[i]);
			if(a[i]>=t[lth])t[++lth]=a[i];
			else t[BS(a[i])]=a[i];
		}
		printf("%d\n",lth);
	}
	return 0;
}
