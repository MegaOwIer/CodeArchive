#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int n,m,tr[MX],x[MX],ans;
int B[MX],A1[MX],A2[MX];

inline void add(int x,int val){for(;x<=m;x+=x&-x)tr[x]+=val;}
inline int ask(int x){int ans=0;for(;x;x-=x&-x)ans+=tr[x];return ans;}

inline void LIS(int *A)
{
    int ans=1;
    memset(B,0,sizeof(B));
    B[1]=x[1];
    A[1]=1;
    for(int i=2;i<=m;i++)
    {
        int tmp=upper_bound(B+1,B+ans+1,x[i])-B;
        A[i]=tmp;
        B[tmp]=x[i];
        ans=max(ans,tmp);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1,l,r;i<=n;i++)
    {
        cin>>l>>r;
        add(r+1,-1),add(l,1);
    }
    for(int i=1;i<=m;i++)x[i]=ask(i);
    LIS(A1);
    reverse(x+1,x+m+1);
    LIS(A2);
    for(int i=1;i<=m;i++)ans=max(ans,A1[i]+A2[m+1-i]-1);
    cout<<ans<<endl;
    return 0;
}
