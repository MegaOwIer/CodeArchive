#include <bits/stdc++.h>
using namespace std;

using LL = long long;

struct modInt {
    static int mod;
    int val;

    modInt() : val(0) {}
    modInt(int u) : val(u % mod) {}

    static void setmod(int p) {mod = p;}

    modInt operator+ (modInt u) {
        modInt res;
        res.val = (val + u.val >= mod) ? val + u.val - mod : val + u.val;
        return res;
    }
    modInt operator* (modInt u) {
        modInt res;
        res.val = (LL)val * u.val % mod;
        return res;
    }

    modInt& operator+= (modInt u) {
        return *this = *this + u;
    }
    modInt& operator*= (modInt u) {
        return *this = *this * u;
    }
};

int modInt::mod;

struct Matrix {
    modInt a[2][2];

    Matrix() {}

    modInt *operator[] (int u) {return a[u];}

    Matrix operator* (Matrix u) {
        Matrix ans;
        for(int k : {0, 1}) {
            for(int i : {0, 1}) {
                for(int j : {0, 1}) {
                    ans[i][j] += a[i][k] * u[k][j];
                }
            }
        }
        return ans;
    }
};

int Pow(int a, int b, int mod) {
    int ans = 1;
    for(; b; b >>= 1, a = (LL)a * a % mod)
        if(b & 1) ans = (LL)ans * a % mod;
    return ans;
}

Matrix Pow(Matrix a, LL b) {
    Matrix ans;
    ans[0][0] = ans[1][1] = 1;
    for(; b; b >>= 1, a = a * a)
        if(b & 1) ans = ans * a;
    return ans;
}

int primitive_root(int p) {
    vector<int> factors;
    int tmp = p - 1;
    for(int i = 2; i * i <= tmp; i++) if(tmp % i == 0) {
        factors.push_back(i);
        while(tmp % i == 0) tmp /= i;
    }
    if(tmp > 1) factors.push_back(tmp);
    for(int g = 2; ; g++) {
        bool failed = false;
        for(int d : factors) {
            if(Pow(g, (p - 1) / d, p) == 1) {
                failed = true;
                break;
            }
        }
        if(!failed) {
            return g;
        }
    }
}

int main() {
    int _;
    scanf("%d", &_);
    while(_--) {
        int k, p;
        long long n;
        scanf("%lld%d%d", &n, &k, &p);
        modInt::setmod(p);
        int lambda = Pow(primitive_root(p), (p - 1) / k, p);
        modInt ans = 0;
        for(int i = 1, cur = 1; i <= k; i++) {
            Matrix tmp;
            tmp[0][0] = cur + 1;
            tmp[0][1] = tmp[1][0] = cur;
            tmp[1][1] = 1;
            tmp = Pow(tmp, n);
            ans += tmp[0][0];
            cur = (LL)cur * lambda % p;
        }
        ans *= Pow(k, p - 2, p);
        printf("%d\n", (LL)ans.val);
    }
    return 0;
}
