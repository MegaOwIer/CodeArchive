#include<bits/stdc++.h>
using namespace std;
const int MX=233340,mod=1000000007;

int N,dp[MX],ans;

inline void read(int& x)
{
    static char c;
    c=getchar(),x=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
}
inline void update(int& a,int b){a+=b;if(a>=mod)a-=mod;}

int main()
{
    read(N);
    for(int x,y,z;N--;)
    {
        read(x),update(ans,dp[x]),y=dp[x]+1;
        for(z=x;z;z=(z-1)&x)update(dp[z],y);
    }
    cout<<ans<<endl;
    return 0;
}