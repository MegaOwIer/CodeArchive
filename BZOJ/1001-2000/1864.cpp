#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=500000+5;

struct node {int fa,l,r;}p[maxn];
int cnt=1,mx[maxn][3],mn[maxn][3];

void build(int now,int pre)
{
	p[now]=(node){pre,0,0};
	char ch=getchar();
	if(ch=='1')  {p[now].l=++cnt;  build(cnt,now);}
	else  if(ch=='2')
	{
		p[now].l=++cnt;  build(cnt,now);
		p[now].r=++cnt;  build(cnt,now);
	}
}
void dfs(int u)
{
	if(!u)  return;
	dfs(p[u].l),dfs(p[u].r);
	mx[u][0]=max(mx[p[u].l][1]+mx[p[u].r][2],mx[p[u].l][2]+mx[p[u].r][1])+1;
	mx[u][1]=max(mx[p[u].l][0]+mx[p[u].r][2],mx[p[u].l][2]+mx[p[u].r][0]);
	mx[u][2]=max(mx[p[u].l][1]+mx[p[u].r][0],mx[p[u].l][0]+mx[p[u].r][1]);
	mn[u][0]=min(mn[p[u].l][1]+mn[p[u].r][2],mn[p[u].l][2]+mn[p[u].r][1])+1;
	mn[u][1]=min(mn[p[u].l][0]+mn[p[u].r][2],mn[p[u].l][2]+mn[p[u].r][0]);
	mn[u][2]=min(mn[p[u].l][1]+mn[p[u].r][0],mn[p[u].l][0]+mn[p[u].r][1]);
}

int main()
{
	build(1,0);
	dfs(1);
	printf("%d %d",max(mx[1][0],max(mx[1][1],mx[1][2])),min(mn[1][0],min(mn[1][1],mn[1][2])));
	return 0;
}
