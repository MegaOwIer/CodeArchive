#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int Pow(int a, int b, int mod) {
    int ans = 1;
    for(; b; a = (LL)a * a % mod, b >>= 1)
        if(b & 1) ans = (LL)ans * a % mod;
    return ans;
}

vector<pair<int, int>> init(const int n) {
    vector<pair<int, int>> res;
    int tmp = n;
    for(int i = 2; i * i <= tmp; i++) if(tmp % i == 0) {
        int d = 1;
        while(tmp % i == 0) tmp /= i, d *= i;
        res.emplace_back(d, i);
    }
    if(tmp > 1) res.emplace_back(tmp, tmp);
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> factors = init(n);
    vector<int> cof;
    vector<vector<int>> sol;
    for(auto &cur : factors) {
        int d = cur.first, p = cur.second;
        int M = n / d;
        cof.push_back((LL)M * Pow(M, d - d / p - 1, d) % n);
        if(p == 2 && d > 4) {
            sol.push_back({1, d / 2 - 1, d / 2 + 1, d - 1});
        } else if(d == 2) {
            sol.push_back({1});
        } else {
            sol.push_back({1, d - 1});
        }
    }

    vector<int> ans;
    function<void(size_t, int)> dfs = [&] (size_t id, int cur) {
        if(id == cof.size()) {
            return ans.push_back(cur);
        }
        for(int tmp : sol[id]) {
            dfs(id + 1, (cur + (LL)tmp * cof[id]) % n);
        }
    };

    dfs(0, 0);
    sort(ans.begin(), ans.end());
    if(ans.empty()) puts("None");
    else for(int val : ans) printf("%d\n", val);

    return 0;
}
