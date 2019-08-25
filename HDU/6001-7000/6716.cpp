#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = (1 << 19) + 5, mod = 998244353;

int tr[MX << 1];
char s[MX];

void pushup(int id) {
    if(s[id] == '0') tr[id] = (tr[id << 1] + tr[id << 1 | 1]) % mod;
    else tr[id] = (LL)tr[id << 1] * tr[id << 1 | 1] % mod;
}

void update(int l, int r, int id, int pos, int val) {
    if(l == r) {
        tr[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) update(l, mid, id << 1, pos, val);
    else update(mid + 1, r, id << 1 | 1, pos, val);
    pushup(id);
}

int getAns(int l, int r, int id, int pos) {
    if(l == r) return 1;
    int mid = (l + r) >> 1;
    if(s[id] == '0') {
        if(pos <= mid) return getAns(l, mid, id << 1, pos);
        else return getAns(mid + 1, r, id << 1 | 1, pos);
    } else {
        if(pos <= mid) return (LL)tr[id << 1 | 1] * getAns(l, mid, id << 1, pos) % mod;
        else return (LL)tr[id << 1] * getAns(mid + 1, r, id << 1 | 1, pos) % mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int m, Q;
    cin >> m >> Q >> (s + 1);
    int n = 1 << (m - 1);
    for(int i = 1; i <= n; i++) update(1, n, 1, i, i);
    while(Q--) {
        int op, x;
        cin >> op >> x;
        if(op == 1) {
            int val;
            cin >> val;
            update(1, n, 1, x, val);
        } else {
            cout << getAns(1, n, 1, x) << "\n";
        }
    }
    return 0;
}
