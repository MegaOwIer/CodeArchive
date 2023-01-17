/**
 * @date 2022-03-24
 * @author MegaOwIer (megaowier@gmail.com)
 * @brief A simple problem in Dynamic DP.
 */

#include <bits/stdc++.h>
using namespace std;

const int MX = 200005;

struct Matrix {
    int a[5][5];

    Matrix() {
        for(size_t i = 0; i < 5; i++) {
            a[i][i] = 0;
            for(size_t j = i + 1; j < 5; j++) {
                a[i][j] = -1;
            }
        }
    }

    int *operator[] (size_t u) { return a[u]; }
    const int *operator[] (size_t u) const { return a[u]; }

    Matrix operator* (const Matrix &b) {
        Matrix ans;
        for(size_t i = 0; i < 5; i++) {
            for(size_t j = i; j < 5; j++) {
                int result = numeric_limits<int>::max();
                for(size_t k = i; k <= j; k++) {
                    if(a[i][k] == -1 || b[k][j] == -1) {
                        continue;
                    }
                    result = min(a[i][k] + b[k][j], result);
                }
                ans[i][j] = (result != numeric_limits<int>::max()) ? result : -1;
            }
        }
        return ans;
    }
};

struct segTree {
    segTree *l, *r;
    Matrix data;

    segTree() : l(nullptr), r(nullptr) {}

    ~segTree() {
        if(l) delete l;
        if(r) delete r;
    }

    void maintain() {
        data = l->data * r->data;
    }
};

char s[MX + 1];

void build(segTree *&o, int l, int r) {
    o = new segTree;
    if(l == r) {
        switch(s[l]) {
            case '2':
                o->data[0][1] = 0;
                o->data[0][0] = 1;
                break;
            case '0':
                o->data[1][2] = 0;
                o->data[1][1] = 1;
                break;
            case '1':
                o->data[2][3] = 0;
                o->data[2][2] = 1;
                break;
            case '7':
                o->data[3][4] = 0;
                o->data[3][3] = 1;
                break;
            case '6':
                o->data[3][3] = 1;
                o->data[4][4] = 1;
                break;
            default:
                break;
        }
        return;
    }
    int mid = (l + r) / 2;
    build(o->l, l, mid);
    build(o->r, mid + 1, r);
    o->maintain();
}

Matrix query(segTree *o, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        return o->data;
    }
    int mid = (l + r) / 2;
    Matrix ans;
    if(L <= mid) ans = ans * query(o->l, l, mid, L, R);
    if(R > mid) ans = ans * query(o->r, mid + 1, r, L, R);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q >> (s + 1);

    segTree *root = nullptr;
    build(root, 1, n);

    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << query(root, 1, n, l, r)[0][4] << "\n";
    }

    delete root;
    return 0;
}
