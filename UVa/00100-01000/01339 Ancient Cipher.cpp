#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cnt1[30],cnt2[30];
char c1[105],c2[105];

int main()
{
	while(scanf("%s%s",c1,c2)!=EOF)
	{
		memset(cnt1,0,sizeof(cnt1));  memset(cnt2,0,sizeof(cnt2));
		int l=strlen(c1);
		for(int i=0;i<l;i++)  {cnt1[c1[i]-'A']++;  cnt2[c2[i]-'A']++;}
		sort(cnt1,cnt1+26);  sort(cnt2,cnt2+26);
		bool flag=0;
		for(int i=0;i<26;i++)  if(cnt1[i]!=cnt2[i])  {flag=1;  break;}
		printf(flag?"NO\n":"YES\n");
	}
	return 0;
}
