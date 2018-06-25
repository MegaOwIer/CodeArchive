#include<cstring>
#include<string>
#include<map>
#include<cstdio>
using namespace std;

map<char,double> mass;
char s[85];
int m,cnt;
double ans,now;

int main()
{
	scanf("%d",&m);
	mass['C']=12.01;  mass['H']=1.008;  mass['O']=16.00;  mass['N']=14.01;
	while(m--)
	{
		memset(s,0,sizeof(0));  ans=now=cnt=0;
	    scanf("%s",s);
		for(int i=0;s[i];i++)
		{
			if(isalpha(s[i]))  {ans+=(cnt?cnt:1)*now;  cnt=0;  now=mass[s[i]];}
			else  cnt=cnt?cnt*10+s[i]-'0':s[i]-'0';
		}
		ans+=(cnt?cnt:1)*now;
		printf("%.3lf\n",ans);
	}
	return 0;
}
