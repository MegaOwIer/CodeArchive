#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 200005;

int n, ans[MX];
set<int> val;
LL a[MX], tr[MX];

void insert(int u) {
    for(int i = u; i <= n; i += i & -i) tr[i] += u;
}
long long getSum(int u) {
    long long ans = 0;
    for(; u; u -= u & -u) ans += tr[u];
    return ans;
}

long long check(int u) {
    return LL(u - 1) * u / 2 - getSum(u - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) val.insert(i);
    for(int i = n; i >= 1; i--) {
        int l = 1, r = n, res = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(check(mid) >= a[i]) res = mid, r = mid - 1;
            else l = mid + 1;
        }
        res = *val.lower_bound(res);
        ans[i] = res, insert(res), val.erase(res);
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    return 0;
}
