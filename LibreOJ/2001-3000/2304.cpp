#include <bits/stdc++.h>
using namespace std;

using LL = long long;

constexpr int mod = 1000000007, MX = 1000000;

int fac[MX + 5], ifa[MX + 5], g[MX + 5];

int getInv(int u) {return u == 1 ? 1 : LL(mod - mod / u) * getInv(mod % u) % mod;}

int C(int n, int m) {return (LL)fac[n] * ifa[m] % mod * ifa[n - m] % mod;}

int main() {
    fac[0] = 1;
    for(int i = 1; i <= MX; i++) fac[i] = (LL)fac[i - 1] * i % mod;
    ifa[MX] = getInv(fac[MX]);
    for(int i = MX; i; i--) ifa[i - 1] = (LL)ifa[i] * i % mod;

    g[0] = 1;
    for(int i = 1; i <= MX; i++)
        g[i] = ((LL)g[i - 1] * i + (i & 1 ? -1 : 1)) % mod;

    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        cout << (LL)g[n - m] * C(n, m) % mod << "\n";
    }
    return 0;
}
