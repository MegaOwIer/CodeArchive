#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int mod = 998244353, B = 31596;

int Pow(int a, int b) {
    int ans = 1;
    for(; b; b >>= 1, a = (LL)a * a % mod)
        if(b & 1) ans = (LL)ans * a % mod;
    return ans;
}

int solve(int x, int n) {
    static unordered_map<int, int> pw;
    pw.clear();

    int tt = Pow(n, B);
    for(int i = 1, tmp = tt; i <= B; i++) {
        pw[tmp] = i * B;
        tmp = (LL)tmp * tt % mod;
    }

    auto get_val = [&] (int val, int flag) {
        int ans = numeric_limits<int>::max();
        for(int i = 0; i <= B; i++) {
            if(pw.count(val)) {
                int cur = pw[val] - i;
                if(cur % 2 == flag) {
                    ans = min(ans, cur);
                }
            }
            val = (LL)val * n % mod;
        }
        return ans;
    };

    int ans = min(get_val(x + 1, 0), get_val(x - 1, 1));
    return ans >= mod ? -2 : ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        if(x == 0) {
            cout << 1 << "\n";
            continue;
        }
        if(x == 1) {
            cout << 0 << "\n";
            continue;
        }

        x = (LL)x * n % mod * Pow(n - 1, mod - 2) % mod;
        cout << solve(x, n - 1) + 1 << "\n";
    }
    return 0;
}
