#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 500005, mod = 1000000007;

int n, a[MX], ans, bit[2][MX];
vector<pair<int, int>> vec;

inline int lowbit(int u) {return u & (-u);}
inline void add(int &a, int b) {(a += b) >= mod && (a -= mod);}
void update(int *a, int b, int c) {for(; b <= n; b += lowbit(b)) add(a[b], c);}
int query(int *a, int l, int r) {
    int ans = 0;
    for(; r; r -= lowbit(r)) add(ans, a[r]);
    for(--l; l; l -= lowbit(l)) add(ans, mod - a[l]);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        vec.push_back({a[i], i});
    }
    sort(vec.begin(), vec.end());
    for(pair<int, int> &cur : vec) {
        int i = cur.second;
        int tmp = i * static_cast<LL>(n - i + 1) % mod;
        tmp = (tmp + query(bit[0], 1, i) * (n - i + 1) + query(bit[1], i, n) * i) % mod;
        ans = (ans + static_cast<LL>(cur.first) * tmp) % mod;
        update(bit[0], i, i), update(bit[1], i, n - i + 1);
    }
    cout << ans << endl;
    return 0;
}
