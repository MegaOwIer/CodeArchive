#include<bits/stdc++.h>
using namespace std;
const int MX=100000*2+5;

int N;
char s[MX];
vector<pair<int,int> > ans;

int main()
{
    ios::sync_with_stdio(0);
    cin>>(s+1);
    N=strlen(s+1)/2;
    for(int i=1,j=1;i<=N;i++,j++)if(s[i]==')')
    {
        while(s[j]==')')j++;
        ans.push_back(make_pair(i,j));
        swap(s[i],s[j]);
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)cout<<i.first<<' '<<i.second<<'\n';
    return 0;
}