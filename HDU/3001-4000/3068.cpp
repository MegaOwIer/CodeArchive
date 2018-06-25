#include<bits/stdc++.h>
using namespace std;
const int maxn=110005;

int p[maxn<<1],lth,id,mxl;
char s[maxn<<1];

int main()
{
	s[0]='*';
	while(~scanf("%s",s+1))
	{
		lth=strlen(s+1),id=0,mxl=0;
		for(int i=lth;i;i--)s[i<<1|1]='#',s[i<<1]=s[i];
		lth=lth*2+1,s[1]='#',s[lth+1]=0;
		for(int i=2;i<lth;i++)
		{
			if(p[id]+id>i)p[i]=min(p[id]+id-i,p[id*2-i]);
			else p[i]=1;
			while(s[i-p[i]]==s[i+p[i]])p[i]++;
			if(id+p[id]<i+p[i])id=i;
			if(mxl<p[i])mxl=p[i];
		}
		printf("%d\n",mxl-1);
	}
	return 0;
}
