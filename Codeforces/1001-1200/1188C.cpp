#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 1005, mod = 998244353;

int n, k, a[MX], dp[MX][MX], ans;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    a[0] = -100000;
    for(int i = 1; i <= n; i++) dp[i][1] = i;
    for(int D = 1; D * (k - 1) <= a[n] - a[1]; D++) {
        for(int l = 2; l <= k; l++) {
            for(int i = 1, j = 0; i <= n; i++) {
                while(a[j + 1] + D <= a[i]) ++j;
                dp[i][l] = (dp[i - 1][l] + dp[j][l - 1]) % mod;
            }
        }
        ans = (ans + dp[n][k]) % mod;
    }
    cout << ans << "\n";
    return 0;
}
