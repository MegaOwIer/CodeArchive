#include<bits/stdc++.h>
using namespace std;

using LL = long long;
constexpr int mod = 998244353, MX = 1000005;

int cnt[MX];
vector<int> gft[MX];

int getInv(int u) {return u == 1 ? 1 : LL(mod - mod / u) * getInv(mod % u) % mod;}

int main() {
    ios::sync_with_stdio(false);
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while(k--) {
            int id;
            cin >> id;
            gft[i].push_back(id);
            cnt[id]++;
        }
    }
    for(int i = 1; i <= n; i++) {
        int cur = 0, inv = getInv((LL)n * gft[i].size() % mod);
        for(int id : gft[i]) cur += cnt[id];
        ans = (ans + (LL)cur * inv) % mod;
    }
    cout << (LL)ans * getInv(n) % mod << "\n";
    return 0;
}
