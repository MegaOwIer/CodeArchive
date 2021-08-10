#include <bits/stdc++.h>
using namespace std;

namespace Polynomial_FFT {
    using LD = long double;
    using LL = long long;

    const int MXLEN = 1 << 18;
    const int mod = 998244352;
    const LD PI = acosl(-1.0);

    int Pow(int a, int b) {
        int ans = 1;
        for(; b; b >>= 1, a = (LL)a * a % mod)
            if(b & 1) ans = (LL)ans * a % mod;
        return ans;
    }

    struct complex {
        LD x, y;
        complex(LD x = 0.0l, LD y = 0.0l) : x(x), y(y) {}

        complex operator ~ () const {return complex(x, -y);}
        complex operator + (const complex &b) const {return complex(x + b.x, y + b.y);}
        complex operator - (const complex &b) const {return complex(x - b.x, y - b.y);}
        complex operator * (const complex &b) const {return complex(x * b.x - y * b.y, x * b.y + y * b.x);}
        complex operator / (const LD &b) const {return complex(x / b, y / b);}
        void operator /= (const LD &b) {x /= b, y /= b;}
    };

    void DFT(complex *A, int n, int flag = 1) {
        static int prevLen, rev[MXLEN + 1];
        if(prevLen != n) {
            prevLen = n;
            for(int i = 0; i < n; i++)
                rev[i] = (rev[i >> 1] >> 1) | ((i & 1) * (n >> 1));
        }
        for(int i = 0; i < n; i++)
            if(i < rev[i]) swap(A[i], A[rev[i]]);
        for(int i = 1; i < n; i <<= 1) {
            complex wn = complex(cosl(PI / i), sinl(PI / i) * flag);
            for(int j = 0; j < n; j += i << 1) {
                complex w = complex(1.0, 0.0);
                for(int k = 0; k < i; k++) {
                    complex x0 = A[j + k], x1 = w * A[i + j + k];
                    A[j + k] = x0 + x1;
                    A[i + j + k] = x0 - x1;
                    w = w * wn;
                }
            }
        }
        if(flag == -1) {
            for(int i = 0; i < n; i++) A[i] /= n;
        }
    }

    void multiply(int *res, const int *A, const int n, const int *B, const int m) {
        static complex _A[MXLEN], _B[MXLEN];
        static complex a[MXLEN], b[MXLEN], c[MXLEN], d[MXLEN];
        int X = 1;
        for(; X < n + m - 1; X <<= 1);
        for(int i = 0; i < n; i++) _A[i] = complex(A[i] >> 16, A[i] & 65535);
        fill(_A + n, _A + X + 1, complex(0, 0));
        for(int i = 0; i < m; i++) _B[i] = complex(B[i] >> 16, B[i] & 65535);
        fill(_B + m, _B + X + 1, complex(0, 0));
        DFT(_A, X), DFT(_B, X);
        for(int i = 0; i < X; i++) {
            int j = i ? X - i : 0;
            complex a1 = (_A[i] + ~_A[j]) * complex(0.5, 0), 
                    a2 = (_A[i] - ~_A[j]) * complex(0, -0.5), 
                    b1 = (_B[i] + ~_B[j]) * complex(0.5, 0), 
                    b2 = (_B[i] - ~_B[j]) * complex(0, -0.5);
            a[i] = a1 * b1, b[i] = a1 * b2;
            c[i] = a2 * b1, d[i] = a2 * b2;
        }
        for(int i = 0; i < X; i++) {
            _A[i] = a[i] + b[i] * complex(0, 1);
            _B[i] = c[i] + d[i] * complex(0, 1);
        }
        DFT(_A, X, -1), DFT(_B, X, -1);
        for(int i = 0; i < n + m - 1; i++) {
            LL a, b, c, d;
            a = LL(_A[i].x + 0.5) % mod;
            b = LL(_A[i].y + 0.5) % mod;
            c = LL(_B[i].x + 0.5) % mod;
            d = LL(_B[i].y + 0.5) % mod;
            res[i] = (((a << 32) + ((b + c) << 16) + d) % mod + mod) % mod;
        }
    }
} // namespace Polynomial_FFT

using LL = long long;
using poly_t = vector<int>;

const int MX = 1 << 18, MAXN = 100005;
const int mod = 998244353;

int a[MX];
poly_t P[MX];

poly_t& calc(int n) {
    priority_queue<pair<int, int>> polys;
    for(int i = 1; i <= n; i++) {
        P[i].assign(a[i] + 1, 0);
        P[i].front() = P[i].back() = 1;
        polys.emplace(-P[i].size(), i);
    }

    while(polys.size() > 1) {
        int u = polys.top().second;
        polys.pop();
        int v = polys.top().second;
        polys.pop();

        poly_t &A = P[u], &B = P[v];
        static int res[MX];
        Polynomial_FFT::multiply(res, A.data(), A.size(), B.data(), B.size());
        
        A = poly_t(res, res + (A.size() + B.size() - 1));
        polys.emplace(-P[u].size(), u);
    }

    return P[polys.top().second];
}

int Pow(int a, int b) {
    int ans = 1;
    for(; b; a = (LL)a * a % mod, b >>= 1)
        if(b & 1) ans = (LL)ans * a % mod;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        bool flag = false;
        cin >> n;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(a[i] == 0) {
                flag = true;
            }
        }
        
        if(flag) {
            cout << 0 << "\n";
            continue;
        }

        poly_t &res = calc(n);
        int ans = 1;
        for(size_t i = 1; i < res.size(); i++) if(res[i]) {
            ans = (LL)ans * Pow(i, res[i]) % mod;
        }
        cout << ans << "\n";
    }
    return 0;
}
