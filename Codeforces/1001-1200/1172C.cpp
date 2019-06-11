#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MN = 200005, MM = 3005, mod = 998244353;

int n, m, a[MN], w[MN], dp[MM];
int qwq[MM << 1], *Inv = qwq + MM;

int read() {
    int x = 0, c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c))
        x = x * 10 + c - 48, c = getchar();
    return x;
}

int inv(int u) {return u == 1 ? 1 : LL(mod - mod / u) * inv(mod % u) % mod;}

int main() {
    n = read(), m = read();
    int S = 0, T = 0;
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1; i <= n; i++) {
        w[i] = read();
        if(a[i] == 1) T += w[i];
        else S += w[i];
    }
    for(int i = max(-m, 1 - S - T); i <= m; i++) Inv[i] = inv(S + T + i);
    dp[0] = 1;
    for(int i = 0; i < m; i++) {
        for(int j = i; j >= 0 && S - i + j >= 0; j--) {
            int invsum = Inv[j * 2 - i];
            dp[j + 1] = (dp[j + 1] + LL(T + j) * invsum % mod * dp[j]) % mod;
            dp[j] = LL(S - i + j) * invsum % mod * dp[j] % mod;
        }
    }
    int inc = dp[0], dec = dp[m];
    for(int i = 1, tmp = 1; i <= m; i++) {
        tmp = LL(1 + inv(T + i - 1)) * tmp % mod;
        inc = (inc + (LL)tmp * dp[i]) % mod;
    }
    for(int i = 1, tmp = 1; i <= m && i <= S; i++) {
        tmp = LL(1 - inv(S - i + 1) + mod) * tmp % mod;
        dec = (dec + (LL)tmp * dp[m - i]) % mod;
    }
    for(int i = 1; i <= n; i++)
        printf("%d\n", int(w[i] * LL(a[i] == 1 ? inc : dec) % mod));
    return 0;
}
