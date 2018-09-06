#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
const int MX=100005;

int N,S,res,B;
vector<int> ans[MX];

int getS(int N)
{
    int cur=INT_MAX,id=0;
    for(int i=1;i<=N;i++)
    {
        int tmp=i+N/i;
        if(N%i)tmp++;
        if(tmp<cur)cur=tmp,id=i;
    }
    return id;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>N;
    S=getS(N);
    B=N/S,res=N%S;
    for(int i=1,j=N;i<=S;i++)
    {
        for(int k=1;k<=B;k++)ans[i].push_back(j--);
        if(i<=res)ans[i].push_back(j--);
    }
    for(int i=1;i<=S;i++)
    {
        reverse(ans[i].begin(),ans[i].end());
        for(int k:ans[i])cout<<k<<' ';
    }
    return 0;
}
