#include<bits/stdc++.h>
using namespace std;

namespace Polynomial_NTT {
    using LL = long long;
    constexpr int g = 3, P = 998244353;
    constexpr int MXLEN = 1 << 18;
    constexpr long long inv2 = (P + 1) >> 1;

    class poly_t : public vector<int> {
        public:
            poly_t() {}
            poly_t(initializer_list<int> list) {
                for(const int &val : list) push_back(val);
            }
            poly_t(const poly_t &A, int size) {*this = A, resize(size);}
    };

    inline int modAdd(int u, int v) {return (((u += v) >= P) && (u -= P)), u;}
    int getInv(int u) {
        return u == 1 ? 1 : static_cast<LL>(P - P / u) * getInv(P % u) % P;
    }
    int Pow(int u, int v) {
        int ans = 1;
        for(; v; v >>= 1, u = static_cast<LL>(u) * u % P)
            if(v & 1) ans = static_cast<LL>(u) * ans % P;
        return ans;
    }

    enum DFT_FLAG_t {NORMAL = 1, INVERSE = -1};
    void DFT(poly_t &A, int n, DFT_FLAG_t flag = NORMAL) {
        static int prevLen, rev[MXLEN + 1];
        if(prevLen != n) {
            prevLen = n;
            for(int i = 0; i < n; i++)
                rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (n >> 1));
        }
        if(static_cast<int>(A.size()) != n) A.resize(n);

        for(int i = 0; i < n; i++)
            if(i < rev[i]) swap(A[i], A[rev[i]]);
        for(int i = 1; i < n; i <<= 1) {
            LL wn = Pow(g, P - 1 + flag * (P - 1) / (i << 1));
            for(int j = 0; j < n; j += i << 1)
                for(int k = 0, w = 1; k < i; k++, w = wn * w % P) {
                    int x0 = A[j + k], x1 = static_cast<LL>(w) * A[i + j + k] % P;
                    A[j + k] = modAdd(x0, x1);
                    A[i + j + k] = modAdd(x0, P - x1);
                }
        }
        if(flag == INVERSE) {
            LL tmp = getInv(n);
            for(int &val : A)
                val = tmp * val % P;
        }
    }

    poly_t multiply(poly_t &A, poly_t &B) {
        static poly_t C;
        int X = 1, n = A.size(), m = B.size();
        for(; X < n + m - 1; X <<= 1);
        C.resize(X);
        DFT(A, X, NORMAL), DFT(B, X, NORMAL);
        for(int i = 0; i < X; i++)
            C[i] = static_cast<LL>(A[i]) * B[i] % P;
        DFT(C, X, INVERSE), C.resize(n + m - 1);
        return C;
    }
    poly_t getInverse(const poly_t &A, int n) {
        if(n == 1)
            return {getInv(A[0])};
        poly_t B = getInverse(A, (n + 1) >> 1);
        poly_t T = poly_t(A, n);
        int X = 1;
        for(int mxlen = (n << 1) - 1; X < mxlen; X <<= 1);
        DFT(B, X, NORMAL), DFT(T, X, NORMAL);
        for(int i = 0; i < X; i++)
            B[i] = (2LL * B[i] + static_cast<LL>(P - T[i]) * B[i] % P * B[i]) % P;
        DFT(B, X, INVERSE), B.resize(n);
        return B;
    }
    poly_t getDerivative(const poly_t &A) {
        int n = A.size();
        poly_t ans;
        ans.resize(n - 1);
        for(int i = 1; i < n; i++)
            ans[i - 1] = static_cast<LL>(i) * A[i] % P;
        return ans;
    }
    poly_t getIntegral(const poly_t &A, int n) {
        static int prevLen = 1, inv[MXLEN + 1] = {0, 1};
        if(n > prevLen) {
            for(int i = prevLen + 1; i <= n; i++)
                inv[i] = static_cast<LL>(P - P / i) * inv[P % i] % P;
            prevLen = n;
        }
        poly_t ans;
        ans.resize(n);
        for(int i = 1; i < n; i++)
            ans[i] = static_cast<LL>(A[i - 1]) * inv[i] % P;
        return ans;
    }
    poly_t getLogarithm(const poly_t &A, int n) {
        poly_t F = A;
        poly_t dF = getDerivative(F);
        F = getInverse(F, n);
        int X = 1;
        for(int mxlen = (n << 1) - 1; X < mxlen; X <<= 1);
        DFT(F, X, NORMAL), DFT(dF, X, NORMAL);
        for(int i = 0; i < X; i++)
            F[i] = static_cast<LL>(F[i]) * dF[i] % P;
        DFT(F, X, INVERSE);
        return getIntegral(F, n);
    }
    poly_t getExponential(const poly_t &A, int n) {
        if(n == 1)
            return {1};
        poly_t F = getExponential(A, (n + 1) >> 1);
        poly_t B = poly_t(A, n);
        F.resize(n);
        poly_t lnF = getLogarithm(F, n);
        for(int i = 0; i < n; i++)
            B[i] = modAdd(B[i], P - lnF[i]);
        int X = 1;
        for(int mxlen = (n << 1) - 1; X < mxlen; X <<= 1);
        DFT(F, X, NORMAL), DFT(B, X, NORMAL);
        for(int i = 0; i < X; i++)
            B[i] = F[i] * (1LL + B[i]) % P;
        DFT(B, X, INVERSE), B.resize(n);
        return B;
    }
    poly_t getSqrt(const poly_t &A, int n) {
        if(n == 1)
            return {1};
        poly_t F = getSqrt(A, (n + 1) >> 1);
        poly_t B = poly_t(A, n);
        F.resize(n);
        poly_t invF = getInverse(F, n);
        int X = 1;
        for(int mxlen = (n << 1) - 1; X < mxlen; X <<= 1);
        DFT(B, X, NORMAL), DFT(invF, X, NORMAL);
        for(int i = 0; i < X; i++)
            B[i] = static_cast<LL>(B[i]) * invF[i] % P;
        DFT(B, X, INVERSE), B.resize(n);
        for(int i = 0; i < n; i++)
            B[i] = modAdd(B[i], F[i]) * inv2 % P;
        return B;
    }
}

#define ENDL "\n"
using LL = long long;
const int mod = 998244353;
const LL inv2 = (mod + 1) >> 1;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    int n, m, mxlen = 100001;
    cin >> n >> m;

    Polynomial_NTT::poly_t C;
    C.resize(mxlen);
    for(int i = 1, val; i <= n; i++) {
        cin >> val;
        C[val] = mod - 4;
    }
    C[0]++;
    C = Polynomial_NTT::getSqrt(C, mxlen);
    C[0]++;
    C = Polynomial_NTT::getInverse(C, mxlen);
    
    for(int i = 1; i <= m; i++)
        cout << C[i] * 2 % mod << ENDL;
    return 0;
}
