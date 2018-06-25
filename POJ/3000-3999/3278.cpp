#include<cstdio>
#include<queue>
using namespace std;

int st,goal,cnt[200005];
queue<int> q;

int main()
{
	scanf("%d%d",&st,&goal);  q.push(st);  cnt[st]=1;
	while(!cnt[goal])
	{
		int now=q.front();  q.pop();
		if(now>=1&&!cnt[now-1])  {q.push(now-1);  cnt[now-1]=cnt[now]+1;}
		if(now<goal&&!cnt[now+1])  {q.push(now+1);  cnt[now+1]=cnt[now]+1;}
		if(now*2<goal+2&&!cnt[now<<1])  {q.push(now<<1);  cnt[now<<1]=cnt[now]+1;}
	}
	printf("%d",cnt[goal]-1);
	return 0; 
}
