#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

int T,cnta,cntb;
long long A,B;

int main()
{
    ios::sync_with_stdio(0);
    cin>>T;
    while(T--)
    {
        cin>>A>>B;
        int cnta=__builtin_popcountll(A);
        int cntb=__builtin_popcountll(B-1);
        if(A==B)cout<<0<<endl;
        else if(B==0)cout<<-1<<endl;
        else if(cntb>=cnta)cout<<cntb-cnta+1<<endl;
        else if(B==1)cout<<-1<<endl;
        else cout<<2<<endl;
    }
    return 0;
}
