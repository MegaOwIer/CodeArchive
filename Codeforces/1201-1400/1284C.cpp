#include<bits/stdc++.h>
using namespace std;

using LL = long long;
constexpr int MX = 250000;

int frac[MX + 5];

int main() {
    ios::sync_with_stdio(false);
    int n, mod, ans = 0;
    cin >> n >> mod;
    frac[0] = 1;
    for(int i = 1; i <= n; i++) frac[i] = frac[i - 1] * (LL)i % mod;
    for(int i = 1; i <= n; i++) {
        ans = (ans + LL(n - i + 1) * frac[i] % mod * frac[n - i + 1]) % mod;
    }
    cout << ans << "\n";
    return 0;
}
