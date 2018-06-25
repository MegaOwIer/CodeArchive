/*��Ŀ����:ƽ������n����(n<=100),ÿ������������-10000~10000֮��.���е�һЩ��֮��������.
           ��������,���ʾ�ɴ�һ���㵽����һ����,���������ͨ·,ͨ·�ľ���Ϊ������ֱ�߾���.���ڵ��������ҳ���һ�㵽��һ��֮������·��.
  ��������:��һ��Ϊ����n.
           ��2�е���n+1��(��n��),ÿ����������x��y,������һ���������.
		   ��n+2��Ϊһ������m,��ʾͼ�����ߵĸ���.
		   �˺��m��,ÿ������һ������,����������i��j���,��ʾ��i����͵�j����֮��������.
		   ���һ��:��������s��t,�ֱ��ʾԴ���Ŀ���.
  �������:��һ��,һ��ʵ��(������λС��),��ʾ��s��t�����·������.
  ��������:5
           0 0
		   2 0
		   2 2
		   0 2
		   3 1
		   5
		   1 2
		   1 3
		   1 4
		   2 5
		   3 5
		   1 5
  �������:3.41  */

#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int x[101],y[101],n,m,s,t;
double dis[101][101];
double di(int,int);

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=100;i++)  for(int j=1;j<=100;j++)  dis[i][j]=0x7fffffff;
	for(int i=1;i<=n;i++)  scanf("%d%d",&x[i],&y[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
	    scanf("%d%d",&s,&t);
	    dis[s][t]=dis[t][s]=di(s,t);
	}
	for(int k=1;k<=n;k++)  for(int i=1;i<=n;i++)  for(int j=1;j<=n;j++)
	dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
	scanf("%d%d",&s,&t);
	printf("%.2lf",dis[s][t]);
	return 0;
}
double di(int u,int v)
{
	return sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]));
}
