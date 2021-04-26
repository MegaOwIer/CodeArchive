#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 100005;

LL a[MX], p[MX];
int atk_p[MX];

LL ex_gcd(LL a, LL b, LL &x, LL &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    LL d = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

inline LL mul_mod(LL a, LL b, LL mod) {
    long long cur = (__int128_t)a * b % mod;
    if(cur < 0) cur += mod;
    return cur;
}

// ax \equiv b \pmod p
bool merge(LL &res, LL &mod, LL a, LL b, LL p) {
    static LL x, y, d;
    d = ex_gcd(a, p, x, y);
    if(b % d != 0) {
        mod = -1;
        return false;
    }
    a /= d, b /= d, p /= d;
    b = mul_mod(b, x, p);
    d = ex_gcd(mod, p, x, y);
    if((b - res) % d != 0) {
        mod = -1;
        return false;
    }
    long long new_mod = mod / d * p;
    b = (b - res + new_mod) % new_mod;
    x = mul_mod(x, b / d, p / d);
    res = (x * mod + res) % new_mod;
    mod = new_mod;
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        for(int i = 1; i <= n; i++) scanf("%lld", &p[i]);
        for(int i = 1; i <= n; i++) scanf("%d", &atk_p[i]);
        multiset<LL> atk;
        for(int i = 1; i <= m; i++) {
            int val;
            scanf("%d", &val);
            atk.insert(val);
        }
        long long min_ans = 0, mod = 1, res = 0;
        for(int i = 1; i <= n; i++) {
            auto it = atk.upper_bound(a[i]);
            if(it != atk.begin()) --it;
            int cur_atk = *it;
            atk.erase(it);
            atk.insert(atk_p[i]);
            min_ans = max(min_ans, (a[i] + cur_atk - 1) / cur_atk);
            if(!merge(res, mod, cur_atk, a[i] % p[i], p[i])) break;
        }
        if(mod == -1) {
            puts("-1");
        } else {
            long long tmp = min_ans / mod * mod + res;
            printf("%lld\n", tmp >= min_ans ? tmp : tmp + mod);
        }
    }
    return 0;
}
