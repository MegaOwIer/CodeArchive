#include<bits/stdc++.h>
using namespace std;

using LL = long long;
constexpr int mod = 1000000007, MX = 1050;

int C[MX + 5][15];

int main() {
    for(int i = 0; i <= MX; i++) C[i][0] = 1;
    for(int i = 1; i <= MX; i++)
        for(int j = 1; j <= i && j <= 10; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    m--;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = (ans + (LL)C[i - 1 + m][m] * C[n - i + m + 1][m + 1]) % mod;
    }
    cout << ans << "\n";
    return 0;
}
