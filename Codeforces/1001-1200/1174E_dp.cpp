#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 1000006, mod = 1000000007;

int n, ans, d, pw2, num[23], dp[21][MX];

int solve1(int k, int d) {
    num[0] = n;
    for(int i = 1; i <= d; i++) num[i] = num[i - 1] >> 1;
    for(int i = 0; i < d; i++) num[i] -= num[i + 1];
    for(int i = d - 1; i >= 0; i--) num[i] += num[i + 1];
    for(int i = 0; i <= d; i++)
        memset(dp[i] + 1, 0, sizeof(int[num[i]]));
    dp[d][1] = 1;
    for(int i = d; i > 0; i--)
        for(int j = 1, val = num[i]; j <= val; j++) if(dp[i][j]) {
            dp[i][j + 1] = (dp[i][j + 1] + dp[i][j] * LL(val - j)) % mod;
            dp[i - 1][j + 1] = (dp[i - 1][j + 1] + dp[i][j] * LL(num[i - 1] - val)) % mod;
        }
    for(int j = 1; j <= n; j++) if(dp[0][j])
        dp[0][j + 1] = (dp[0][j + 1] + dp[0][j] * LL(n - j)) % mod;
    return dp[0][n];
}

int f[23];
int solve2(int k, int d) {
    if(k > n || d == -1) return 0;
    long long ans = 0;
    for(int t = 0; t <= d; t++) {
        f[0] = k;
        for(int j = 1; j <= t; j++) f[j] = f[j - 1] >> 1;
        f[t + 1] = f[t] / 3;
        for(int j = t + 1; j <= d; j++) f[j + 1] = f[j] >> 1;
        for(int i = 0; i <= d + 1; i++) num[i] = n / f[i];
        for(int i = 0; i <= d + 1; i++)
            memset(dp[i] + 1, 0, sizeof(int[num[i]]));
        dp[0][1] = 1;
        for(int i = 0; i <= d; i++)
            for(int j = 1, val = num[i]; j <= val; j++) if(dp[i][j]) {
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j] * LL(val - j)) % mod;
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * LL(num[i + 1] - val)) % mod;
            }
        for(int j = 1; j <= n; j++) if(dp[d + 1][j])
            dp[d + 1][j + 1] = (dp[d + 1][j + 1] + dp[d + 1][j] * LL(n - j)) % mod;
        ans += dp[d + 1][n];
    }
    return ans % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(pw2 = 1; pw2 <= n; pw2 <<= 1, ++d);
    pw2 >>= 1, --d;
    cout << (solve1(pw2, d) + solve2(pw2 / 2 * 3, d - 1)) % mod;
    return 0;
}
