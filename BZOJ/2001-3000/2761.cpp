#include<cstdio>
#include<map>
using namespace std;

map<int,bool> s;
int t,n;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		s.clear();  bool fl=0;
		scanf("%d",&n);
		for(int i=1,a;i<=n;i++)
		{
			scanf("%d",&a);
			if(!s[a])  {s[a]=1;  printf(fl?" %d":"%d",a);  fl=1;}
		}
		puts("");
	}
	return 0;
}
