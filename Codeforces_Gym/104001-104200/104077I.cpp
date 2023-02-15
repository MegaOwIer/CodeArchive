/**
 * @date 2023-02-07
 * @author MegaOwIer (megaowier@gmail.com)
 * @brief counting.
 */

#include <bits/stdc++.h>
using namespace std;

namespace Polynomial_NTT {

using int_t = int;
using long_t = long long;

// make sure 2*P will not cause signed overflow
constexpr int_t g = 3, P = 998244353;
constexpr int_t MXLEN = 1 << 19;
constexpr int_t inv2 = (P + 1) >> 1;
using array = int_t[MXLEN + 1];

inline size_t getLength(int_t val) {
    val |= val >> 1;    val |= val >> 2;
    val |= val >> 4;    val |= val >> 8;
    val |= val >> 16;
    return val + 1;
}

int_t Pow(long_t u, int_t v) {
    long_t ans = 1;
    for(; v; v >>= 1, u = u * u % P)
        if(v & 1) ans = u * ans % P;
    return (int_t)ans;
}

int_t getInv(int_t u) { return Pow(u, P - 2); }

void DFT(int_t *A, const size_t n, const int_t flag) {
    static size_t rev[MXLEN + 1], preN;
    if(preN != n) {
        for(size_t i = 0; i < n; i++) {
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (n >> 1));
        }
        preN = n;
    }
    for(size_t i = 0; i < n; i++)
        if(i < rev[i]) swap(A[i], A[rev[i]]);
    for(size_t i = 1, r = 1; i < n; i *= 2, r++) {
        long_t wn = Pow(g, P - 1 + flag * ((P - 1) >> r));
        for(size_t j = 0; j < n; j += i * 2) {
            long_t w = 1;
            for(size_t k = j; k < j + i; k++) {
                int_t x0 = A[k], x1 = int_t(w * A[i + k] % P);
                A[k] = (x0 + x1) % P;
                A[i + k] = (x0 + P - x1) % P;
                w = wn * w % P;
            }
        }
    }
    if(flag == -1) {
        long_t tmp = getInv(n);
        for(size_t i = 0; i < n; i++) A[i] = int_t(A[i] * tmp % P);
    }
}

void multiply(int_t *res, const int_t *A, const size_t n, const int_t *B, const size_t m) {
    static array _A, _B;
    size_t X = getLength(n + m - 2);
    memcpy(_A, A, sizeof(int_t[n])), memset(_A + n, 0, sizeof(int_t[X - n]));
    memcpy(_B, B, sizeof(int_t[m])), memset(_B + m, 0, sizeof(int_t[X - m]));
    DFT(_A, X, 1), DFT(_B, X, 1);
    for(size_t i = 0; i < X; i++) res[i] = int_t((long_t)_A[i] * _B[i] % P);
    DFT(res, X, -1);
}

} // namespace Polynomial_NTT

using LL = long long;

const int MX = Polynomial_NTT::MXLEN;
const int mod = Polynomial_NTT::P;

// ans = a^b mod (x^n - 1)
void Pow(int *ans, int *a, int b, int n) {
    int n_ans = 1, n_a = 2;
    while(b) {
        if(b & 1) {
            Polynomial_NTT::multiply(ans, ans, n_ans, a, n_a);
            for(int i = n_ans + n_a - 2; i >= n; i--) {
                ans[i - n] = (ans[i - n] + ans[i]) % mod;
                ans[i] = 0;
            }
            n_ans = min(n_ans + n_a - 1, n);
        }

        Polynomial_NTT::multiply(a, a, n_a, a, n_a);
        for(int i = n_a + n_a - 2; i >= n; i--) {
            a[i - n] = (a[i - n] + a[i]) % mod;
            a[i] = 0;
        }
        n_a = min(n_a + n_a - 1, n);

        b >>= 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t, q;
    cin >> n >> t >> q;
    n = 2 * (n + 2);

    static int C[MX], P[MX];
    C[0] = 1;
    P[0] = P[1] = 1;
    Pow(C, P, t, n);

    function<LL(int, int)> calc = [&] (int x, int y) {
        int dx = x + y, dy = x - y;
        dx = ((dx + t) / 2 % n + n) % n;
        dy = ((dy + t) / 2 % n + n) % n;
        return (LL)C[dx] * C[dy];
    };

    while(q--) {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        ++x0, ++y0, ++x1, ++y1;

        if((x0 ^ y0 ^ x1 ^ y1 ^ t) & 1) {
            cout << 0 << "\n";
            continue;
        }
        
        LL ans = 0;
        ans += calc(x1 - x0, y1 - y0);
        ans += calc(x1 - x0, y1 - y0 + n);

        ans += calc(-x1 - x0, -y1 - y0);
        ans += calc(-x1 - x0, -y1 - y0 + n);
        
        ans -= calc(-x1 - x0, y1 - y0);
        ans -= calc(-x1 - x0, y1 - y0 + n);
        
        ans -= calc(x1 - x0, -y1 - y0);
        ans -= calc(x1 - x0, -y1 - y0 + n);

        cout << (ans % mod + mod) % mod << "\n";
    }
    return 0;
}
