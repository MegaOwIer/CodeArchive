#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 2000000;
const int mod = 1000000007;

int fac[MX + 5], inv[MX + 5];

int Pow(int a, int b) {
    int ans = 1;
    for(; b; b >>= 1) {
        if(b & 1) ans = (LL)ans * a % mod;
        a = (LL)a * a % mod;
    }
    return ans;
}

int main() {
    fac[0] = 1;
    for(int i = 1; i <= MX; i++) fac[i] = (LL)fac[i - 1] * i % mod;
    inv[MX] = Pow(fac[MX], mod - 2);
    for(int i = MX; i; i--) inv[i - 1] = (LL)inv[i] * i % mod;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        if(n == 1 || m == 1) {
            cout << 2 << "\n";
        } else {
            cout << 4LL * fac[n + m - 2] * inv[n - 1] % mod * inv[m - 1] % mod << "\n";
        }
    }
    return 0;
}
