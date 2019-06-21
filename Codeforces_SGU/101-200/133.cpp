#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> V;
set<int> S;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        V.push_back({l, r});
    }
    sort(V.begin(), V.end());
    int ans = 0;
    for(auto &cur : V) {
        ans += S.upper_bound(cur.second) != S.end();
        S.insert(cur.second);
    }
    cout << ans << "\n";
    return 0;
}
