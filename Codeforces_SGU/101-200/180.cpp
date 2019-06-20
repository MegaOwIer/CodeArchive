#include<bits/stdc++.h>
using namespace std;

const int MX = 65539;

int n, a[MX], ls[MX], tr[MX];
long long ans;

int query(int x) {
    int ans = 0;
    while(x) ans += tr[x], x -= x & -x;
    return ans;
}
void modify(int x) {
    while(x <= n) ++tr[x], x += x & -x;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    memcpy(ls + 1, a + 1, sizeof(int[n]));
    sort(ls + 1, ls + n + 1);
    for(int i = 1; i <= n; i++)
        a[i] = lower_bound(ls + 1, ls + n + 1, a[i]) - ls;
    for(int i = n; i >= 1; i--) {
        ans += query(a[i] - 1);
        modify(a[i]);
    }
    cout << ans << "\n";
    return 0;
}
