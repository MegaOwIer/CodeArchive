#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using LD=long double;

int N,d1,x;

LD solve(int N,LD s,LD d)
{
    if(!N)return 0;
    return s+N*d-d/2+solve(N-1,s+(s*2+5*d)/N/2,d+2*d/N);
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>d1>>x;
    cout<<fixed<<setprecision(12)<<solve(N,d1,x)<<endl;
    return 0;
}