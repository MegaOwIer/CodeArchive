#include<bits/stdc++.h>
using namespace std;

int ans;
string s;

inline bool judge(int l)
{
    if(!l)return true;
    for(int i=1;i<=l;i++)
        if(s[i-1]!=s[l-i])return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>s;
    ans=s.length();
    while(!judge(ans))ans--;
    cout<<ans<<endl;
    return 0;
}

