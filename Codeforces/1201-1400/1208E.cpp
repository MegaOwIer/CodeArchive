#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 1000005;

int a[MX], tr[MX << 2];
long long ans1[MX], ans2[MX];

void build(int l, int r, int id) {
    if(l == r) {
        tr[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, id << 1), build(mid + 1, r, id << 1 | 1);
    tr[id] = max(tr[id << 1], tr[id << 1 | 1]);
}

int query(int l, int r, int id, int L, int R) {
    if(L <= l && r <= R) return tr[id];
    int mid = (l + r) >> 1, ans = INT_MIN;
    if(L <= mid) ans = max(ans, query(l, mid, id << 1, L, R));
    if(R > mid) ans = max(ans, query(mid + 1, r, id << 1 | 1, L, R));
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int _n, w;
    cin >> _n >> w;
    for(int i = 1; i <= _n; i++) {
        int n;
        cin >> n;
        for(int j = 1; j <= n; j++) cin >> a[j];
        build(1, n, 1);
        int l = w + 1 - n;
        if(n + 1 <= l) {
            ans1[n + 1] += max(0, tr[1]);
            ans1[l] -= max(0, tr[1]);
            for(int it = 1; it <= n; it++)
                ans2[it] += max(0, query(1, n, 1, 1, it));
            for(int it = l, r = 1; it <= w; it++, r++)
                ans2[it] += max(0, query(1, n, 1, r, n));
        } else {
            for(int it = 1; it < l; it++)
                ans2[it] += max(0, query(1, n, 1, 1, it));
            for(int it = l; it <= n; it++)
                ans2[it] += query(1, n, 1, it - l + 1, it);
            for(int it = n + 1; it <= w; it++)
                ans2[it] += max(0, query(1, n, 1, it - l + 1, n));
        }
    }
    for(int i = 1; i <= w; i++) ans1[i] += ans1[i - 1];
    for(int i = 1; i <= w; i++) cout << ans1[i] + ans2[i] << ' ';
    return 0;
}
