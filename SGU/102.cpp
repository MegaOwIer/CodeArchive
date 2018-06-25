#include<bits/stdc++.h>
using namespace std;

int N;

int phi(int N)
{
    int ans=N;
    for(int i=2;i*i<=N;i++)if(N%i==0)
    {
        ans-=ans/i;
        while(N%i==0)N/=i;
    }
    if(N>1)ans-=ans/N;
    return ans;
}

int main()
{
    scanf("%d",&N);
    printf("%d\n",phi(N));
    return 0;
}
