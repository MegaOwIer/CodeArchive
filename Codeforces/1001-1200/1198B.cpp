#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 200005;

int n, a[MX], tr[MX << 2];

void build(int l, int r, int id) {
    if(l == r) {
        tr[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, id << 1);
    build(mid + 1, r, id << 1 | 1);
}

void pushdown(int id) {
    if(tr[id]) {
        tr[id << 1] = max(tr[id << 1], tr[id]);
        tr[id << 1 | 1] = max(tr[id << 1 | 1], tr[id]);
        tr[id] = 0;
    }
}

void modify(int l, int r, int id, int pos, int val) {
    if(l == r) {
        tr[id] = val;
        return;
    }
    pushdown(id);
    int mid = (l + r) >> 1;
    if(pos <= mid) modify(l, mid, id << 1, pos, val);
    else modify(mid + 1, r, id << 1 | 1, pos, val);
}

int query(int l, int r, int id, int pos) {
    if(l == r) return tr[id];
    pushdown(id);
    int mid = (l + r) >> 1;
    if(pos <= mid) return query(l, mid, id << 1, pos);
    else return query(mid + 1, r, id << 1 | 1, pos);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, n, 1);
    int q;
    cin >> q;
    while(q--) {
        int op, p, x;
        cin >> op;
        if(op == 1) {
            cin >> p >> x;
            modify(1, n, 1, p, x);
        } else {
            cin >> x;
            tr[1] = max(tr[1], x);
        }
    }
    for(int i = 1; i <= n; i++)
        cout << query(1, n, 1, i) << ' ';
    return 0;
}
