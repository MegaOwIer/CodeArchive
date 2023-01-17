/**
 * @date 2023-01-12
 * @author MegaOwIer (megaowier@gmail.com)
 * @brief Simple digit dp
 */

#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int solve() {
    LL x, y;
    cin >> x >> y;

    vector<int> a, b;
    while(x) {
        a.push_back(x % 3);
        x /= 3;
    }
    while(y) {
        b.push_back(y % 3);
        y /= 3;
    }

    while(a.size() < b.size()) {
        a.push_back(0);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int pref = 0;
    size_t i = 0;
    while(i < b.size() && a[i] == b[i]) {
        pref += b[i] + 1;
        i++;
    }

    int ans = 0;
    while(i < b.size()) {
        if(i == 0 && b[i] == 1) {
            ans = max<int>(ans, pref + 3 * (b.size() - i - 1));
        } else {
            ans = max<int>(ans, pref + b[i] + 3 * (b.size() - i - 1));
        }
        pref += b[i] + 1;
        i++;
    }

    return max(pref, ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cout << solve() << "\n";
    }
    return 0;
}
