#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 10000000;

LL sum[MX + 5];

int main() {
    for(int i = 2; i <= MX; i++) sum[i] = i;
    for(int i = 2; i <= MX; i++) if(sum[i]) {
        for(int j = i * 2; j <= MX; j += i) {
            sum[j] = 0;
        }
    }
    sum[2] = 0;
    for(int i = 2; i <= MX; i++) sum[i] += sum[i - 1];

    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if (n < 3) {
            cout << 0 << "\n";
            continue;
        }

        long long ans = (LL)n * (n + 1) / 2;
        cout << ans - 3 + sum[n] << "\n";
    }
    return 0;
}
