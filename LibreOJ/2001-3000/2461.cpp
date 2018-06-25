#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MX=100005,B=320;

int N,M,a[MX],lim[MX],ans[MX],tmp[MX],id[MX],res[MX];
vector<pii> ex[MX];
vector<int> x[B];

struct oper{int l,r,x;}A[MX];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
inline int insert(int L,int R,int l,int r,int val,int mx)
{
    if(l>r)return mx;
    for(int i=l;i<=r;i++)res[i]+=val;
    return *max_element(res+L,res+R+1);
}
void solve(int L,int R)
{
    int mx=0,tag=0,tot=0,siz=R-L+1;
    mx=*max_element(res+L,res+R+1);
    for(int i=1,nw=1;i<=M;i++)
    {
        while(nw<=M&&mx+tag>=0)
        {
            int l=A[nw].l,r=A[nw].r;
            if(l<=L&&r>=R)tag--;
            else mx=insert(L,R,max(L,l),min(R,r),-1,mx);
            nw++;
        }
        if(A[i].l<=L&&A[i].r>=R)tag++,lim[i]=max(lim[i],nw-2);
        else mx=insert(L,R,max(L,A[i].l),min(R,A[i].r),1,mx);
    }
    for(int i=1;i<=siz;i++)x[i].clear();
    for(int i=1;i<=M;i++)
        if(A[i].l<=L&&A[i].r>=R)tmp[i]=1,id[++tot]=i;
        else
        {
            tmp[i]=0;
            int k1=max(A[i].l,L),k2=min(A[i].r,R);
            for(int j=k1;j<=k2;j++)x[j-L+1].push_back(i);
        }
    for(int i=1;i<=M;i++)tmp[i]+=tmp[i-1];
    for(int it=1;it<=siz;it++)
    {
        int cur=a[it+L-1];
        vector<int>::iterator i,nw=x[it].begin();
        for(i=x[it].begin();i!=x[it].end();i++)
        {
            if(tmp[M]-tmp[*i]+(x[it].end()-i)-1<cur)
            {
                lim[*i]=max(lim[*i],M+1);
                continue;
            }
            while(nw!=x[it].end()&&tmp[*nw]-tmp[*i]+(nw-i)<cur)nw++;
            if(nw!=x[it].end())
            {
                int num=tmp[*nw]-tmp[*i]+(nw-i);
                if(num==cur)
                {
                    lim[*i]=max(lim[*i],*nw-1);
                    continue;
                }
            }
            int pos=tmp[*i]+(cur-(nw-i-1));
            lim[*i]=max(lim[*i],id[pos]-1);
        }
    }
}

int main()
{
    N=read(),M=read();
    for(int i=1;i<=N;i++)res[i]=a[i]=read();
    for(int i=1;i<=M;i++)A[i].l=read(),A[i].r=read(),A[i].x=read();
    A[++M]=(oper){1,1,1};
    for(int i=1;i<=M;i++)lim[i]=i;
    for(int i=1,j=B;i<=N;i+=B,j+=B)solve(i,min(j,N));
    for(int i=1;i<=M;i++)ex[A[i].x].push_back(make_pair(i,lim[i]));
    for(int i=1;i<=100000;i++)if(!ex[i].empty())
    {
        sort(ex[i].begin(),ex[i].end());
        int L=ex[i][0].first,R=ex[i][0].second;
        for(int j=1;j<=ex[i].size();j++)
            if(j==ex[i].size()||ex[i][j].first>R)
                ans[L]++,ans[R+1]--,L=ex[i][j].first,R=ex[i][j].second;
            else R=max(R,ex[i][j].second);
    }
    for(int i=1;i<M;i++)ans[i]+=ans[i-1],printf("%d\n",ans[i]);
    return 0;
}
