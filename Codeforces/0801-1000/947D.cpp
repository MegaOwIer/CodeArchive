#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int S,T,cnt1[MX],cnt2[MX],sum1[MX],sum2[MX],Q;
char s[MX],t[MX];

int main()
{
	scanf("%s",s+1),S=strlen(s+1);
	for(int i=1;i<=S;i++)
	{
		if(s[i]=='C')s[i]='B';
		cnt1[i]=cnt1[i-1]+(s[i]=='B');
		if(s[i]=='A')sum1[i]=sum1[i-1]+1;
		else sum1[i]=0;
	}
	scanf("%s",t+1),T=strlen(t+1);
	for(int i=1;i<=T;i++)
	{
		if(t[i]=='C')t[i]='B';
		cnt2[i]=cnt2[i-1]+(t[i]=='B');
		if(t[i]=='A')sum2[i]=sum2[i-1]+1;
		else sum2[i]=0;
	}
	scanf("%d",&Q);
	for(int i=1,a,b,c,d,l1,l2,n1,n2;i<=Q;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		l1=min(b-a+1,sum1[b]),l2=min(d-c+1,sum2[d]);
		n1=cnt1[b]-cnt1[a-1],n2=cnt2[d]-cnt2[c-1];
		if(l1<l2)putchar('0');
		else if(n1==n2)putchar((l1-l2)%3==0?'1':'0');
		else if(n1>n2)putchar('0');
		else if((n2-n1)&1)putchar('0');
		else putchar(!n1&&l1==l2?'0':'1');
	}
	return 0;
}
