#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int mod = 1000000007, MX = 51;

int n, T, dp[MX][MX][MX][3], frac[MX], a[MX], type[MX], num[3], usd[3];
vector<int> cnt[MX][MX][MX];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin >> n >> T;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> type[i];
        ++num[--type[i]];
    }

    frac[0] = 1;
    for(int i = 1; i <= n; i++) frac[i] = (LL)frac[i - 1] * i % mod;

    dp[1][0][0][0] = dp[0][1][0][1] = dp[0][0][1][2] = 1;
    for(int i = 0; i <= num[0]; i++)
        for(int j = 0; j <= num[1] && i + j < n; j++)
            for(int k = 0; k <= num[2] && i + j + k < n; k++)
                for(int t = 0; t < 3; t++) if(dp[i][j][k][t]) {
                    if(t != 0)
                        (dp[i + 1][j][k][0] += dp[i][j][k][t]) %= mod;
                    if(t != 1)
                        (dp[i][j + 1][k][1] += dp[i][j][k][t]) %= mod;
                    if(t != 2)
                        (dp[i][j][k + 1][2] += dp[i][j][k][t]) %= mod;
                }

    for(int i = 0; i <= num[0]; i++)
        for(int j = 0; j <= num[1] && i + j <= n; j++)
            for(int k = 0; k <= num[2] && i + j + k <= n; k++)
                cnt[i][j][k].resize(T + 1);
    cnt[0][0][0][0] = 1;
    for(int cur = 1; cur <= n; cur++) {
        int f = type[cur];
        for(int i = usd[0]; i >= 0; i--)
            for(int j = usd[1]; j >= 0; j--) if(i + j < cur)
                for(int k = usd[2]; k >= 0; k--) if(i + j + k < cur)
                    for(int pr = 0; pr + a[cur] <= T; pr++)
                            (cnt[i + (f == 0)][j + (f == 1)][k + (f == 2)][pr + a[cur]] += cnt[i][j][k][pr]) %= mod;
        ++usd[f];
    }

    int ans = 0;
    for(int i = 0; i <= num[0]; i++)
        for(int j = 0; j <= num[1] && i + j <= n; j++)
            for(int k = 0; k <= num[2] && i + j + k <= n; k++) if(cnt[i][j][k][T]) {
                LL tmp = ((LL)dp[i][j][k][0] + dp[i][j][k][1] + dp[i][j][k][2]) * frac[i] % mod * frac[j] % mod * frac[k] % mod;
                ans = (ans + cnt[i][j][k][T] * tmp) % mod;
            }
    cout << ans << "\n";
    return 0;
}
