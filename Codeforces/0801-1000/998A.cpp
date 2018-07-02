#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int N,a[15],S;

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=0;i<N;i++)cin>>a[i],S+=a[i];
    for(int i=1;i<(1<<N)-1;i++)
    {
        int tmp=0;
        for(int j=0;j<N;j++)if((i>>j)&1)
            tmp+=a[j];
        if(tmp+tmp!=S)
        {
            cout<<__builtin_popcount(i)<<endl;
            for(int j=0;j<N;j++)if(i>>j&1)
                cout<<j+1<<' ';
            return 0;
        }
    }
    return puts("-1"),0;
}
