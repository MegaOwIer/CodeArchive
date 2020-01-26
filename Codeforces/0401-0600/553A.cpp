#include <bits/stdc++.h>
using namespace std;

using LL = long long;

constexpr int mod = 1000000007, MX = 2000;

int fac[MX + 5], ifa[MX + 5];

int getInv(int u) {return u == 1 ? 1 : LL(mod - mod / u) * getInv(mod % u) % mod;}

int C(int n, int m) {return (LL)fac[n] * ifa[m] % mod * ifa[n - m] % mod;}

int main() {
    fac[0] = 1;
    for(int i = 1; i <= MX; i++) fac[i] = (LL)fac[i - 1] * i % mod;
    ifa[MX] = getInv(fac[MX]);
    for(int i = MX; i; i--) ifa[i - 1] = (LL)ifa[i] * i % mod;
    
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = 1, sum = 0;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        ans = (LL)ans * C(val + sum - 1, sum) % mod;
        sum += val;
    }
    cout << ans << "\n";
    return 0;
}
