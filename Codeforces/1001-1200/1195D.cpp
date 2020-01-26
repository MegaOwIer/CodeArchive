#include <bits/stdc++.h>
using namespace std;

using LL = long long;
constexpr int mod = 998244353, MLEN = 10;

int sum[MLEN + 1][MLEN + 1], pw10[MLEN * 2 + 5], siz[MLEN + 1];

int calc1(int l1, int l2) {
    int cur = 0, ans = 0;
    for(int i = 0, j = 0; i < l1 || j < l2; i++, j++) {
        if(j < l2) ++cur;
        if(i < l1) {
            ans = (ans + (LL)sum[l1][i] * pw10[cur]) % mod;
            ++cur;
        }
    }
    return ans;
}

int calc2(int l1, int l2) {
    int cur = 0, ans = 0;
    for(int i = 0, j = 0; i < l1 || j < l2; i++, j++) {
        if(i < l1) {
            ans = (ans + (LL)sum[l1][i] * pw10[cur]) % mod;
            ++cur;
        }
        if(j < l2) ++cur;
    }
    return ans;
}

int main() {
    pw10[0] = 1;
    for(int i = 1; i <= MLEN * 2; i++) pw10[i] = 10LL * pw10[i - 1] % mod;

    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string val;
        cin >> val;
        int lth = val.length();
        reverse(val.begin(), val.end());
        for(size_t j = 0; j < lth; j++) {
            sum[lth][j] += val[j] - '0';
        }
        siz[lth]++;
    }
    int ans = 0;
    for(int i = 1; i <= MLEN; i++) {
        for(int j = 1; j <= MLEN; j++) {
            ans = (ans + (LL)siz[j] * calc1(i, j) + (LL)siz[i] * calc2(j, i)) % mod;
        }
    }
    cout << ans << "\n";
    return 0;
}
