#include<bits/stdc++.h>
using namespace std;

int N,cnt;
char s[105];

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>(s+1);
    if(N==1&&s[1]=='0')return puts("0"),0;
    for(int i=1;i<=N;i++)if(s[i]=='0')cnt++;
    putchar('1');
    for(int i=1;i<=cnt;i++)putchar('0');
    return 0;
}