#include<bits/stdc++.h>
using namespace std;

int getSum(int x) {
    int ans = 0;
    for(; x; x /= 10) ans += x % 10;
    return ans;
}

vector<int> divide(int x) {
    vector<int> ans;
    for(int i = 1; i * i <= x; i++) if(x % i == 0) {
        ans.push_back(i);
        if(i * i != x) ans.push_back(x / i);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int x;
        cin >> x;
        x = __gcd(x, getSum(x));
        vector<int> res = divide(x);
        cout << res.size() << "\n";
        for(int u : res) cout << u << " \n"[x == u];
    }
    return 0;
}
