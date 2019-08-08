#include<bits/stdc++.h>
using namespace std;

const int MX = 300005, EPS = 2000000;
const int MV = 4000000;

struct segTree {
    int tag, mx;
    void add(int x) {tag += x, mx += x;}
}tr[MV << 2];

map<int, vector<int>> P;

void pushdown(int id) {
    if(tr[id].tag == 0) return;
    int val = tr[id].tag;
    tr[id << 1].add(val);
    tr[id << 1 | 1].add(val);
    tr[id].tag = 0;
}

void insert(int l, int r, int id, int L, int R, int val) {
    if(l != r) pushdown(id);
    if(L <= l && r <= R) {
        tr[id].add(val);
        return;
    }
    int mid = (l + r) >> 1;
    if(L <= mid) insert(l, mid, id << 1, L, R, val);
    if(R > mid) insert(mid + 1, r, id << 1 | 1, L, R, val);
    tr[id].mx = max(tr[id << 1].mx, tr[id << 1 | 1].mx);
}

int main() {
    ios::sync_with_stdio(false);
    int n, r;
    cin >> n >> r;
    r *= 2;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        P[x - y + EPS].push_back(x + y + EPS);
    }
    int ans = 0;
    for(map<int, vector<int>>::iterator it1 = P.begin(), it2 = P.begin(); it1 != P.end(); ++it1) {
        while(it2 != P.end() && it2 -> first <= it1 -> first + r) {
            for(int y : it2 -> second)
                insert(0, MV, 1, max(0, y - r), y, 1);
            ++it2;
        }
        ans = max(ans, tr[1].mx);
        for(int y : it1 -> second)
            insert(0, MV, 1, max(0, y - r), y, -1);
    }
    cout << ans << "\n";
    return 0;
}
