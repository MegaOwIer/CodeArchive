#include<bits/stdc++.h>
using namespace std;

using LL = long long;

const int MX = 1000, mod = 1000000007;

int C[MX + 5][MX + 5];

int main() {
    for(int i = 0; i <= MX; i++) C[i][0] = 1;
    for(int i = 1; i <= MX; i++)
        for(int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        if(n < m) swap(n, m);
        cout << C[n][m] << "\n";
    }
    return 0;
}
