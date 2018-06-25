#include<bits/stdc++.h>
using namespace std;

long long N,x;

int main()
{
    cin>>N>>x;
    cout<<3*(N-__gcd(N,x))<<endl;
    return 0;
}