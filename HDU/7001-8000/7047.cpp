#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int mod = 1000000007;
const int MX = 2000000;

int frac[MX + 5], inv[MX + 5];

int getInv(int u) {
    return u == 1 ? 1 : LL(mod - mod / u) * getInv(mod % u) % mod;
}

int C(int n, int m) {
    return (LL)frac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {
    frac[0] = 1;
    for(int i = 1; i <= MX; i++) frac[i] = (LL)frac[i - 1] * i % mod;
    inv[MX] = getInv(frac[MX]);
    for(int i = MX; i; i--) inv[i - 1] = (LL)inv[i] * i % mod;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        int ans = C(n + m, m);
        if(m >= n + 1) {
            int r = m - n - 1;
            ans = (ans + mod - C(n + r, r)) % mod;
        }
        cout << ans << "\n";
    }
    return 0;
}
