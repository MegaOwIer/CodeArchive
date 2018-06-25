#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
struct BigInt
{
	char ch[50];
	int siz;
	void mst() {memset(ch,0,sizeof(ch));siz=0;}
	void print()
	{
		for(int i=siz;i;i--)  putchar(ch[i]+'0');
	}
}dp[105];
BigInt operator + (BigInt a,int b)
{
	BigInt ans=a;
	ans.ch[1]+=b;
	for(int i=1;ans.ch[i]>9;i++)
	{
		ans.ch[i]-=10;
		ans.ch[i+1]++;
	}
	if(ans.ch[a.siz+1])  ans.siz++;
	return ans;
}
BigInt operator - (BigInt a,BigInt b)
{
	BigInt ans;  ans.mst();
	for(int i=a.siz;i;i--)  ans.ch[i]=a.ch[i]-b.ch[i]+'0';
	for(int i=1;i<=a.siz;i++)  if(ans.ch[i]<'0')
	{
		ans.ch[i+1]--;
		ans.ch[i]+=10;
	}
	for(int i=a.siz;i;i--)  ans.ch[i]-='0';
	for(ans.siz=a.siz;!ans.ch[ans.siz];ans.siz--);
	return ans;
}
BigInt operator * (BigInt a,int b)
{
	BigInt ans;  ans.mst();
	for(int i=1;i<=a.siz;i++)  ans.ch[i]=a.ch[i]*b;
	for(int i=1;i<=a.siz;i++)  if(ans.ch[i]>9)
	{
		ans.ch[i+1]+=ans.ch[i]/10;
		ans.ch[i]%=10;
	}
	if(ans.ch[a.siz+1])  ans.siz=a.siz+1;
	else  ans.siz=a.siz;
	return ans;
}

int main()
{
	scanf("%d",&n);
	dp[1].ch[1]=1;  dp[2].ch[1]=5;  dp[1].siz=dp[2].siz=1;
	for(int i=3;i<=n;i++)  
	dp[i]=dp[i-1]*3-dp[i-2]+2;
	dp[n].print();
	return 0;
}
