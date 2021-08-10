#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        LL n;
        cin >> n;
        n %= mod;
        n = n * (n - 1) % mod;
        cout << 2 * n * n % mod << "\n";
    }
    return 0;
}
