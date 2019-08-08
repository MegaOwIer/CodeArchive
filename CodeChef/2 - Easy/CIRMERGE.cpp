#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 803;

long long a[MX], dp[MX][MX];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        memcpy(a + n + 1, a + 1, sizeof(LL[n]));
        int m = n * 2;
        for(int i = 1; i <= m; i++) dp[i][i] = 0;
        for(int i = 1; i <= m; i++) a[i] += a[i - 1];
        for(int i = 2; i <= n; i++) {
            for(int l = 1, r = i; r <= m; l++, r++) {
                long long &cur = dp[l][r];
                cur = LLONG_MAX;
                for(int k = l; k < r; k++)
                    cur = min(cur, dp[l][k] + dp[k + 1][r]);
                cur += a[r] - a[l - 1];
            }
        }
        long long ans = LLONG_MAX;
        for(int l = 1, r = n; r <= m; l++, r++)
            ans = min(ans, dp[l][r]);
        cout << ans << "\n";
    }
    return 0;
}
