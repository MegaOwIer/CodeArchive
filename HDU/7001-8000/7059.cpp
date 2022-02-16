#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 100005;
const int mod = 998244353;

struct segTree {
    int low, high, tag;
    segTree *l, *r;

    segTree() : low(0), high(0), tag(1), l(nullptr), r(nullptr) {}

    ~segTree() {
        if(l) delete l;
        if(r) delete r;
    }

    void maintain() {
        low = high = 0;
        if(l) {
            low = (low + l->low) % mod;
            high = (high + l->high) % mod;
        }
        if(r) {
            low = (low + r->low) % mod;
            high = (high + r->high) % mod;
        }
    }

    void modify(int val = 2) {
        tag = (LL)tag * val % mod;
        high = (LL)high * val % mod;
    }

    void pushdown() {
        if(tag > 1) {
            if(l) l->modify(tag);
            if(r) r->modify(tag);
            tag = 1;
        }
    }
};

int a[MX];

inline int get_hbit(int x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return (x + 1) >> 1;
}

void build_tree(segTree *&o, int l, int r) {
    o = new segTree;
    if(l == r) {
        int cur = get_hbit(a[l]);
        o->high = cur;
        o->low = (a[l] -= cur);
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(o->l, l, mid);
    build_tree(o->r, mid + 1, r);
    o->maintain();
}

int segTree_query(segTree *o, int L, int R, int l, int r) {
    if(L <= l && r <= R) {
        return (o->low + o->high) % mod;
    }
    o->pushdown();
    int mid = (l + r) >> 1, ans = 0;
    if(L <= mid) ans = (ans + segTree_query(o->l, L, R, l, mid)) % mod;
    if(R > mid) ans = (ans + segTree_query(o->r, L, R, mid + 1, r)) % mod;
    return ans;
}

void segtree_modify_high(segTree *o, int L, int R, int l, int r) {
    if(L <= l && r <= R) {
        return o->modify();
    }
    o->pushdown();
    int mid = (l + r) >> 1;
    if(L <= mid) segtree_modify_high(o->l, L, R, l, mid);
    if(R > mid) segtree_modify_high(o->r, L, R, mid + 1, r);
    o->maintain();
}

inline int lowbit(int u) { return u & -u; }

void segtree_modify_low(segTree *o, int L, int R, int l, int r) {
    if(o->low + o->high == 0) return;
    if(l == r) {
        if(o->low != 0) {
            o->low -= lowbit(o->low);
        } else {
            o->high = 0;
        }
        return;
    }
    o->pushdown();
    int mid = (l + r) >> 1;
    if(L <= mid) segtree_modify_low(o->l, L, R, l, mid);
    if(R > mid) segtree_modify_low(o->r, L, R, mid + 1, r);
    o->maintain();
}

void work() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    segTree *root = nullptr;
    build_tree(root, 1, n);

    int Q;
    cin >> Q;
    while(Q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1) {
            cout << segTree_query(root, l, r, 1, n) << "\n";
        } else if(op == 2) {
            segtree_modify_low(root, l, r, 1, n);
        } else {
            segtree_modify_high(root, l, r, 1, n);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        work();
    }
    return 0;
}
