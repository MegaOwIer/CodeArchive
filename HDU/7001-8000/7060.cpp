#include <bits/stdc++.h>
using namespace std;

namespace Polynomial_NTT {

using LL = long long;
constexpr int g = 3, P = 998244353;
constexpr int MXLEN = 1 << 21;
constexpr int inv2 = (P + 1) >> 1;
using array = int[MXLEN + 1];

inline int getLength(int val) {
    val |= val >> 1;
    val |= val >> 2;
    val |= val >> 4;
    val |= val >> 8;
    val |= val >> 16;
    return val + 1;
}

int getInv(int u) {return u == 1 ? 1 : int(LL(P - P / u) * getInv(P % u) % P);}

int Pow(int u, int v) {
    int ans = 1;
    for(; v; v >>= 1, u = int((LL)u * u % P))
        if(v & 1) ans = int((LL)u * ans % P);
    return ans;
}

void DFT(int *A, const int n, const int flag) {
    static int rev[MXLEN + 1], preN;
    if(preN != n) {
        for(int i = 0; i < n; i++) {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (n >> 1));
        }
        preN = n;
    }
    for(int i = 0; i < n; i++)
        if(i < rev[i]) swap(A[i], A[rev[i]]);
    for(int i = 1; i < n; i <<= 1) {
        LL wn = Pow(g, P - 1 + flag * (P - 1) / (i << 1));
        for(int j = 0; j < n; j += i << 1)
            for(int k = 0, w = 1; k < i; k++, w = int(wn * w % P)) {
                int x0 = A[j + k], x1 = int((LL)w * A[i + j + k] % P);
                A[j + k] = (x0 + x1) % P;
                A[i + j + k] = (x0 + P - x1) % P;
            }
    }
    if(flag == -1) {
        int tmp = getInv(n);
        for(int i = 0; i < n; i++) A[i] = int((LL)A[i] * tmp % P);
    }
}

void multiply(int *res, const int *A, const int n, const int *B, const int m) {
    static array _A, _B;
    int X = getLength(n + m - 2);
    memcpy(_A, A, sizeof(int[n])), memset(_A + n, 0, sizeof(int[X - n]));
    memcpy(_B, B, sizeof(int[m])), memset(_B + m, 0, sizeof(int[X - m]));
    DFT(_A, X, 1), DFT(_B, X, 1);
    for(int i = 0; i < X; i++) res[i] = int((LL)_A[i] * _B[i] % P);
    DFT(res, X, -1);
}

} // namespace Polynomial_NTT
using Polynomial_NTT::MXLEN;
using Polynomial_NTT::Pow;

using LL = long long;
const int MX = 1000000;
const int mod = Polynomial_NTT::P;

char s[MX + 5];
int fac[MX + 1], inv[MX + 1];
int pw10[MX + 1];

int F[MXLEN], A[MXLEN], B[MXLEN], C[MXLEN];

void work() {
    int n, k;
    cin >> k >> (s + 1);
    n = strlen(s + 1);

    if(k == 1) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = (ans * 10LL + s[i] - '0') % mod;
        }
        cout << ans << "\n";
        return;
    }

    reverse(s + 1, s + n + 1);
    F[n] = 0;
    for(int i = n; i >= 1; i--) {
        F[i - 1] = F[i] + s[i] - '0';
    }
    for(int i = 1; i <= n; i++) {
        F[i] = (LL)F[i] * pw10[i - 1] % mod;
    }

    for(int t = 0; t < k - 1; t++) A[t] = inv[t];
    for(int t = 0; t < n; t++) B[t] = inv[t];
    Polynomial_NTT::multiply(C, A, k - 1, B, n);

    for(int j = 1; j < n; j++) {
        F[j] = (LL)F[j] * C[n - 1 - j] % mod;
    }

    int ans = 0;
    for(int j = 1; j <= n; j++) {
        ans = (ans + (LL)F[j] * fac[n - 1 - j]) % mod;
    }

    for(int i = 0, j = k - 1; j < n; i++, j++) {
        C[j] = (C[j] + (LL)inv[k - 1] * inv[i]) % mod;
    }

    for(int i = 1; i <= n; i++) {
        int tmp = (LL)(s[i] - '0') * pw10[i - 1] % mod * fac[n - i] % mod;
        ans = (ans + (LL)tmp * C[n - i]) % mod;
    }

    cout << ans << "\n";
}

int main() {
    fac[0] = 1;
    for(int i = 1; i <= MX; i++) fac[i] = (LL)fac[i - 1] * i % mod;
    inv[MX] = Pow(fac[MX], mod - 2);
    for(int i = MX; i; i--) inv[i - 1] = (LL)inv[i] * i % mod;

    pw10[0] = 1;
    for(int i = 1; i <= MX; i++) pw10[i] = 10LL * pw10[i - 1] % mod;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        work();
    }

    return 0;
}
/*
2
2
1111
3
100

*/