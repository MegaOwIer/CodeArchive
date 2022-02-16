#include <bits/stdc++.h>
using namespace std;

namespace std {

template<>
struct hash<pair<int, int>> {
    inline size_t operator() (const pair<int, int> &P) const {
        hash<int> int_hasher;
        return int_hasher(P.first) ^ int_hasher(P.second);
    }
};

}

using LL = long long;
const int MX = 100005;

int a[MX], b[MX], ans[MX];
vector<int> query_id[MX];

void exgcd(int a, int b, int &u, int &v) {
    if(!b) {
        u = 1, v = 0;
        return;
    }
    exgcd(b, a % b, v, u);
    v -= a / b * u;
}

int get_inv(int u, int mod) {
    int a, b;
    exgcd(u, mod, a, b);
    return (a + mod) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, m;
    cin >> T >> m;

    for(int i = 1; i <= T; i++) {
        cin >> a[i] >> b[i];
        int d = __gcd(m, __gcd(a[i], b[i]));
        query_id[d].push_back(i);
        a[i] /= d, b[i] = (m - b[i]) / d;
    }

    for(int d = 1; d <= m; d++) if(query_id[d].size()) {
        int mod = m / d;

        unordered_set<pair<int, int>> vis;
        map<pair<int, int>, map<int, int>> res;
        for(int u = 1, v = 0, i = 0; !vis.count({u, v}); u = (u + v) % mod, swap(u, v), i++) {
            int p = __gcd(v, mod), q = __gcd(u, mod);
            int cur_mod = mod / (p * q);
            int target = LL(u / q) * get_inv(v / p, cur_mod) % cur_mod;
            
            auto it = res[{p, q}].find(target);
            if(it == res[{p, q}].end()) {
                res[{p, q}][target] = i;
            }
            vis.insert({u, v});
        }

        for(int id : query_id[d]) {
            int p = __gcd(a[id], mod), q = __gcd(b[id], mod);
            int cur_mod = mod / (p * q);
            int target = LL(b[id] / q) * get_inv(a[id] / p, cur_mod) % cur_mod;

            auto it = res[{p, q}].find(target);
            ans[id] = it != res[{p, q}].end() ? it->second : -1;
        }
    }

    for(int i = 1; i <= T; i++) cout << ans[i] << "\n";

    return 0;
}
