#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int mod = 1000000007;

struct Matrix {
    int a[2][2];

    Matrix() {
        memset(a, 0, sizeof(a));
    }

    int *operator[] (int u) {return a[u];}

    Matrix operator* (Matrix u) {
        Matrix ans;
        ans[0][0] = ((LL)a[0][0] * u[0][0] + (LL)a[0][1] * u[1][0]) % mod;
        ans[0][1] = ((LL)a[0][0] * u[0][1] + (LL)a[0][1] * u[1][1]) % mod;
        ans[1][0] = ((LL)a[1][0] * u[0][0] + (LL)a[1][1] * u[1][0]) % mod;
        ans[1][1] = ((LL)a[1][0] * u[0][1] + (LL)a[1][1] * u[1][1]) % mod;
        return ans;
    }
};

long long dp[64];

long long calc1(LL n) {
    int l = 0;
    while(n >> l) l++;
    long long ans = 0;
    for(int i = l - 1, pre = 0; i >= 0; i--) {
        int cur = (n >> i) & 1;
        if(cur) ans += dp[i];
        if(pre && cur) break;
        pre = cur;
    }
    return ans - 1;
}

Matrix Pow(Matrix a, LL b) {
    Matrix ans;
    ans[0][0] = ans[1][1] = 1;
    for(; b; b >>= 1, a = a * a)
        if(b & 1) ans = ans * a;
    return ans;
}

int calc2(long long n) {
    Matrix tmp;
    tmp[0][0] = tmp[0][1] = tmp[1][0] = 1;
    return Pow(tmp, n + 1)[0][0];
}

int main() {
    dp[0] = 1, dp[1] = 2;
    for(int i = 2; i < 64; i++) dp[i] = dp[i - 1] + dp[i - 2];
    int _;
    scanf("%d", &_);
    while(_--) {
        long long n;
        scanf("%lld", &n);
        printf("%lld\n%d\n", calc1(n + 1), calc2(n));
    }
    return 0;
}
