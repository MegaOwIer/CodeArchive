#include<bits/stdc++.h>
using namespace std;

using LL=long long;
using pii=pair<int,int>;
#define endl "\n"

int N,ans,cnt[2][10][10];

inline int getid(char c)
{
    if(c=='M')return 0;
    if(c=='S')return 1;
    return 2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        string s;
        cin>>s;
        cnt[0][s.length()][getid(s.back())]++;
    }
    for(int i=1;i<=N;i++)
    {
        string s;
        cin>>s;
        cnt[1][s.length()][getid(s.back())]++;
    }
    for(int i=1;i<=4;i++)for(int j=0;j<3;j++)
        ans+=abs(cnt[0][i][j]-cnt[1][i][j]);
    cout<<ans/2<<endl;
    return 0;
}
