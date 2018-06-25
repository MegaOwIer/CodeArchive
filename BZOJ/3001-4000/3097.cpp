#include<bits/stdc++.h>
using namespace std;

int N=2119,K=1024;
char s[10005];

int main()
{
    s[1]='b';
    for(int i=1,nw=1;i<=11;i++,nw<<=1)
        for(int j=1;j<=nw;j++)s[nw+j]=s[j]^1;
    s[2049]='e';
    for(int i=2050,j=1;j<=70;i++,j++)s[i]='d';
    printf("%d %d\n%s\n",N,K,s+1);
    return 0;
}
