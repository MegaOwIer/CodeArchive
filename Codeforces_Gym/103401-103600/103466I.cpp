#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int mod = 1000000007;
const int MX = 100005;

int fac[MX], inv[MX];

int Pow(int a, int b) {
    int ans = 1;
    for(; b; b >>= 1) {
        if(b & 1) ans = (LL)ans * a % mod;
        a = (LL)a * a % mod;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, init, mxVal = 0;
    cin >> n >> init;

    fac[0] = 1;
    for(int i = 1; i <= n; i++) fac[i] = (LL)fac[i - 1] * i % mod;
    inv[n] = Pow(fac[n], mod - 2);
    for(int i = n; i; i--) inv[i - 1] = (LL)inv[i] * i % mod;

    vector<int> cnt(50);
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        mxVal = max(mxVal, val);
        if(val < 50) {
            cnt[val]++;
        }
    }

    vector<int> used(50);
    map<vector<int>, int> dp;

    function<int(int)> dfs = [&] (int sum) -> int {
        if(sum >= mxVal) {
            return fac[n - cnt[0] - accumulate(used.begin(), used.end(), 0)];
        }
        if(dp.count(used)) {
            return dp[used];
        }
        int ans = 0;
        for(int i = 1; i <= sum; i++) {
            used[i]++;
            ans = (ans + (LL)(cnt[i] - used[i] + 1) * dfs(sum + i)) % mod;
            used[i]--;
        }
        return dp[used] = ans;
    };

    cout << (LL)fac[n] * inv[n - cnt[0]] % mod * dfs(init) % mod << "\n";
    return 0;
}
