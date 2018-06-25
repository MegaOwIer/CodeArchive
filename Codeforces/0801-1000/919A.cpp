#include<bits/stdc++.h>
using namespace std;

int n,m,a,b;
double ans=1e20;

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        ans=min(ans,(double)a/b);
    }
    printf("%.8lf",ans*m);
    return 0;
}