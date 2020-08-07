#include <bits/stdc++.h>
using namespace std;

const int MX = 200005;

vector<int> A[MX];

int calc(vector<int> &vec, int del, int n, int m) {
    map<int, int> cnt;
    for(size_t i = 0; i < vec.size(); i++) {
        int val = vec[i] - del;
        if(val % m != 0) continue;
        val /= m;
        if(val < 0 || val >= n) continue;
        cnt[(i + n - val) % n]++;
    }
    int ans = n;
    for(auto &cur : cnt) {
        ans = min(ans, cur.first + n - cur.second);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) A[i].resize(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> A[j][i];
        }
    }
    int ans = 0;
    for(int i = 0; i < m; i++) ans += calc(A[i], i + 1, n, m);
    cout << ans << "\n";
    return 0;
}
