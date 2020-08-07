#include <bits/stdc++.h>
using namespace std;

namespace Polynomial_NTT {
    using LL = long long;
    constexpr int g = 3, P = 1004535809;
    constexpr int MXLEN = 1 << 18;
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
} // namespace Polynomial_NTT

using LL = long long;
const int MX = 1 << 18;
const int mod = 1004535809;

int fac[MX], ifa[MX];
int G[MX], H[MX], F[MX];

int Pow(int a, LL b) {
    int ans = 1;
    for(; b; a = (LL)a * a % mod, b >>= 1)
        if(b & 1) ans = (LL)ans * a % mod;
    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    fac[0] = 1;
    for(int i = 1; i <= n; i++) fac[i] = (LL)fac[i - 1] * i % mod;
    ifa[n] = Pow(fac[n], mod - 2);
    for(int i = n; i; i--) ifa[i - 1] = (LL)ifa[i] * i % mod;

    F[0] = 1;
    for(int i = 1; i <= n; i++) {
        int cur = Pow(2, i * LL(i - 1) / 2);
        G[i] = (LL)cur * ifa[i - 1] % mod;
        F[i] = (LL)cur * ifa[i] % mod;
    }

    Polynomial_NTT::getInverse(H, F, n + 1);
    Polynomial_NTT::multiply(F, G, n + 1, H, n + 1);

    printf("%lld\n", (LL)F[n] * fac[n - 1] % mod);
    return 0;
}
