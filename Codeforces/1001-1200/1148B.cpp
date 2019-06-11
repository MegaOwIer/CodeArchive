#include<bits/stdc++.h>
using namespace std;

vector<int> a, b;

int main() {
    ios::sync_with_stdio(false);
    int n, m, ta, tb, k, ans = 0;
    cin >> n >> m >> ta >> tb >> k;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        a.push_back(val);
    }
    sort(a.begin(), a.end());
    for(int i = 1; i <= m; i++) {
        int val;
        cin >> val;
        b.push_back(val);
    }
    sort(b.begin(), b.end());
    if(k >= a.size() || k >= b.size())
        return puts("-1"), 0;
    for(size_t i = 0; i < a.size() && i <= k; i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i] + ta);
        if(b.end() - it <= k - i)
            return puts("-1"), 0;
        ans = max(ans, *(it + k - i) + tb);
    }
    cout << ans << "\n";
    return 0;
}
