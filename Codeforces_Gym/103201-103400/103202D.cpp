#include <bits/stdc++.h>
using namespace std;

using LL = long long;

bool dfs(int it, int sum, int n0, int n1, int n, int &res, string &ans) {
    bool valid = false;
    if(n0 <= n / 2 && n1 <= (n + 1) / 2) {
        valid = true;
    }
    if(n1 <= n / 2 && n0 <= (n + 1) / 2) {
        valid = true;
    }
    if(!valid) {
        return false;
    }

    if(it == n) {
        cout << ans << "\n";
        res--;
        return res == 0;
    }

    ans.push_back('b');
    if(dfs(it + 1, sum, n0 + (sum == 0), n1 + (sum == 1), n, res, ans)) {
        return true;
    }
    ans.pop_back();

    ans.push_back('r');
    if(dfs(it + 1, sum ^ 1, n0 + (sum == 1), n1 + (sum == 0), n, res, ans)) {
        return true;
    }
    ans.pop_back();

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << (LL)((n + 1) / 2) * ((n + 2) / 2) << "\n";

    int res = 100;
    string ans;
    dfs(1, 0, 1, 0, n + 1, res, ans);

    return 0;
}
