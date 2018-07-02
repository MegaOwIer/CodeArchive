#include<bits/stdc++.h>
using namespace std;

using LL=long long;
using pli=pair<LL,int>;
const int MX=200005;
#define endl "\n"

int N;
LL ans[MX];
vector<pli> pos;

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        LL l,r;
        cin>>l>>r;
        pos.push_back(make_pair(l,1));
        pos.push_back(make_pair(r+1,-1));
    }
    sort(pos.begin(),pos.end());
    for(int i=0,j=0,cnt=0;i<pos.size();i=j)
    {
        while(j<pos.size()&&pos[i].first==pos[j].first)
            cnt+=pos[j].second,j++;
        if(j<pos.size())ans[cnt]+=pos[j].first-pos[i].first;
    }
    for(int i=1;i<=N;i++)cout<<ans[i]<<' ';
    return 0;
}
