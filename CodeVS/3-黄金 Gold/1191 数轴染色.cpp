/*题目描述:在一条数轴上有N个点,分别是1~N.一开始所有的点都被染成黑色.接着我们进行M次操作,第i次操作将[Li,Ri]这些点染成白色.
           请输出每个操作执行后剩余黑色点的个数。
  输入描述:输入一行为N和M.下面M行每行两个数Li,Ri
  输出描述:输出M行,为每次操作后剩余黑色点的个数
  样例输入:10 3
           3 3
		   5 7
		   2 8
  样例输出:9
           6
		   3
  数据范围及提示:对30%的数据,有1<=N<=2000,1<=M<=2000
                 对100%数据,有1<=Li<=Ri<=N<=200000,1<=M<=200000*/
                 
#include<iostream>
#include<cstdio>
using namespace std;

int n,m;
struct node
{
    int lt,rt;
    bool num;
}p[600000];
void build(int l,int r,int num)
{
    p[num].lt=l;
    p[num].rt=r;
    if(l==r)  return;
    int mid=(l+r)/2;
    build(l,mid,num*2);
    build(mid+1,r,num*2+1);
}
void insert(int l,int r,int step)
{
    if(p[step].num)  return;
    if(l==p[step].lt&&r==p[step].rt)  {p[step].num=1;  return;}
    int mid=(p[step].lt+p[step].rt)/2;
    if(r<=mid)  insert(l,r,step*2);
    else  if(l>mid)  insert(l,r,step*2+1);
          else  {insert(l,mid,step*2);  insert(mid+1,r,step*2+1);}
}
int con(int l,int r,int step)
{
    int ans=0;
    if(p[step].num)  {ans+=r-l+1;  return ans;}
    if(p[step].lt==p[step].rt)  return ans;
    int mid=(p[step].lt+p[step].rt)/2;
    if(mid>=r)  ans+=con(l,r,step*2);
    else  if(mid<l)  ans+=con(l,r,step*2+1);
          else  ans+=con(l,mid,step*2)+con(mid+1,r,step*2+1);
    return ans;
}

int main()
{
    cin>>n>>m;
    build(1,n,1);
    for(int i=1,l,r;i<=m;i++)
    {
        scanf("%d%d",&l,&r);
        insert(l,r,1);
        printf("%d\n",n-con(1,n,1));
    }
    return 0;
}
