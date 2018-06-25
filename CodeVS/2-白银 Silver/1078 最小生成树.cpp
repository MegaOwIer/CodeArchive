/*题目描述:农民约翰被选为他们镇的镇长!他其中一个竞选承诺就是在镇上建立起互联网,并连接到所有的农场
           当然,他需要你的帮助.约翰已经给他的农场安排了一条高速的网络线路,他想把这条线路共享给其他农场.为了使花费最少,他想铺设最短的光纤去连接所有的农场
		   你将得到一份各农场之间连接费用的列表,你必须找出能连接所有农场并所用光纤最短的方案.每两个农场间的距离不会超过100000
  输入描述:第一行,农场的个数,N(3<=N<=100)
           第二行..结尾:接下来的行包含了一个N*N的矩阵,表示每个农场之间的距离.当然,对角线将会是0,因为线路从第i个农场到它本身的距离在本题中没有意义
  输出描述:只有一个输出,是连接到每个农场的光纤的最小长度和
  样例输入:4
           0 4 9 21
		   4 0 8 17
		   9 8 0 16
		   21 17 16 0
  样例输出:28*/

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
