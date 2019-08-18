#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 100005;

int tr[MX << 2];

int read() {
    int x = 0, c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x;
}

int gcd(int a, int b) {
    if(a == 0 || b == 0) return a + b;
    int ctz = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    while(b != 0) {
        b >>= __builtin_ctz(b);
        if(a > b) swap(a, b);
        b -= a;
    }
    return a << ctz;
}

void update(int l, int r, int id, int pos, int val) {
    if(l == r) {
        tr[id] = val;
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) update(l, mid, id << 1, pos, val);
    else update(mid + 1, r, id << 1 | 1, pos, val);
    tr[id] = gcd(tr[id << 1], tr[id << 1 | 1]);
}
int getVal(int l, int r, int id, int L, int R) {
    if(L <= l && r <= R) return tr[id];
    int ans = 0, mid = (l + r) >> 1;
    if(L <= mid) ans = gcd(ans, getVal(l, mid, id << 1, L, R));
    if(R > mid) ans = gcd(ans, getVal(mid + 1, r, id << 1 | 1, L, R));
    return ans;
}

int getNextL(int l, int r, int id, int tar, int cur) {
    if(l == r) return l;
    int mid = (l + r) >> 1, tmp = gcd(cur, tr[id << 1 | 1]);
    if(tmp == 0 || tmp >= tar)
        return getNextL(l, mid, id << 1, tar, tmp);
    else
        return getNextL(mid + 1, r, id << 1 | 1, tar, cur);
}
int getNextR(int l, int r, int id, int tar, int cur) {
    if(l == r) return l;
    int mid = (l + r) >> 1, tmp = gcd(cur, tr[id << 1]);
    if(tmp == 0 || tmp >= tar)
        return getNextR(mid + 1, r, id << 1 | 1, tar, tmp);
    else
        return getNextR(l, mid, id << 1, tar, cur);
}

int main() {
    int n = read(), q = read();
    for(int i = 1; i <= n; i++)
        update(0, n + 1, 1, i, read());
    while(q--) {
        int pos = read(), val = read();
        update(0, n + 1, 1, pos, val);
        int _l = 1, _r = n - 1, res = n;
        while(_l <= _r) {
            int mid = (_l + _r) >> 1;
            if(getVal(0, n + 1, 1, 1, mid) <= getVal(0, n + 1, 1, mid + 1, n))
                res = mid, _r = mid - 1;
            else _l = mid + 1;
        }
        long long ans = 0;
        for(int i = res, r; i <= n; i = r) {
            int cur = getVal(0, n + 1, 1, 1, i);
            r = getNextR(0, n + 1, 1, cur, 0);
            ans += LL(r - i) * cur;
        }
        for(int i = res, l; i >= 1; i = l) {
            int cur = getVal(0, n + 1, 1, i, n);
            l = getNextL(0, n + 1, 1, cur, 0);
            ans += LL(i - l) * cur;
        }
        printf("%lld\n", ans - tr[1]);
    }
    return 0;
}