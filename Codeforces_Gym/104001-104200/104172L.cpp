#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> pos(n + 1);
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        pos[val] = i;
    }

    bool invalid = false;
    vector<bool> used(n + 1);
    for(int i = 1, lst = 0; i <= m; i++) {
        int val;
        cin >> val;
        if(pos[val] < lst) {
            invalid = true;
        }
        lst = pos[val];
        used[val] = true;
    }

    map<int, int> tool;
    for(int i = 1; i <= k; i++) {
        int val;
        cin >> val;
        tool[val]++;
    }

    if(invalid) {
        return false;
    }

    set<int> used_position {0, n + 1};
    vector<int> bit(n + 1);

    auto query = [&] (int u) {
        int ans = 0;
        while(u > 0) {
            ans += bit[u];
            u -= u & -u;
        }
        return ans;
    };

    for(int i = n; i >= 1; i--) {
        if(used[i]) {
            used_position.insert(pos[i]);
            continue;
        }
        int cur_pos = pos[i];
        auto nxt = used_position.lower_bound(pos[i]);
        auto pre = prev(nxt);

        int mxlen = *nxt - *pre - 1 - (query(*nxt - 1) - query(*pre));
        auto it = tool.upper_bound(mxlen);
        if(it == tool.begin()) {
            return false;
        }
        it--;
        if(--(it->second) == 0) {
            tool.erase(it);
        }

        while(cur_pos <= n) {
            bit[cur_pos]++;
            cur_pos += cur_pos & -cur_pos;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        if(solve()) {
            puts("YES");
        } else {
            puts("NO");
        }
    }

    return 0;
}
