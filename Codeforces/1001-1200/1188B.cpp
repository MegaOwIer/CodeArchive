#include<bits/stdc++.h>
using namespace std;

using LL = long long;

const int MX = 300005;

map<int, int> S;

int Pow(int u, int mod) {
    int ans = (LL)u * u % mod;
    return (LL)ans * ans % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int n, k, p;
    cin >> n >> p >> k;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        ++S[(Pow(val, p) - (LL)k * val % p + p) % p];
    }
    long long ans = 0;
    for(auto &cur : S)
        ans += LL(cur.second - 1) * cur.second / 2;
    cout << ans << endl;
    return 0;
}
