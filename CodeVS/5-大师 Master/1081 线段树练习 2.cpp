/*��Ŀ����:����N����,�����ֲ���
           1:������[a,b]��������������X
		   2:ѯ�ʵ�i������ʲô
  ��������:��һ��һ��������n,������n��n������,�ٽ�����һ��������Q,��ʾ�����ĸ���.
           ������Q��ÿ�����ɸ�����.�����һ������1,���3��������a,b,X,��ʾ������[a,b]��ÿ��������X,�����2,�����1������i,��ʾѯ�ʵ�i��λ�õ����Ƕ���
  �������:����ÿ��ѯ�����һ��һ����
  ��������:3
           1
		   2
		   3
		   2
		   1 2 3 2
		   2 3
  �������:5
  ���ݷ�Χ����ʾ:1<=n<=100000,1<=q<=100000*/

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
