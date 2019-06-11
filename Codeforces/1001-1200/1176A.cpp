#include<bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int q;
    cin >> q;
    while(q--) {
        LL n;
        cin >> n;
        int ans = 0;
        while(n % 5 == 0)
            n = n / 5 * 4, ++ans;
        while(n % 3 == 0)
            n = n / 3 * 2, ++ans;
        while(n % 2 == 0)
            n >>= 1, ++ans;
        if(n != 1)
            ans = -1;
        cout << ans << '\n';
    }
    return 0;
}
