#include <bits/stdc++.h>
using namespace std;

using LL = long long;

constexpr int MX = 100000, mod = 1000000007;

int fib[MX + 5];

int main() {
    fib[1] = 1, fib[2] = 2;
    for(int i = 3; i <= MX; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    cout << 2LL * (fib[n] + fib[m] - 1) % mod << "\n";
    return 0;
}
