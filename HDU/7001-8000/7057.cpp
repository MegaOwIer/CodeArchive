#include <bits/stdc++.h>
using namespace std;

namespace Polynomial_NTT {

using LL = long long;
constexpr int g = 3, P = 998244353;
constexpr int MXLEN = 1 << 16;
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

using poly_t = vector<int>;
const int mod = Polynomial_NTT::P;
const int MX = Polynomial_NTT::MXLEN;

poly_t operator+ (poly_t a, poly_t b) {
    if(a.size() < b.size()) {
        swap(a, b);
    }
    for(size_t i = 0; i < b.size(); i++) {
        a[i] = (a[i] + b[i]) % mod;
    }
    return a;
}

poly_t operator* (poly_t a, poly_t b) {
    static int res[MX];
    Polynomial_NTT::multiply(res, a.data(), a.size(), b.data(), b.size());
    return poly_t(res, res + (a.size() + b.size() - 1));
}

struct Matrix {
    poly_t a[2][2];

    poly_t *operator[] (int u) { return a[u]; }

    void normalize(int m) {
        for(int i : {0, 1}) {
            for(int j : {0, 1}) {
                if(a[i][j].size() > m) {
                    a[i][j].resize(m);
                }
            }
        }
    }

    Matrix operator* (Matrix u) {
        Matrix ans;
        ans[0][0] = a[0][0] * u[0][0] + a[0][1] * u[1][0];
        ans[0][1] = a[0][0] * u[0][1] + a[0][1] * u[1][1];
        ans[1][0] = a[1][0] * u[0][0] + a[1][1] * u[1][0];
        ans[1][1] = a[1][0] * u[0][1] + a[1][1] * u[1][1];
        return ans;
    }
};

Matrix Pow(Matrix a, int b, int m) {
    Matrix ans;
    ans[0][0] = ans[1][1] = {1};
    ans[0][1] = ans[1][0] = {0};
    for(; b; b >>= 1) {
        if(b & 1) {
            ans = ans * a;
            ans.normalize(m + 1);
        }
        a = a * a;
        a.normalize(m + 1);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;

        Matrix res;
        res[0][0] = {1, 1, 1};
        res[0][1] = {0, 1, 2, 1};
        res[1][0] = {1};
        res[1][1] = {0};

        res = Pow(res, n - 1, m);

        poly_t f1 {1, 1, 1};

        poly_t ans = f1 * res[0][0] + res[0][1];
        ans.resize(m + 1);
        for(int i = 1; i <= m; i++) {
            cout << ans[i] << ' ';
        }
        cout << "\n";
    }
    return 0;
}
