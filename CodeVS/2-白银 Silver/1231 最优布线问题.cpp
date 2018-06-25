/*题目描述:学校需要将n台计算机连接起来,不同的2台计算机之间的连接费用可能是不同的.为了节省费用,我们考虑采用间接数据传输结束,
           就是一台计算机可以间接地通过其他计算机实现和另外一台计算机连接.
		   为了使得任意两台计算机之间都是连通的(不管是直接还是间接的),需要在若干台计算机之间用网线直接连接,现在想使得总的连接费用最省,
		   让你编程计算这个最小的费用
  输入描述:输入第一行为两个整数n,m(2<=n<=100000,2<=m<=100000),表示计算机总数,和可以互相建立连接的连接个数.
           接下来m行,每行三个整数a,b,c表示在机器a和机器b之间建立连接的话费是c
		   (题目保证一定存在可行的连通方案,数据中可能存在权值不一样的重边,但是保证没有自环)
  输出描述:输出只有一行一个整数,表示最省的总连接费用
  样例输入:3 3
           1 2 1
		   1 3 2
		   2 3 1
  样例输出:2*/

#include<cstdio>
#include<algorithm>
using namespace std;

struct side
{
	long long st,en,ln;
}lian[100001];
long long n,m,fa[100001];
long long ans;
int find(long long u)  {return fa[u]==u?u:fa[u]=find(fa[u]);}
bool cmp(side u,side v)  {return u.ln<v.ln;}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)  scanf("%d%d%d",&lian[i].st,&lian[i].en,&lian[i].ln);
	for(int i=1;i<=n;i++)  fa[i]=i;
	sort(lian+1,lian+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=find(lian[i].st),y=find(lian[i].en);
		if(x!=y)  {fa[y]=x;  ans+=lian[i].ln;}
	}
	printf("%lld",ans);
	return 0;
}
