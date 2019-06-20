#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 100005;

pair<LL, int> S[MX];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        ++b, p *= 2;
        int mod = 2 * q, B = floorl(sqrtl(mod));

        auto f = [p, mod](int x){return (LL)p * x % mod;};
        auto dis = [q, f](int x)->int{return abs(q - f(x));};

        for(int i = 0; i < B; i++) S[i + 1] = {f(i), i};
        sort(S + 1, S + B + 1);
        S[0] = {S[B].first - mod, S[B].second};
        S[B + 1] = {S[1].first + mod, S[1].second};
        pair<int, int> ans = {INT_MAX, INT_MAX};
        for(int l = a, r = a + B; l < b; l = r, r += B)
            if(r <= b) {
                LL tar = ((LL)q + mod - f(l)) % mod;
                int it = lower_bound(S + 1, S + B + 1, make_pair(tar, -1)) - S;
                ans = min(ans, {dis(l + S[it].second), l + S[it].second});
                ans = min(ans, {dis(l + S[it - 1].second), l + S[it - 1].second});
            } else {
                for(int i = l; i < b; i++) ans = min(ans, {dis(i), i});
            }
        printf("%d\n", ans.second);
    }
    return 0;
}
/*
1
229717240 896611996 864983627 854487553

*/