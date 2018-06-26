#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef tuple<int,int,int> Edge;
const int MX=500005;
const double eps=1e-6;

int N,M,fa[MX];
Edge E[MX];
LD fans;

struct edge
{
    int u,v,flag;
    double w;
    
    edge(){}
    edge(int u,int v,int f,double w):u(u),v(v),flag(f),w(w){}
    bool operator < (const edge& a)const{return w>a.w;}
};

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
int check(double val)
{
    static int tag=0;
	vector<edge> black,red,e;
#define get(d) get<d>(E[i])
    for(int i=1;i<=M;i++)
        if(get(2)>val)black.push_back(edge(get(0),get(1),1,get(2)-val));
        else if(fabs(get(2)-val)<eps)black.push_back(edge(get(0),get(1),0,0));
        else red.push_back(edge(get(0),get(1),-1,val-get(2)));
#undef get
    reverse(red.begin(),red.end());
    e.resize(black.size()+red.size());
    merge(black.begin(),black.end(),red.begin(),red.end(),e.begin());
    for(int i=1;i<=N;i++)fa[i]=i;
    int tmp=0,cnt=0;
    LD ans=0;
    double mn=0;
    for(auto it:e)
    {
        int _u=find(it.u),_v=find(it.v);
        if(_u==_v)continue;
        ans+=it.w,fa[_u]=_v;
        if(it.flag==1)
        {
            ++tmp;
            if(tmp>0)mn=it.w;
        }
        else if(it.flag==-1)
        {
            --tmp;
            if(tmp<0)mn=it.w;
        }
        else if(tmp)tmp>0?++tmp:--tmp;
        else ++tmp,mn=0;
        if(++cnt==N-1)break;
    }
    if(!tmp)return fans=ans,0;
    else if(tmp==1||tmp==-1)
    {
        fans=max(fans,ans-mn);
        if(tmp==1)tag|=1;
        else tag|=2;
        return tag==3?0:tmp;
    }
    else return tmp>0?1:-1;
}

int main()
{
    N=read(),M=read();
    for(int i=1,u,v,w;i<=M;i++)
    {
    	u=read(),v=read(),w=read();
    	E[i]=make_tuple(u,v,w);
    }
    sort(E+1,E+M+1,[](const Edge& a,const Edge& b){return get<2>(a)>get<2>(b);});
    double L=0,R=1000000005,mid,res;
    while(R-L>0.7)
    {
        res=check(mid=(L+R)/2);
        if(res==0)break;
        if(res>0)L=mid;
        else R=mid;
    }
    printf("%lld\n",LL(fans+0.5));
    return 0;
}
