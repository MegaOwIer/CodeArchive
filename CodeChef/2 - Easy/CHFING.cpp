#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int mod = 1000000007;
const int inv2 = (mod + 1) >> 1;

int solve(LL a, LL d) {
    return (a + a % d) % mod * ((a / d + 1) % mod) % mod * inv2 % mod;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        LL N, K;
        cin >> N >> K;
        cout << solve(K - 1, N - 1) << "\n";
    }
    return 0;
}
