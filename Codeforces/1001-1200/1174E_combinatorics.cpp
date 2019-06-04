#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 1000005, mod = 1000000007;

int n, frac[MX], inv[MX], d[23], num[23];

int work1(int vp2) {
    for(int i = 0; i <= vp2; i++) d[i] = 1 << i;
    for(int i = 0; i <= vp2; i++) num[i] = n / d[i];
    for(int i = 0; i < vp2; i++) num[i] -= num[i + 1];
    LL ans = frac[n];
    for(int i = 0; i <= vp2; i++) ans = ans * num[i] % mod;
    for(int i = 0, l = 0; i <= vp2; i++)
        l += num[i], ans = ans * inv[l] % mod;
    return ans;
}

int work2(int k, int vp2) {
    if(k > n || vp2 < 0) return 0;
    LL ans = 0;
    for(int cas = 0; cas <= vp2; cas++) {
        for(int i = 0; i <= cas; i++) d[i] = 1 << i;
        d[cas + 1] = d[cas] * 3;
        for(int i = cas + 1; i <= vp2; i++) d[i + 1] = d[i] << 1;
        for(int i = 0; i <= vp2 + 1; i++) num[i] = n / d[i];
        for(int i = 0; i <= vp2; i++) num[i] -= num[i + 1];
        LL tmp = frac[n];
        for(int i = 0; i <= vp2 + 1; i++) tmp = tmp * num[i] % mod;
        for(int i = 0, l = 0; i <= vp2 + 1; i++)
            l += num[i], tmp = tmp * inv[l] % mod;
        ans += tmp;
    }
    return ans % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    frac[0] = 1;
    for(LL i = 1; i <= n; i++) frac[i] = frac[i - 1] * i % mod;
    inv[1] = 1;
    for(int i = 2; i <= n; i++) inv[i] = LL(mod - mod / i) * inv[mod % i] % mod;
    int pw2 = 1, d = 0;
    while(pw2 <= n) pw2 <<= 1, ++d;
    pw2 >>= 1, --d;
    cout << (work1(d) + work2(pw2 / 2 * 3, d - 1)) % mod << "\n";
    return 0;
}
