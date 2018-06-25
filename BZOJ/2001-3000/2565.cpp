#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;

int lth,l[maxn],r[maxn],id,p[maxn],ans;
char s[maxn];

int main()
{
	scanf("%s",s+1),lth=strlen(s+1);
	for(int i=lth;i;i--)s[i<<1|1]='#',s[i<<1]=s[i];
	s[0]='*',s[1]='#',lth=lth*2+1;
	for(int i=1;i<=lth;i++)
	{
		if(p[id]+id>i)p[i]=min(p[id]+id-i,p[id*2-i]);
		else p[i]=1;
		while(s[i+p[i]]==s[i-p[i]])p[i]++;
		if(i+p[i]>id+p[id])
		{
			for(int j=id+p[id]+1;j<=i+p[i]&&j<=lth;j++)l[j]=i;
			id=i;
		}
	}
	id=lth+1;
	for(int i=lth;i;i--)if(id-p[id]>i-p[i])
	{
		for(int j=id-p[id]-1;j>=i-p[i];j--)r[j]=i;
		id=i;
	}
	for(int i=3;i<lth;i+=2)ans=max(ans,r[i]-l[i]);
	printf("%d",ans);
	return 0;
}
