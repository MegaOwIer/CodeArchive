#include <bits/stdc++.h>
using namespace std;

using LD = double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int k, x1, x2, x3, y1, y2, y3;
        cin >> k >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        int x = x3 - x2, h = y1 - y2;
        LD ans = x * h * (2. * k - 5) + x * h * 3 * pow(2, 1 - k);
        printf("%.3lf\n", ans);
    }
    return 0;
}
