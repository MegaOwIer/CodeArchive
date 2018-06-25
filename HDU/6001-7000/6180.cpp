#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int T,N,ans;
long long tot;
pair<int,int> s[MX<<1];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

int main()
{
    T=read();
    while(T--)
    {
        N=read();
        for(int i=1,u,v;i<=N;i++)
            s[i*2-1]=make_pair(read(),i),s[i*2]=make_pair(read(),-i);
        sort(s+1,s+N*2+1);
        ans=tot=0;
        for(int i=1,tmp=0;i<=2*N;i++)
        {
            if(s[i].second>0)tmp++;
            else tmp--;
            if(tmp>ans)ans=tmp,tot-=s[i].first;
        }
        ans=0;
        for(int i=N*2,tmp=0;i;i--)
        {
            if(s[i].second<0)tmp++;
            else tmp--;
            if(tmp>ans)ans=tmp,tot+=s[i].first;
        }
        printf("%d %lld\n",ans,tot);
    }
    return 0;
}