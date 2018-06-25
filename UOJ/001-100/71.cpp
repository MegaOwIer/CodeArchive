#include<bits/stdc++.h>
using namespace std;

namespace FastIO
{
	char c;
	int bf[22],tp;
	template<typename T>inline void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>inline void write(T x)
	{
		tp=0;
		do bf[++tp]=x%10,x/=10;while(x);
		while(tp)putchar(48+bf[tp--]);
		putchar('\n');
	}
}
using FastIO::read;
using FastIO::write;

int n,m,s,t,k;

namespace Subtask1
{
    typedef long long LL;

	int u[22],v[22],w[22],cnt,now;
    LL ans[1<<20|3];
	queue<int> q;
	char vis[12];
	
	inline void check(int S)
	{
		LL res=0;
		for(int i=0;i<m;i++)if((S>>i)&1)res+=w[i];
		while(!q.empty())q.pop();
		q.push(s);
		memset(vis+1,0,sizeof(char)*n),vis[s]=1;
		while(!q.empty())
		{
			now=q.front(),q.pop();
			if(now==t)return;
			for(int i=0;i<m;i++)if((~S)&(1<<i))
				if(u[i]==now&&!vis[v[i]])vis[v[i]]=1,q.push(v[i]);
		}
		ans[++cnt]=res;
	}
	void work()
	{
		for(int i=0;i<m;i++)read(u[i]),read(v[i]),read(w[i]);
		for(int i=(1<<m)-1;~i;i--)check(i);
		sort(ans+1,ans+cnt+1);
		for(int i=1;i<=k&&i<=cnt;i++)write(ans[i]);
		if(k>cnt)puts("-1");
	}
}

namespace Subtask2
{
    typedef long long LL;
    const int MXN=55,MXM=1505;
    
    struct edge{int to,nxt;}e[MXM<<1];
    int tot=1,head[MXN],cur[MXN],dep[MXN],u[MXM],v[MXM];
    LL w[MXM],ds[MXN],dt[MXN];
    char hvs[MXN],hvt[MXN],vis[MXN],in[MXM];
    queue<int> q;
    struct Graph
    {
        LL w[MXM<<1];

        void add(int u,int v,LL z)
        {
            e[++tot]=(edge){v,head[u]},head[u]=tot,w[tot]=z;
            e[++tot]=(edge){u,head[v]},head[v]=tot,w[tot]=0;
        }
        bool bfs(int S,int T)
        {
            int now;
            memset(dep+1,-1,sizeof(int)*n);
            dep[S]=0,q.push(S);
            while(!q.empty())
            {
                now=q.front(),q.pop();
                for(int i=head[now];i;i=e[i].nxt)if(w[i]&&!~dep[e[i].to])
                    dep[e[i].to]=dep[now]+1,q.push(e[i].to);
            }
            return ~dep[T];
        }
        LL dfs(int u,LL flow,int T)
        {
            LL t,used=0;
            if(u==T||!flow)return flow;
            for(int &i=cur[u];i;i=e[i].nxt)
                if(dep[e[i].to]==dep[u]+1&&w[i])
                {
                    t=dfs(e[i].to,min(flow-used,w[i]),T);
                    w[i]-=t,w[i^1]+=t,used+=t;
                    if(used==flow)return flow;
                }
            if(!used)dep[u]=-1;
            return used;
        }
        LL dinic(int S,int T)
        {
            LL ans=0;
            while(bfs(S,T))
            {
                memcpy(cur+1,head+1,sizeof(int)*n),ans+=dfs(S,1e18,T);
                if(ans>=1e18)return 1e18;
            }
            return ans;
        }
        void dfs2(int u)
        {
            vis[u]=1;
            for(int i=head[u];i;i=e[i].nxt)if(w[i]&&!vis[e[i].to])
                dfs2(e[i].to);
        }
        void get_cur()
        {
            memset(vis+1,0,sizeof(char)*n);
            memset(in+1,0,sizeof(char)*m);
            dfs2(s);
            for(int i=1;i<=m;i++)
                if(vis[u[i]]&&!vis[v[i]])in[i]=1;
        }
    }G,tmp,tmp2;
    struct Node
    {
        LL val,ww;
        int id;
        bool mst[MXM],stp[MXM];
        
