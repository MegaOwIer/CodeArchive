#include<bits/stdc++.h>
using namespace std;
const int MX=300005;
#define endl "\n"

int N,X1,X2,a[MX],b[MX],pa[MX],pb[MX];
pair<int,int> S[MX];

inline void print(int u,int v)
{
    cout<<"Yes"<<endl;
    cout<<a[u]<<' '<<b[v]<<endl;
    if(u>v)
    {
        u=a[u],v=b[v];
        for(int i=1;i<=u;i++)cout<<S[i+v].second<<' ';
        cout<<endl;
        for(int i=1;i<=v;i++)cout<<S[i].second<<' ';
    }
    else
    {
        u=a[u],v=b[v];
        for(int i=1;i<=u;i++)cout<<S[i].second<<' ';
        cout<<endl;
        for(int i=1;i<=v;i++)cout<<S[i+u].second<<' ';
    }
    exit(0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>X1>>X2;
    for(int i=1;i<=N;i++)
        cin>>S[i].first,S[i].second=i;
    sort(S+1,S+N+1,greater<pair<int,int> >());
    for(int i=1;i<=N;i++)
    {
        a[i]=X1/S[i].first+int(bool(X1%S[i].first));
        pa[i]=(a[i]<=i?i:pa[i-1]);
        b[i]=X2/S[i].first+int(bool(X2%S[i].first));
        pb[i]=(b[i]<=i?i:pb[i-1]);
    }
    for(int i=1;i<=N;i++)
    {
        int j=upper_bound(b+1,b+i+1,i-a[i])-b-1;
        if(j&&pb[j])print(i,pb[j]);
    }
    for(int j=1;j<=N;j++)
    {
        int i=upper_bound(a+1,a+j+1,j-b[j])-a-1;
        if(i&&pa[i])print(pa[i],j);
    }
    return puts("No"),0;
}