/**
 * @date 2022-08-23
 * @author MegaOwIer (megaowier@gmail.com)
 * @link http://oj.daimayuan.top/problem/61
 * @brief Template for bisection on the answer.
 */

#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    vector<int> arr;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end());

    function<bool(LL)> check = [&] (LL val) {
        LL tot = k;
        for(size_t i = 0; i < arr.size() && tot >= 0; i++) {
            if(arr[i] < val) {
                tot -= val - arr[i];
            }
        }
        return tot >= 0;
    };

    LL l = 1, r = 100000000000000, ans = -1;
    while(l <= r) {
        LL mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid, l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
