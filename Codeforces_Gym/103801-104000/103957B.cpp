#include <bits/stdc++.h>
using namespace std;

using LL = long long;

LL solve() {
    int n;
    LL g, p;
    cin >> n >> g >> p;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    LL sum = 0, min_sum = numeric_limits<LL>::max();
    for(int val : arr) {
        sum += val;
        if(sum < min_sum) {
            min_sum = sum;
        }
    }

    LL max_round = p / n;
    LL ans1 = g, ans2 = g;
    for(int i = n - 1; i >= 0; i--) {
        ans2 = min(g, max(0LL, ans2 - arr[i]));
        if(i < p % n) {
            ans1 = min(g, max(0LL, ans1 - arr[i]));
        }
    }

    if(max_round == 0) {
        return ans1;
    }

    if(sum <= 0) {
        if(ans1 <= sum - min_sum) {
            ans1 = 0;
        }
        if(max_round > 1 && ans2 <= sum - min_sum) {
            ans2 = 0;
        }
        return min(ans1, ans2);
    }

    if(ans1 / sum < max_round) {
        ans1 = 0;
    } else {
        ans1 -= max_round * sum;
    }

    if(ans2 / sum < max_round - 1) {
        ans2 = 0;
    } else {
        ans2 -= (max_round - 1) * sum;
    }

    LL ans = min(ans1, ans2);
    if(ans <= -min_sum || ans <= 0) {
        return 0;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int _ = 1; _ <= T; _++) {
        printf("Case #%d: %lld\n", _, solve());
    }
    return 0;
}