        bool operator < (const Node& a)const{return a.val<val;}
        void build()
        {
            val=0,tmp=G;
            for(int i=1;i<=m;i++)
                if(mst[i])
                    val+=w[i],tmp.w[i<<1]=0,tmp.w[i<<1|1]=0;
                else if(stp[i])
                    tmp.w[i<<1]=1e18,tmp.w[i<<1|1]=0;
            val+=tmp.dinic(s,t);
            tmp.get_cur();
            memset(hvs+1,0,sizeof(char)*n);
            memset(hvt+1,0,sizeof(char)*n);
            id=0,ww=1e18;
            for(int i=1;i<=m;i++)if(!mst[i]&&!stp[i])
            {
                if(in[i])
                {
                    if(!hvs[u[i]])
                        hvs[u[i]]=1,tmp2=tmp,ds[u[i]]=tmp2.dinic(s,u[i]);
                    if(!hvt[v[i]])
                        hvt[v[i]]=1,tmp2=tmp,dt[v[i]]=tmp2.dinic(v[i],t);
                    if(ds[u[i]]<ww)ww=ds[u[i]],id=i;
                    if(dt[v[i]]<ww)ww=dt[v[i]],id=i;
                }
                else if(w[i]<ww)ww=w[i],id=i;
            }
            val+=ww;
        }
    }a,b;
    priority_queue<Node> Q;

	void work()
	{
        for(int i=1;i<=m;i++)
        {
            read(u[i]),read(v[i]),read(w[i]);
            G.add(u[i],v[i],w[i]);
        }
        k--,tmp=G,write(tmp.dinic(s,t));
        a.build();
        if(a.val<1e18)Q.push(a);
        while(!Q.empty()&&k>0)
        {
            a=b=Q.top(),Q.pop(),k--;
            write(a.val);
            a.mst[a.id]=1,a.build();
            if(a.val<1e18)Q.push(a);
            b.stp[b.id]=1,b.build();
            if(b.val<1e18)Q.push(b);
        }
        if(k)puts("-1");
	}
}

namespace Subtask3
{
	typedef long long LL;
	typedef pair<int,int> pii;
	const int MX=150005;
#define st first
#define nd second
#define mp make_pair

	LL ans;
	int pre[MX],nxt[MX],cnt;
	struct Node
	{
		int pos,id;LL val;
		bool operator < (const Node& a)const{return val>a.val;}
	}tmp;
	priority_queue<Node> q;
	pii a[MX];

	void work()
	{
		for(int i=1,u,v,w;i<=m;i++)
		{
			read(u),read(v),read(w);
			if(u==s)pre[v]=w;
			else nxt[u]=w;
		}
		for(int i=1;i<=n;i++)if(i!=s&&i!=t)
		{
			if(pre[i]>nxt[i])swap(pre[i],nxt[i]);
			ans+=pre[i],++cnt;
			a[cnt]=mp(nxt[i]-pre[i],pre[i]);
		}
		sort(a+1,a+cnt+1);
		write(ans),k--;
		q.push((Node){1,1,ans+a[1].st});
		while(!q.empty()&&k>0)
		{
			tmp=q.top(),q.pop();
			write(tmp.val),k--;
			if(tmp.id<2)q.push((Node){tmp.pos,2,tmp.val+a[tmp.pos].nd});
			if(tmp.id==1&&tmp.pos<cnt)
				q.push((Node){tmp.pos+1,1,tmp.val-a[tmp.pos].st+a[tmp.pos+1].st});
			if(tmp.pos<cnt)q.push((Node){tmp.pos+1,1,tmp.val+a[tmp.pos+1].st});
		}
		if(k>0)puts("-1");
	}
#undef st
#undef nd
#undef mp
}

int main()
{
	read(n),read(m),read(s),read(t),read(k);
	if(n<=10&&m<=20)Subtask1::work();
	else if(n<=50&&m<=1500&&k<=100)Subtask2::work();
	else Subtask3::work();
	return 0;
}
