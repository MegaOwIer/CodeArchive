#include <bits/stdc++.h>
using namespace std;

using LL = long long;

constexpr int MX = 200005, mod = 998244353;

int fac[MX], ifa[MX];
int h[MX];

constexpr int getInv(int u) {return u == 1 ? 1 : LL(mod - mod / u) * getInv(mod % u) % mod;}
int C(int n, int m) {return (LL)fac[n] * ifa[m] % mod * ifa[n - m] % mod;}

int Pow(int a, int b) {
    int ans = 1;
    for(; b; b >>= 1, a = (LL)a * a % mod)
        if(b & 1) ans = (LL)ans * a % mod;
    return ans;
}

int getSum(int u) {
    static constexpr int inv2 = getInv(2);
    if(u & 1) return Pow(2, u - 1);
    return LL(Pow(2, u) - C(u, u >> 1) + mod) * inv2 % mod;
}

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    
    fac[0] = 1;
    for(int i = 1; i <= n; i++) fac[i] = (LL)fac[i - 1] * i % mod;
    ifa[n] = getInv(fac[n]);
    for(int i = n; i; i--) ifa[i - 1] = (LL)ifa[i] * i % mod;

    for(int i = 1; i <= n; i++) cin >> h[i];
    int same = 0, diff = 0;
    for(int i = 1; i <= n; i++)
        (h[i] == h[i % n + 1] ? same : diff)++;
    int ans = 0;
    for(int i = 1; i <= diff; i++) {
        ans = (ans + (LL)getSum(i) * C(diff, i) % mod * Pow(k - 2, diff - i)) % mod;
    }
    cout << (LL)ans * Pow(k, same) % mod << "\n";
    return 0;
}
