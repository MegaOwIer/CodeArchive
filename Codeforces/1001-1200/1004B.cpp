#include<bits/stdc++.h>
using namespace std;

using pii=pair<int,int>;
const int MX=1005;
#define endl "\n"

int N,M,tag;
set<int> R[MX];
vector<pii> ans;
char s[MX];

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>M;
    fill(s+1,s+N+1,'0');
    for(int i=1,l,r;i<=M;i++)cin>>l>>r,R[l].insert(r);
    pair<int,int> lst=make_pair(-1,-1);
    for(int i=1;i<=N;i++)if(!R[i].empty())
    {
        if(i!=1)
        {
            ans.push_back(make_pair(lst.first,min(i-1,lst.second)));
            if(lst.second>=i)R[i].insert(lst.second);
        }
        int r=*R[i].begin();
        for(int j:R[i])if(j>r)R[r+1].insert(j);
        lst=make_pair(i,r);
    }
    ans.push_back(lst);
    for(auto i:ans)
        if((i.second-i.first)&1)
            for(int j=i.first;j<=i.second;j++)s[j]=tag+'0',tag^=1;
        else for(int j=i.first;j<=i.second;j++)s[j]='0'+(j&1);
    cout<<(s+1)<<endl;
    return 0;
}
