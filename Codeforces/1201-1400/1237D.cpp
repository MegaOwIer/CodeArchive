#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 100005;

int n, tr[MX << 3], ans[MX << 1];
array<int, 2> num[MX];
set<int> visited;

void update(int l, int r, int id, int pos, int val) {
    tr[id] = val;
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(pos <= mid) update(l, mid, id << 1, pos, val);
    else update(mid + 1, r, id << 1 | 1, pos, val);
}

int getMin(int l, int r, int id, int L, int R) {
    if(L <= l && r <= R) return tr[id];
    int mid = (l + r) >> 1, res = INT_MAX;
    if(L <= mid) res = min(res, getMin(l, mid, id << 1, L, R));
    if(R > mid) res = min(res, getMin(mid + 1, r, id << 1 | 1, L, R));
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> num[i][0];
        num[i][1] = i;
    }
    sort(num + 1, num + n + 1, greater<array<int, 2>>());
    for(int i = 1; i <= n; i++) {
        update(1, 2 * n, 1, num[i][1], num[i][0]);
        update(1, 2 * n, 1, num[i][1] + n, num[i][0]);
    }
    for(int i = 1; i <= n; i++) {
        int val = num[i][0], pos = num[i][1];
        int end = visited.empty() ? pos + n : *visited.upper_bound(pos);
        int L = pos, R = end - 1, res = end;
        while(L <= R) {
            int mid = (L + R) >> 1;
            if(getMin(1, n * 2, 1, pos, mid) * 2 >= val) L = mid + 1;
            else res = mid, R = mid - 1;
        }
        if(res < end) ans[pos] = res - pos;
        else if(visited.empty() || ans[end] == -1) ans[pos] = -1;
        else ans[pos] = end - pos + ans[end];
        ans[n + pos] = ans[pos];
        visited.insert(pos);
        visited.insert(pos + n);
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}
