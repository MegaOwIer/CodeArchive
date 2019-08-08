#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int mod = 1000000007, inv2 = (mod + 1) >> 1;
const int MX = 200005;

int frac[MX], ifr[MX];

int getInv(int u) {return u == 1 ? 1 : LL(mod - mod / u) * getInv(mod % u) % mod;}

int C(int n, int m) {
    if(n < m) return 0;
    return (LL)frac[n] * ifr[m] % mod * ifr[n - m] % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int n, ans = 0, pow2 = 1, B = 1, cnt;
    LL T, S = 0;
    cin >> n >> T;

    frac[0] = 1;
    for(int i = 1; i <= n; i++) frac[i] = (LL) frac[i - 1] * i % mod;
    ifr[n] = getInv(frac[n]);
    for(int i = n; i >= 1; i--) ifr[i - 1] = (LL)ifr[i] * i % mod;

    int X = n;
    for(int i = 1, val; i <= n; i++) {
        cin >> val;
        S += val;
        if(S > T) break;
        pow2 = (LL)pow2 * inv2 % mod;
        B = (2LL * B - C(i - 1, X) + mod) % mod;
        int Y = min<LL>(n, T - S);
        while(X > Y) {
            B = (B + mod - C(i, X)) % mod;
            X--;
        }
        ans = (ans + (LL)B * pow2 % mod) % mod;
    }
    cout << ans << "\n";
    return 0;
}
