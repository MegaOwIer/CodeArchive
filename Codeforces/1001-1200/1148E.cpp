#include<bits/stdc++.h>
using namespace std;

using ans_t = tuple<int, int, int>;
const int MX = 300005;

int n, t[MX], diff[MX];
pair<int, int> s[MX];
vector<int> bk;
vector<ans_t> ans;

inline void operate(int u, int v, int d) {
    ans.push_back({s[u].second, s[v].second, d});
    diff[u] -= d, diff[v] += d;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i].first;
        s[i].second = i;
    }
    for(int i = 1; i <= n; i++) cin >> t[i];
    sort(s + 1, s + n + 1);
    sort(t + 1, t + n + 1);
    for(int i = 1; i <= n; i++) {
        diff[i] = t[i] - s[i].first;
        if(diff[i] < 0) bk.push_back(i);
    }
    reverse(bk.begin(), bk.end());
    for(int i = 1; i <= n; i++) {
        if(diff[i] < 0) return puts("NO"), 0;
        if(diff[i] == 0) continue;
        while(diff[i] > 0) {
            if(bk.empty()) return puts("NO"), 0;
            operate(i, bk.back(), min(diff[i], -diff[bk.back()]));
            if(!diff[bk.back()]) bk.pop_back();
        }
    }
    if(!bk.empty()) return puts("NO"), 0;
    cout << "YES\n" << ans.size() << "\n";
    for(auto res : ans) {
        int u, v, d;
        tie(u, v, d) = res;
        cout << u << ' ' << v << ' ' << d << "\n";
    }
    return 0;
}
