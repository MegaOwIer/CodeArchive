#include<bits/stdc++.h>
using namespace std;

int N,cnt[127];
char s[105];

int main()
{
    ios::sync_with_stdio(0);
    cin>>(s+1);
    N=strlen(s+1);
    cnt[s[1]]++,cnt[s[2]]++;
    for(int i=3;i<=N;i++)
    {
        cnt[s[i]]++,cnt[s[i-3]]--;
        if(cnt['A']&&cnt['B']&&cnt['C'])return puts("Yes"),0;
    }
    return puts("No"),0;
}
