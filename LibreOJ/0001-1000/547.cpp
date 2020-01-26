#include <bits/stdc++.h>
using namespace std;

using LL = long long;

constexpr int mod = 65537, B = 4000;

int pw2[mod];

namespace Polynomial_NTT {
    using LL = long long;
    constexpr int g = 3, P = 65537;
    constexpr int MXLEN = 1 << 16;
    constexpr int inv2 = (P + 1) >> 1;
    using array = int[MXLEN + 1];
    
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
            preN = n;
            for(int i = 0; i < n; i++)
                rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (n >> 1));
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
        int X = 1;
        for(; X < n + m - 1; X <<= 1);
        memcpy(_A, A, sizeof(int[n])), memset(_A + n, 0, sizeof(int[X - n]));
        memcpy(_B, B, sizeof(int[m])), memset(_B + m, 0, sizeof(int[X - m]));
        DFT(_A, X, 1), DFT(_B, X, 1);
        for(int i = 0; i < X; i++) res[i] = int((LL)_A[i] * _B[i] % P);
        DFT(res, X, -1);
    }

    void getInverse(int *res, const int *A, const int n) {
        if(n == 1) {
            res[0] = getInv(A[0]);
            return;
        }
        int X = 1, half = (n + 1) >> 1;
        for(int mxlen = n + n - 1; X < mxlen; X <<= 1);
        static array T;
        getInverse(res, A, half), memset(res + half, 0, sizeof(int[X - half]));
        memcpy(T, A, sizeof(int[n])), memset(T + n, 0, sizeof(int[X - n]));
        DFT(res, X, 1), DFT(T, X, 1);
        for(int i = 0; i < X; i++)
            res[i] = int((2LL * res[i] + LL(P - T[i]) * res[i] % P * res[i]) % P);
        DFT(res, X, -1);
    }

    void doDivision(int *q, int *r, const int *A, const int n, const int *B, const int m) {
        static array _r, _q, _A, _B;
        if(q == nullptr) q = _q;
        if(r == nullptr) r = _r;
        for(int i = 1; i <= n; i++) _A[n - i] = A[i - 1];
        for(int i = 1; i <= m; i++) _B[m - i] = B[i - 1];
        int lres = n - m + 1;
        for(int i = m; i < lres; i++) _B[i] = 0;
        getInverse(_r, _B, lres);
        multiply(q, _A, lres, _r, lres);
        reverse(q, q + lres);
        multiply(_A, q, lres, B, m);
        for(int i = 0; i < n; i++) r[i] = (A[i] - _A[i] + P) % P;
    }
} // namespace Polynomial_NTT

namespace Linear_Recursion {
    using LL = long long;

    constexpr int MXLEN = Polynomial_NTT::MXLEN;

    void update(int *res, const int *cur, const int *p, int n) {
        using Polynomial_NTT::multiply;
        using Polynomial_NTT::doDivision;
        static int tmp[MXLEN];
        multiply(tmp, res, n, cur, n);
        doDivision(nullptr, res, tmp, n + n - 1, p, n);
    }

    void Pow(int *res, LL b, const int *p, const int n) {
        static int cur[MXLEN];
        memset(cur, 0, sizeof(int[n]));
        cur[0] = 1;
        while(b) {
            if(b & 1) update(cur, res, p, n);
            update(res, res, p, n);
            b >>= 1;
        }
        memcpy(res, cur, sizeof(int[n]));
    }

    int solve(const int *p, const int len, const int *x, LL index) {
        static int res[MXLEN];
        memset(res, 0, sizeof(int[len]));
        res[1] = 1;
        Pow(res, index, p, len);
        int ans = 0;
        for(int i = 0; i < len; i++) {
            ans = (ans + (LL)x[i] * res[i]) % mod;
        }
        return ans;
    }
} // namespace Linear_Recursion


namespace Solve1 {

constexpr int MLEN = B + 5;

using Linear_Recursion::solve;

void work(LL n, int m) {
    static int poly[MLEN];
    poly[0] = 1, poly[m] = mod - 2, poly[m + 1] = 1;
    cout << (solve(poly, m + 2, pw2, n + 1) - solve(poly, m + 2, pw2, n) + mod) % mod << "\n";
}

} // namespace Solve1

namespace Solve2 {
    int fac[mod], ifa[mod];

    int getInv(int u) {return u == 1 ? 1 : LL(mod - mod / u) * getInv(mod % u) % mod;}

    int C(LL n, LL m) {
        if(m > n) return 0;
        if(n < mod) return (LL)fac[n] * ifa[m] % mod * ifa[n - m] % mod;
        return (LL)C(n / mod, m / mod) * C(n % mod, m % mod) % mod;
    }

    int calc(LL n, LL m) {
        LL ans = 0;
        for(int i = 0; i * (m + 1) <= n; i++) {
            LL cur = C(n - i * m, i) * pw2[(n - i * (m + 1)) & (mod - 2)];
            ans += (i & 1 ? -cur : cur);
        }
        return (ans % mod + mod) % mod;
    }

    void work(LL n, LL m) {
        fac[0] = 1;
        for(int i = 1; i < mod; i++) fac[i] = (LL)fac[i - 1] * i % mod;
        ifa[mod - 1] = getInv(fac[mod - 1]);
        for(int i = mod - 1; i; i--) ifa[i - 1] = (LL)ifa[i] * i % mod;
        cout << (calc(n + 1, m) - calc(n, m) + mod) % mod;
    }
} // namespace Solve2

int main() {
    pw2[0] = 1;
    for(int i = 1; i < mod; i++) pw2[i] = pw2[i - 1] * 2 % mod;

    ios::sync_with_stdio(false);
    LL n, m;
    cin >> n >> m;
    if(m <= B) Solve1::work(n, m);
    else Solve2::work(n, m);
    return 0;
}
