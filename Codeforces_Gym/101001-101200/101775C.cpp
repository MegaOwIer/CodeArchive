#include <bits/stdc++.h>
using namespace std;

int read()
{
    int x = 0, c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x;
}

int main()
{
    int T = read();
    for(int i = 1; i <= T; i++)
    {
        int N = read(), mx = 0;
        long long ans = 0;
        for(int j = 0; j <= N; j++) ans += read();
        for(int i = 1; i <= N; i++) read(), mx = max(mx, read());
        printf("Case #%d: %lld.0000000000\n", i, ans + mx);
    }
    return 0;
}