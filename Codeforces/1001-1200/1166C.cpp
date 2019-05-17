#include<bits/stdc++.h>
using namespace std;

const int MX = 200005;

int n, a[MX];
long long ans;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1, val; i <= n; i++) {
        cin >> val;
        a[i] = abs(val);
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        ans += upper_bound(a + i, a + n + 1, 2 * a[i]) - (a + i) - 1;
    cout << ans << endl;
    return 0;
}
