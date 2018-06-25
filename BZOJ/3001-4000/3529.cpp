#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

struct Ques
{
	int n,m,a,id;
	bool operator<(const Ques& m)const{return a<m.a;}
}q[20005];
int Q,d[MX],pr[MX],cnt,ans[20005],now=1,miu[MX],tr[MX];
pair<int,int> N[MX];
#define tao(i) N[i].first

inline int read(int& x)
{
	static char c;
	c=getchar(),x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void insert(int u,int v){for(;u<=100000;u+=u&-u)tr[u]+=v;}
inline int ask(int u){int ans=0;for(;u;u-=u&-u)ans+=tr[u];return ans;}

int main()
{
	for(int i=1;i<=100000;i++)N[i].second=i;
	d[1]=1,tao(1)=1,miu[1]=1;
	for(int i=2,tmp,j;i<=100000;i++)
	{
		if(!d[i])pr[++cnt]=i,tao(i)=i+1,d[i]=i,miu[i]=-1;
		for(j=1;j<=cnt&&(tmp=i*pr[j])<=100000;j++)
		{
			if(i%pr[j]==0)
			{
				d[tmp]=d[i]*pr[j],miu[tmp]=0;
				tao(tmp)=tao(i/d[i])*(tao(d[i])+d[tmp]);
				break;
			}
			d[tmp]=pr[j],tao(tmp)=tao(i)*(pr[j]+1),miu[tmp]=-miu[i];
		}
	}
	read(Q);
	for(int i=1;i<=Q;i++)
		read(q[i].n),read(q[i].m),read(q[i].a),q[i].id=i;
	sort(q+1,q+Q+1),sort(N+1,N+100001);
	for(int i=1;i<=Q;i++)
	{
		while(tao(now)<=q[i].a&&now<=100000)
		{
			for(int j=1;j*N[now].second<=100000;j++)
				insert(j*N[now].second,tao(now)*miu[j]);
			now++;
		}
		if(q[i].n>q[i].m)swap(q[i].n,q[i].m);
		for(int j=1,pos;j<=q[i].n;j=pos+1)
		{
			pos=min(q[i].n/(q[i].n/j),q[i].m/(q[i].m/j));
			ans[q[i].id]+=(q[i].n/j)*(q[i].m/j)*(ask(pos)-ask(j-1));
		}
	}
	for(int i=1;i<=Q;i++)printf("%d\n",ans[i]&2147483647);
	return 0;
}
