#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;

int n,kind,lth;
char s[100005];

void zhuan(LL u)
{
	if(!u)  return;
	zhuan((u-1)/26);
	putchar('A'+(u-1)%26);
}
void judge()
{
	int now=2;
	if(s[0]!='R')  {kind=1;  return;}
	if(s[1]<'0'||s[1]>'9')  {kind=1;  return;}
	for(;s[now]>='0'&&s[now]<='9'&&now<lth;now++);
	if(now==lth)  {kind=1;  return;}
	kind=2;
}
void solve(int u)
{
	if(u==2)
	{
		int l=0;
		LL ans=0LL;
		for(;s[l]!='C';l++);  l++;
		for(;l<lth;l++)  ans=ans*10+s[l]-'0';
		zhuan(ans);
		for(int i=1;s[i]!='C';i++)  putchar(s[i]);
		puts("");
	}
	else
	{
		int l=0;  putchar('R');
		while(s[l]<'0'||s[l]>'9')  l++;
		for(;l<lth;l++)  putchar(s[l]);  putchar('C');
		LL ans=0LL;
		for(int i=0;s[i]<'0'||s[i]>'9';i++)  ans=ans*26+s[i]-'A'+1;
		printf("%I64d\n",ans);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);  lth=strlen(s);
		judge();
		solve(kind);
	}
	return 0;
}
