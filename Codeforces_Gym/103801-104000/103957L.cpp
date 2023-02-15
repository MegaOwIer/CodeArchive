#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 1003;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int _ = 1; _ <= T; _++) {
        int r, c;
        cin >> r >> c;

        vector<tuple<int, int, int>> info;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                string qwq;
                cin >> qwq;
                if(qwq != "?") {
                    info.emplace_back(i, j, atoi(qwq.c_str()));
                }
            }
        }

        auto check = [&] (int x, int y) {
            for(auto [i, j, val] : info) {
                if((LL)(x + i) * (y + j) != val) {
                    return false;
                }
            }
            return true;
        };

        if(info.empty()) {
            printf("Case #%d: Yes\n", _);
        } else if(info.size() == 1) {
            bool result = false;
            int i, j, target;
            tie(i, j, target) = info[0];
            for(int t = min(i, j) + 1; t * (max(i, j) + 1) <= target; t++) {
                if(target % t == 0) {
                    result = true;
                    break;
                }
            }
            if(result) {
                printf("Case #%d: Yes\n", _);
            } else {
                printf("Case #%d: No\n", _);
            }
        } else {
            bool result = false;
            int i, j, target;
            tie(i, j, target) = info[0];

            int p, q, trigger;
            tie(p, q, trigger) = info[1];
            for(int t = min(i, j) + 1; t * (max(i, j) + 1) <= target; t++) {
                if(target % t != 0) {
                    continue;
                }
                int s = target / t;
                // s, t
                if((LL)(s - i + p) * (t - j + q) == trigger) {
                    if(check(s - i, t - j)) {
                        result = true;
                        break;
                    }
                }
                // t, s
                if((LL)(t - i + p) * (s - j + q) == trigger) {
                    if(check(t - i, s - j)) {
                        result = true;
                        break;
                    }
                }
            }

            if(result) {
                printf("Case #%d: Yes\n", _);
            } else {
                printf("Case #%d: No\n", _);
            }
        }
    }
    return 0;
}
