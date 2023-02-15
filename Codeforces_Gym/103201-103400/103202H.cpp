#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;
    cin >> n >> m >> r;

    vector<tuple<int, int, int>> cards;
    for(int i = 1; i <= n; i++) {
        int d, k, c;
        cin >> d >> k >> c;
        if((LL)k * r > c) {
            cards.emplace_back(d, k, c);
        }
    }

    map<int, int> rents;
    for(int i = 1; i <= m; i++) {
        int p, q;
        cin >> p >> q;
        rents[p] = q;
    }

    vector<int> days {0};
    map<int, size_t> st_idx;
    for(auto [key, val] : rents) {
        st_idx[key] = days.size();
        while(val--) {
            days.push_back(key);
        }
    }
    st_idx[1000000001] = days.size();

    vector<LL> dp;
    dp.assign(days.size(), numeric_limits<LL>::max());
    dp[0] = 0;

    auto update = [] (LL &u, LL v) {
        if(u > v) u = v;
    };

    for(size_t i = 0; i < dp.size() - 1; i++) {
        update(dp[i + 1], dp[i] + r);
        for(const auto &[d, k, c] : cards) {
            size_t j = min(i + k, dp.size() - 1);
            if(days[j] - days[i + 1] >= d) {
                j = st_idx.lower_bound(days[i + 1] + d)->second - 1;
            }
            update(dp[j], dp[i] + c);
        }
    }

    cout << dp.back() << "\n";
    return 0;
}
