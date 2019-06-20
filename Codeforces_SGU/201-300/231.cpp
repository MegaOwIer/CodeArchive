#include<bits/stdc++.h>
using namespace std;

const int MX = 1000005;

int cnt, prime[78501];
bool vis[MX];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vis[1] = true;
    for(int i = 2; i <= n; i++) {
        if(!vis[i]) prime[++cnt] = i;
        for(int j = 1; j <= cnt && i * prime[j] <= n; j++) {
            vis[i * prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
    int ans = 0;
    for(int i = n; i >= 5; i--)
        if(!vis[i] && !vis[i - 2]) ++ans;
    printf("%d\n", ans);
    for(int i = 3; i <= n - 2; i++)
        if(!vis[i] && !vis[i + 2])
            printf("2 %d\n", i);
    return 0;
}
