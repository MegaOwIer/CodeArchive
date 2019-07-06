#include<bits/stdc++.h>
using namespace std;

const int MX = 1005;

bool vis[MX];
vector<pair<int, int>> S[2], tmp;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        (t == 1 ? tmp : S[0]).push_back({l, r});
    }
    if(!tmp.empty()) {
        sort(tmp.begin(), tmp.end());
        int l = tmp.front().first, r = tmp.front().second;
        for(auto &cur : tmp) {
            if(cur.first <= r) r = max(r, cur.second);
            else {
                S[1].push_back({r, l});
                l = cur.first, r = cur.second;
            }
        }
        S[1].push_back({r, l});
    }
    for(auto &cur : S[0]) {
        int l = cur.first, r = cur.second;
        auto it = lower_bound(S[1].begin(), S[1].end(), make_pair(r, -1));
        if(it != S[1].end() && it -> second <= l)
            return puts("NO"), 0;
    }
    int cur = n;
    S[1].push_back({0, 0});
    reverse(S[1].begin(), S[1].end());
    cout << "YES\n";
    for(int i = 1; i <= n; i++, cur--) {
        if(i == S[1].back().second) {
            while(i++ <= S[1].back().first)
                cout << cur << ' ';
            S[1].pop_back();
            i -= 2;
        } else {
            cout << cur << ' ';
        }
    }
    return 0;
}
