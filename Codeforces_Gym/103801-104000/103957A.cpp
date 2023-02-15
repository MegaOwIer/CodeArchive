#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        long long n;
        cin >> n;

        long long w = sqrtl(2 * n) - 1;
        while(w * (w + 1) <= n * 2) w++;
        cout << "Case #" << i << ": " << w * (w - 1) / 2 << "\n";
    }
    return 0;
}
