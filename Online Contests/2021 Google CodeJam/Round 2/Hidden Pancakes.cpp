/* Round 2
 * https://codingcompetitions.withgoogle.com/codejam/round/0000000000435915/00000000007dc20c
 */

#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int mod = 1000000007, MX = 100000;

int fac[MX + 5], inv[MX + 5];
int val[MX + 5], ind[MX + 5];
vector<int> G[MX + 5];

void add_edge(int u, int v) {
    G[u].emplace_back(v);
    ind[v]++;
}

int C(int n, int m) { return (LL)fac[n] * inv[m] % mod * inv[n - m] % mod; }

pair<int, int> dfs(int u) {
    vector<int> vec;
    for(int v : G[u]) {
        if(!--ind[v]) vec.emplace_back(v);
    }
    int ans = 1, siz = 0;
    vector<pair<int, int>> res;
    for(int v : vec) {
        pair<int, int> cur = dfs(v);
        res.emplace_back(cur);
        siz += cur.second;
    }
    int tot = siz;
    for(pair<int, int> &cur : res) {
        ans = (LL)ans * C(tot, cur.second) % mod * cur.first % mod;
        tot -= cur.second;
    }
    return {ans, siz + 1};
}

int work() {
    int n;
    cin >> n;
    n += 1;
    memset(ind, 0, sizeof(int[n]));
    for(int i = 0; i <= n; i++) G[i].clear();

    for(int i = 1; i < n; i++) cin >> val[i];

    vector<int> vec = {0};
    for(int i = 1; i < n; i++) {
        if(val[i] >= val[i - 1] + 2) return 0;
        add_edge(vec[val[i] - 1], i);
        if(vec.size() >= val[i] + 1) {
            add_edge(i, vec[val[i]]);
        }
        vec.resize(val[i] + 1);
        vec[val[i]] = i;
    }

    return dfs(0).first;
}

int Pow(int a, int b) {
    int ans = 1;
    for(; b; b >>= 1, a = (LL)a * a % mod) if(b & 1) {
        ans = (LL)ans * a % mod;
    }
    return ans;
}

int main() {
    fac[0] = 1;
    for(int i = 1; i <= MX; i++) fac[i] = (LL)fac[i - 1] * i % mod;
    inv[MX] = Pow(fac[MX], mod - 2);
    for(int i = MX; i; i--) inv[i - 1] = (LL)inv[i] * i % mod;

    ios::sync_with_stdio(false);
    int cas;
    cin >> cas;
    for(int _ = 1; _ <= cas; _++) {
        printf("Case #%d: %d\n", _, work());
    }
    return 0;
}
