#include <bits/stdc++.h>
using namespace std;

const int MX = 1005;

long long dp[MX];
vector<int> prime;
bool vis[MX];

void update(int p, int n) {
    for(int i = n; i >= p; i--) {
        for(int k = p; k <= i; k *= p) {
            dp[i] += dp[i - k];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    dp[0] = 1;
    for(int i = 2; i <= n; i++) {
        if(!vis[i]) {
            prime.push_back(i);
            update(i, n);
        }
        for(int p : prime) {
            int tmp = i * p;
            if(tmp > n) break;
            vis[tmp] = true;
            if(i % p == 0) break;
        }
    }
    long long ans = 0;
    for(int i = 0; i <= n; i++) ans += dp[i];
    printf("%lld\n", ans);
    return 0;
}
