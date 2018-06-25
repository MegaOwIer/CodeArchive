/*��Ŀ����:ũ��Լ����ѡΪ���������!������һ����ѡ��ŵ���������Ͻ���������,�����ӵ����е�ũ��
           ��Ȼ,����Ҫ��İ���.Լ���Ѿ�������ũ��������һ�����ٵ�������·,�����������·���������ũ��.Ϊ��ʹ��������,����������̵Ĺ���ȥ�������е�ũ��
		   �㽫�õ�һ�ݸ�ũ��֮�����ӷ��õ��б�,������ҳ�����������ũ�������ù�����̵ķ���.ÿ����ũ����ľ��벻�ᳬ��100000
  ��������:��һ��,ũ���ĸ���,N(3<=N<=100)
           �ڶ���..��β:���������а�����һ��N*N�ľ���,��ʾÿ��ũ��֮��ľ���.��Ȼ,�Խ��߽�����0,��Ϊ��·�ӵ�i��ũ����������ľ����ڱ�����û������
  �������:ֻ��һ�����,�����ӵ�ÿ��ũ���Ĺ��˵���С���Ⱥ�
  ��������:4
           0 4 9 21
		   4 0 8 17
		   9 8 0 16
		   21 17 16 0
  �������:28*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct edge{int st,en,lg;}po;
vector<edge> ed;
long long n,g,ans,fa[101];
bool cmp(edge a,edge b)  {return a.lg<b.lg;}
inline int find(long long u)  {return u==fa[u]?u:fa[u]=find(fa[u]);}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	    for(int j=1;j<=n;j++)
	    {
	        cin>>g;
	        if(i>=j||!g)  continue;
	        po.st=i;  po.en=j;  po.lg=g;
	        ed.push_back(po);
        }
    }
	sort(ed.begin(),ed.end(),cmp);
	for(int i=0;i<ed.size();i++)
	{
		int x=find(ed[i].st),y=find(ed[i].en);
		if(x==y)  continue;
		fa[y]=x;
		ans+=ed[i].lg;
	}
	cout<<ans;
	return 0;
}
