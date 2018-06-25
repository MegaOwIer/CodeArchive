/*题目描述:给你N个数,有两种操作
           1:给区间[a,b]的所有数都增加X
		   2:询问第i个数是什么
  输入描述:第一行一个正整数n,接下来n行n个整数,再接下来一个正整数Q,表示操作的个数.
           接下来Q行每行若干个整数.如果第一个数是1,后接3个正整数a,b,X,表示在区间[a,b]内每个数增加X,如果是2,后面跟1个整数i,表示询问第i个位置的数是多少
  输出描述:对于每个询问输出一行一个答案
  样例输入:3
           1
		   2
		   3
		   2
		   1 2 3 2
		   2 3
  样例输出:5
  数据范围及提示:1<=n<=100000,1<=q<=100000*/

#include<iostream>
#include<cstdio>
using namespace std;

int n,m;
struct node
{
	int l,r,num;
}po[300000];
void build(int l,int r,int step)
{
	po[step].l=l;
	po[step].r=r;
	if(l==r)  {scanf("%d",&po[step].num);  return;}
	int mid=(l+r)/2;
	build(l,mid,step*2);
	build(mid+1,r,step*2+1);
}
void insert(int l,int r,int step,int ord)
{
	if(po[step].l==l&&po[step].r==r)  {po[step].num+=ord;  return;}
	int mid=(po[step].l+po[step].r)/2;
	if(mid<l)  insert(l,r,step*2+1,ord);
	else if(mid>=r)  insert(l,r,step*2,ord);
	     else  {insert(l,mid,step*2,ord);  insert(mid+1,r,step*2+1,ord);}
}
int ask(int l,int step)
{
	int ans=0;
	ans+=po[step].num;
	if(po[step].l==po[step].r)  return ans;
	int mid=(po[step].l+po[step].r)/2;
	if(mid>=l)  ans+=ask(l,step*2);
	else  ans+=ask(l,step*2+1);
	return ans;
}
int main()
{
	cin>>n;
	build(1,n,1);
	cin>>m;
	for(int i=1,aa,bb,cc,dd;i<=m;i++)
	{
		scanf("%d",&dd);
		if(dd==1)  {scanf("%d%d%d",&aa,&bb,&cc);  insert(aa,bb,1,cc);}
		else  {scanf("%d",&bb);  printf("%d\n",ask(bb,1));}
	}
	return 0;
}
