#include<bits/stdc++.h>
using namespace std;

struct cpl{int x,y;}w[3];
struct dat{cpl a;int id;}e[200005];
int n,l,ans;
char c;

inline void getalpha(char& c){do c=getchar();while(c<'A'||c>'Z');}
inline int id(char c)
{
	if(c=='J')return 0;
	if(c=='O')return 1;
	if(c=='I')return 2;
}
inline cpl operator + (cpl a,cpl b){return (cpl){a.x+b.x,a.y+b.y};}
inline bool operator == (cpl a,cpl b){return a.x==b.x&&a.y==b.y;}
inline bool operator < (cpl a,cpl b){return a.x<b.x||(a.y<b.y&&a.x==b.x);}
inline bool operator < (dat a,dat b){return a.a<b.a||(a.a==b.a&&a.id<b.id);}
inline bool operator == (dat a,dat b){return a.a==b.a;}

int main()
{
	scanf("%d",&n);
	w[0].x=2,w[1].x=w[2].x=-1,w[1].y=1,w[2].y=-1;
	for(int i=1;i<=n;i++)getalpha(c),e[i].a=e[i-1].a+w[id(c)],e[i].id=i;
	sort(e+1,e+n+1);
	for(int i=1;i<=n;i++)
	{
		if(e[i].a==(cpl){0,0}){ans=max(ans,e[i].id),l=i;continue;}
		if(e[i]==e[l])continue;
		ans=max(ans,abs(e[i-1].id-e[l].id));
		l=i;
	}
	ans=max(ans,abs(e[n].id-e[l].id));
	printf("%d",ans);
	return 0;
}
