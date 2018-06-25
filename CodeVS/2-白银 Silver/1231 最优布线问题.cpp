/*��Ŀ����:ѧУ��Ҫ��n̨�������������,��ͬ��2̨�����֮������ӷ��ÿ����ǲ�ͬ��.Ϊ�˽�ʡ����,���ǿ��ǲ��ü�����ݴ������,
           ����һ̨��������Լ�ӵ�ͨ�����������ʵ�ֺ�����һ̨���������.
		   Ϊ��ʹ��������̨�����֮�䶼����ͨ��(������ֱ�ӻ��Ǽ�ӵ�),��Ҫ������̨�����֮��������ֱ������,������ʹ���ܵ����ӷ�����ʡ,
		   �����̼��������С�ķ���
  ��������:�����һ��Ϊ��������n,m(2<=n<=100000,2<=m<=100000),��ʾ���������,�Ϳ��Ի��ཨ�����ӵ����Ӹ���.
           ������m��,ÿ����������a,b,c��ʾ�ڻ���a�ͻ���b֮�佨�����ӵĻ�����c
		   (��Ŀ��֤һ�����ڿ��е���ͨ����,�����п��ܴ���Ȩֵ��һ�����ر�,���Ǳ�֤û���Ի�)
  �������:���ֻ��һ��һ������,��ʾ��ʡ�������ӷ���
  ��������:3 3
           1 2 1
		   1 3 2
		   2 3 1
  �������:2*/

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
