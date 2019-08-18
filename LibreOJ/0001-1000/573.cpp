#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 1000005, mod = 998244353;

struct Matrix {
    int a[2][2];
    Matrix() {}
    Matrix(int _v) {
        a[0][0] = _v;
        a[0][1] = a[1][0] = 1;
        a[1][1] = 0;
    }
    int* operator [] (int x) {return a[x];}
    Matrix operator * (Matrix);
};
Matrix Matrix::operator * (Matrix x) {
    static Matrix ans;
    for(int i : {0, 1})
        for(int j : {0, 1}) {
            ans[i][j] = 0;
            for(int k : {0, 1})
                ans[i][j] = (ans[i][j] + (LL)a[i][k] * x[k][j]) % mod;
        }
    return ans;
}

Matrix tr[MX << 2];

void update(int l, int r, int id, int pos, int val) {
    if(l == r) {
        tr[id] = Matrix(val);
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) update(l, mid, id << 1, pos, val);
    else update(mid + 1, r, id << 1 | 1, pos, val);
    tr[id] = tr[id << 1 | 1] * tr[id << 1];
}
Matrix query(int L, int R, int id, int l, int r) {
    if(l <= L && R <= r) return tr[id];
    int mid = (L + R) >> 1;
    Matrix ans;
    ans[0][0] = ans[1][1] = 1;
    ans[0][1] = ans[1][0] = 0;
    if(r > mid) ans = ans * query(mid + 1, R, id << 1 | 1, l, r);
    if(l <= mid) ans = ans * query(L, mid, id << 1, l, r);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, Type, lth = 0, Ansx = 0, Ansy = 0;
    cin >> n >> m >> Type;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        update(1, n + m, 1, ++lth, val);
    }
    for(int i = 1; i <= m; i++) {
        int opt, l, r;
        cin >> opt;
        if(opt == 1) {
            cin >> l;
            if(Type == 1)
                l ^= Ansx ^ Ansy;
            update(1, n + m, 1, ++lth, l);
        } else {
            cin >> l >> r;
            if(Type == 1) {
                l ^= Ansx ^ Ansy;
                r ^= Ansx ^ Ansy;
            }
            Matrix tmp = query(1, n + m, 1, l, r);
            Ansx = tmp[0][0], Ansy = tmp[0][1];
            printf("%d %d\n", Ansx, Ansy);
        }
    }
    return 0;
}
