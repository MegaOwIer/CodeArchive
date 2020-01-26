#include <bits/stdc++.h>
using namespace std;

using LL = long long;

LL count_odd(LL u, LL n) {
    LL ans = 0;
    for(int i = 0; u <= n; i++, u <<= 1) {
        ans += min(n, u + (1LL << i) - 1) - u + 1;
    }
    return ans;
}

LL count_even(LL u, LL n) {
    LL ans = count_odd(u + 1, n);
    for(int i = 0; u <= n; i++, u <<= 1) {
        ans += min(n, u + (1LL << i) - 1) - u + 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    long long n, k;
    cin >> n >> k;
    LL l = 1, r = n / 2, ans = 0;
    while(l <= r) {
        LL mid = (l + r) / 2;
        if(count_even(mid * 2, n) >= k) ans = mid * 2, l = mid + 1;
        else r = mid - 1;
    }
    l = ans / 2, r = (n - 1) / 2;
    while(l <= r) {
        LL mid = (l + r) / 2;
        if(count_odd(mid * 2 + 1, n) >= k) ans = mid * 2 + 1, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << "\n";
    return 0;
}
