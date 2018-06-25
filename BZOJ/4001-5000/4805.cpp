#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=5000005;

int N,pr[348520],cnt;
LL phi[MX],ans[500];

LL solve(int u)
{
    if(u<=5e6)return phi[u];
    if(ans[N/u])return ans[N/u];
    LL res=LL(u+1)*u/2;
    for(int i=2,j;i<=u;i=j+1)
        j=u/(u/i),res-=solve(u/i)*(j-i+1);
    return ans[N/u]=res;
}

int main()
{
    phi[1]=1;
    for(int i=2,tmp;i<=5e6;i++)
    {
        if(!phi[i])pr[++cnt]=i,phi[i]=i-1;
        for(int j=1;j<=cnt&&(tmp=i*pr[j])<=5e6;j++)
        {
            if(i%pr[j]==0){phi[tmp]=phi[i]*pr[j];break;}
            phi[tmp]=phi[i]*(pr[j]-1);
        }
    }
    for(int i=2;i<=5e6;i++)phi[i]+=phi[i-1];
    cin>>N;
    cout<<solve(N)<<endl;
    return 0;
}