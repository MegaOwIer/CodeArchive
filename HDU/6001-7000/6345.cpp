#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
const int MX=100005;

int T,N,Q,pre[MX][26];
char s[MX];

int solve(int L,int R)
{
    for(int i=0;i<26;i++)
        if(pre[R][i]!=pre[L][i])return pre[R][i]-pre[L][i];
}

void work()
{
    cin>>N>>Q>>(s+1);
    for(int i=1;i<=N;i++)
    {
        memcpy(pre[i],pre[i-1],sizeof(pre[i]));
        ++pre[i][s[i]-'A'];
    }
    while(Q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<solve(l-1,r)<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cout<<"Case #"<<i<<":"<<endl;
        work();
    }
    return 0;
}
