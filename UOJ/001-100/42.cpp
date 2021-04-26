/* 2021-02-25
 * Euclidean-like Algorithm.
 */

#include <bits/stdc++.h>
using namespace std;

using LL = long long;

LL solve(LL a, LL b, LL c, LL n, const int r, const long double sq) {
    if(n < 1) return 0;
    
    LL d = __gcd(a, __gcd(b, c));
    a /= d, b /= d, c /= d;
    
    long double k = (a * sq + b) / c;
    LL k_floor = floor(k);
    if(n == 1) return k_floor;

    LL cur = n * (n + 1) / 2 * k_floor;
    b -= c * k_floor;
    LL y_max = (k - k_floor) * n;
    return cur + n * y_max - solve(a * c, -b * c, a * a * r - b * b, y_max, r, sq);
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, r;
        scanf("%d%d", &n, &r);
        int s = sqrt(r);
        if(s * s == r) {
            printf("%d\n", (s & 1) ? ((n & 1) ? -1 : 0) : n);
        } else {
            long double sq = sqrtl(r);
            long long ans = n - 2 * solve(1, 0, 1, n, r, sq) + 4 * solve(1, 0, 2, n, r, sq);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
