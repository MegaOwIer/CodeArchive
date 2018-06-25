#include<bits/stdc++.h>
using namespace std;

int N,K,S,P,tmp;

int main()
{
    ios::sync_with_stdio(0);
    cin>>K>>N>>S>>P;
    tmp=(N/S+int(bool(N%S)))*K;
    cout<<tmp/P+int(bool(tmp%P))<<endl;
    return 0;
}