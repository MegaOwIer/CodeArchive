#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int n;
    vector<LL> vec = {0};
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        vec.push_back(val + vec.back());
    }
    set<LL> num;
    LL ans = 0;
    for(size_t i = 0, j = 0; i < vec.size(); i++) {
        while(j < vec.size() && num.find(vec[j]) == num.end()) num.insert(vec[j++]);
        ans += j - i - 1;
        num.erase(vec[i]);
    }
    cout << ans << "\n";
    return 0;
}
