#include<bits/stdc++.h>
using namespace std;
#define siz 151][151][151]

int p,q,r,f[siz,c[151],ans,h[151],l[151],R[151];
bool a[siz,b[siz;
char C;

inline void getalpha(char& c){do c=getchar();while(!isalpha(c));}
inline void cal()
{
	int tmp=0;
	c[0]=c[r+1]=-1,h[1]=0;
	for(int i=1,j=1;i<=r;i++)
	{
		while(c[i]<=c[h[j]])j--;
		l[i]=h[j]+1,h[++j]=i;
	}
	h[1]=r+1;
	for(int i=r,j=1;i;i--)
	{
		while(c[i]<=c[h[j]])j--;
		R[i]=h[j]-1,h[++j]=i;
	}
	for(int i=1;i<=r;i++)ans=max(ans,c[i]*(R[i]-l[i]+1));
}
inline void solve()
{
	for(int k=1;k<=r;k++)for(int i=1;i<=p;i++)for(int j=1;j<=q;j++)
		if(a[i][j][k])f[i][j][k]=min(min(f[i][j-1][k],f[i-1][j][k]),f[i-1][j-1][k])+1;
		else f[i][j][k]=0;
	for(int i=1;i<=p;i++)for(int j=1;j<=q;j++)memcpy(c,f[i][j],sizeof(f[i][j])),cal();
}

int main()
{
	scanf("%d%d%d",&p,&q,&r);
	for(int j=1;j<=q;j++)for(int i=1;i<=p;i++)for(int k=1;k<=r;k++)
		getalpha(C),a[i][j][k]=b[i][j][k]=(C=='N');
	solve();
	for(int i=1;i<=p;i++)for(int j=1;j<=q;j++)for(int k=1;k<=r;k++)
		a[i][r-k+1][j]=b[i][j][k];
	swap(q,r),solve(),swap(q,r);
	for(int i=1;i<=p;i++)for(int j=1;j<=q;j++)for(int k=1;k<=r;k++)
		a[k][j][p-i+1]=b[i][j][k];
	swap(p,r),solve();
	printf("%d",ans<<2);
	return 0;
}
