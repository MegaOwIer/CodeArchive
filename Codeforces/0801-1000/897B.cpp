#include<bits/stdc++.h>
using namespace std;
using LL=long long;

int N,P,ans;
string a,b;

inline int read(const char *s,int l)
{
    LL ans=0;
    for(int i=0;i<l;i++)ans=ans*10+s[i]-'0';
    return ans%P;
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>P;
    for(int i=1;i<=N;i++)
    {
        a=b=to_string(i);
        reverse(b.begin(),b.end());
        ans=(ans+read((a+b).c_str(),2*a.length()))%P;
    }
    cout<<ans<<endl;
}