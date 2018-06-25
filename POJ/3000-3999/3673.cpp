#include<cstdio>
#include<algorithm>
using namespace std;

int a[2];
char ch;
bool fl;

int main()
{
	while((ch=getchar())!=EOF)
	{
		if(ch==' ')  {fl=1;  continue;}
		if(ch=='\n')  break;
		if(ch>='0'&&ch<='9')  a[1^fl]+=ch-'0';
	}
	printf("%d",a[0]*a[1]);
	return 0;
}
