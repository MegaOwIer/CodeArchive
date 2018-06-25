#include<bits/stdc++.h>
using namespace std;

using sta=tuple<int,int,int>;
using pii=pair<int,int>;
const int MX=55;
#define endl "\n"
#define st first
#define nd second

int N,K,G[5][MX],res;
vector<sta> ans;
vector<pii> pos;

bool check()
{
    if(K!=N*2)return false;
    for(int i=1;i<=N;i++)
        if(G[1][i]==G[2][i]||G[3][i]==G[4][i])
            return false;
    return true;
}
int modify()
{
    int cnt=0;
    for(int i=1;i<=N;i++)
    {
        if(G[1][i]==G[2][i]&&G[1][i])
        {
            ans.push_back(make_tuple(G[2][i],1,i));
            G[2][i]=0,++cnt;
        }
        if(G[3][i]==G[4][i]&&G[3][i])
        {
            ans.push_back(make_tuple(G[3][i],4,i));
            G[3][i]=0,++cnt;
        }
    }
    return cnt;
}
void work(int s)
{
    ans.push_back(make_tuple(G[pos[s].st][pos[s].nd],pos[s-1].st,pos[s-1].nd));
    swap(G[pos[s].st][pos[s].nd],G[pos[s-1].st][pos[s-1].nd]);
    int ed=s==1?2*N:s-1;
    for(int i=s+1;;i++)
    {
        if(i==pos.size())i=1;
        if(i==ed)return;
        if(!G[pos[i].st][pos[i].nd])continue;
        ans.push_back(make_tuple(G[pos[i].st][pos[i].nd],pos[i-1].st,pos[i-1].nd));
        swap(G[pos[i].st][pos[i].nd],G[pos[i-1].st][pos[i-1].nd]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>K;
    for(int i=1;i<=4;i++)for(int j=1;j<=N;j++)cin>>G[i][j];
    if(check())return puts("-1"),0;
    res=K;
    pos.push_back(make_pair(3,1));
    for(int i=1;i<=N;i++)pos.push_back(make_pair(2,i));
    for(int i=N;i;i--)pos.push_back(make_pair(3,i));
    while(true)
    {
        res-=modify();
        if(!res)break;
        for(int i=1;i<pos.size();i++)
            if(G[pos[i].st][pos[i].nd]&&!G[pos[i-1].st][pos[i-1].nd])
                {work(i);break;}
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)
        cout<<get<0>(i)<<' '<<get<1>(i)<<' '<<get<2>(i)<<endl;
    return 0;
}
