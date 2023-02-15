#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, m;
    LL a;
    cin >> h >> m >> a;

    if(a * 2 == (LL)h * m) {
        cout << (LL)h * m << "\n";
        return 0;
    }

    int d = __gcd(h - 1, m);
    cout << (a / d * 2 + 1) * d << "\n";

    return 0;
}
