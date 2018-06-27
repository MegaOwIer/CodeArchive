#include<bits/stdc++.h>
using namespace std;

using LL=long long;

int S,T,mod;
unordered_map<int,pair<int,int> > G[2];
queue<int> Q;

int Inv(int u){return u<=1?u:LL(mod-mod/u)*Inv(mod%u)%mod;}
inline int inc(int a){return ((++a)==mod)&&(a=0),a;}
inline int dec(int a){return ((--a)==-1)&&(a=mod-1),a;}
inline unsigned RD()
{
    static unsigned seed=time(NULL);
    return seed^=seed<<12,seed^=seed>>7,seed^=seed<<4;
}
void work(unordered_map<int,pair<int,int> > &G,int S)
{
    for(int i=1,cur=S,tmp;i<=100;i++,cur=tmp)
    {
        switch(RD()%3)
        {
            case 0:tmp=inc(cur);break;
            case 1:tmp=dec(cur);break;
            case 2:tmp=Inv(cur);break;
        }
        if(!G.count(tmp))G[tmp]=make_pair(i,cur);
        else G[tmp]=min(G[tmp],make_pair(i,cur));
    }
}
inline int check(int s,int t)
{
    if(inc(s)==t)return 1;
    if(dec(s)==t)return 2;
    return 3;
}
void print(int u)
{
    vector<int> ans;
    for(int i=u;i!=S;i=G[0][i].second)
        ans.push_back(check(G[0][i].second,i));
    reverse(ans.begin(),ans.end());
    for(int i=u;i!=T;i=G[1][i].second)
        ans.push_back(check(i,G[1][i].second));
    cout<<ans.size()<<endl;
    for(int i:ans)cout<<i<<' ';
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>S>>T>>mod;
    int B=sqrt(mod);
    G[0][S]=G[1][T]=make_pair(0,-1);
    for(int i=1;i<=B;i++)work(G[0],S);
    for(int i=1;i<=B;i++)work(G[1],T);
    for(auto i:G[0])if(G[1].count(i.first))
        return print(i.first),0;
    throw;
    return 23333;
}
