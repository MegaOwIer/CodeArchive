#include<bits/stdc++.h>
using namespace std;
 
constexpr int MX = 400005;
 
int a[MX], b[MX];
pair<int, int> num[MX];
 
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    memcpy(b + 1, a + 1, sizeof(int[n]));
    sort(b + 1, b + n + 1);
    int val_nums = unique(b + 1, b + n + 1) - b - 1;
    for(int i = 1; i <= n; i++)
        a[i] = lower_bound(b + 1, b + val_nums + 1, a[i]) - b;
    for(int i = 1; i <= val_nums; i++) num[i].first = i;
    for(int i = 1; i <= n; i++) num[a[i]].second++;
 
    sort(num + 1, num + val_nums + 1, [&](auto u, auto v) {
        return u.second < v.second;
    });
    int size = 0;
    pair<int, int> ans {0, 0};
    for(int i = 1, j = 1, k = 1; ; i++, j = k) {
        while(num[k].second == i) k++;
        size += val_nums - j + 1;
        if(size < i * i) break;
        ans = max(ans, {size / i * i, i});
    }
    cout << ans.first << "\n" << ans.second << ' ' << ans.first / ans.second << "\n";
 
    function<void(int&, int&, int, int)> getNext = [](int &x, int &y, int w, int h) {
        ++x, ++y;
        if(x == w) x = 0, y -= w - 1;
        if(y == h) y = 0;
        if(y < 0) y += h;
    };
 
    vector<vector<int>> res(ans.second, vector<int>(ans.first / ans.second, 0));
    for(int i = val_nums, x = 0, y = 0; i >= 1; i--) {
        int cnt = min(num[i].second, ans.second);
        while(cnt--) res[x][y] = b[num[i].first], getNext(x, y, ans.second, ans.first / ans.second);
    }
    for(auto row : res) {
        for(int u : row) cout << u << ' ';
        cout << "\n";
    }
    return 0;
}