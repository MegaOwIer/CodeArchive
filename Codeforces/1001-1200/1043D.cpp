#include <bits/stdc++.h>
using namespace std;

constexpr int MX = 100005;

map<pair<int, int>, int> cnt;
int to[MX], ind[MX], dep[MX];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int cur, lst;
        cin >> lst;
        for(int j = 1; j < n; j++) {
            cin >> cur;
            cnt[{lst, cur}]++;
            lst = cur;
        }
    }
    for(auto &cur : cnt) if(cur.second == m) {
        to[cur.first.first] = cur.first.second;
        ind[cur.first.second] = 1;
    }

    function<void(int)> dfs = [&](int u) {
        if(to[u] != 0) dep[to[u]] = dep[u] + 1, dfs(to[u]);
    };

    for(int i = 1; i <= n; i++) if(!ind[i]) dfs(i);
    long long ans = n;
    for(int i = 1; i <= n; i++) ans += dep[i];
    cout << ans << "\n";
    return 0;
}
