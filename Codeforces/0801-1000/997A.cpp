#include<bits/stdc++.h>
using namespace std;

using LL=long long;
#define endl '\n'
const int MX=300005;

int N,x,y;
LL ans;
char s[MX];

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>x>>y>>(s+1);
    N=unique(s+1,s+N+1)-s-1;
    if(N==1)return printf("%d\n",s[1]=='1'?0:y),0;
    int cnt=0;
    for(int i=2;i<N;i++)if(s[i]=='1')cnt++;
    if(x>y)ans=LL(cnt+1)*y;
    else ans=y+(LL)cnt*x;
    cout<<ans<<endl;
    return 0;
}
