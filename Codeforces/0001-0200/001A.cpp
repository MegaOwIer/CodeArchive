#include<cstdio>
using namespace std;
typedef long long LL;

LL a,b,c;

LL read()
{
	char ch=getchar();  LL ans=0LL;
	while(ch<'0'||ch>'9')  ch=getchar();
	while(ch>='0'&&ch<='9')  {ans=ans*10+ch-'0';  ch=getchar();}
	return ans;
}

int main()
{
	a=read();  b=read();  c=read();
	printf("%I64d",(a/c+(bool)(a%c))*(b/c+(bool)(b%c)));
	return 0;
}
