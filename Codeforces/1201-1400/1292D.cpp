#include <bits/stdc++.h>
using namespace std;

using LL = long long;

constexpr int MX = 1000005, MVAL = 5000, PCNT = 670;

int pr[PCNT], cnt, d[MVAL + 5];
bool vis[MVAL + 5], invalid[MX];
int val[MVAL + 5], pid[MVAL + 5], pw[MVAL + 5];

int calc(int val, int p) {
    int ans = 0;
    while(val /= p) ans += val;
    return ans;
}

int main() {
    pr[0] = 1;
    for(int i = 2; i <= MVAL; i++) {
        if(!vis[i]) pr[++cnt] = i, d[i] = 1;
        for(int j = 1, tmp; j <= cnt && (tmp = i * pr[j]) <= MVAL; j++) {
            vis[tmp] = true, d[tmp] = d[i] + 1;
            if(i % pr[j] == 0) break;
        }
    }
    for(int i = 2; i <= MVAL; i++) d[i] += d[i - 1];
    for(int i = 0; i <= MVAL; i++) {
        pid[i] = upper_bound(pr + 1, pr + cnt + 1, i) - pr - 1;
        if(!pid[i]) invalid[i] = true;
        else pw[i] = calc(i, pr[pid[i]]);
    }

    ios::sync_with_stdio(false);
    int n;
    long long ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int cur;
        cin >> cur;
        val[cur]++;
        ans += d[cur];
    }
    for(int i = 0; i <= MVAL; i++) if(!val[i]) invalid[i] = true;
    while(true) {
        map<int, int> cnt;
        for(int i = 0; i <= MVAL; i++) if(!invalid[i]) cnt[pid[i]] += val[i];
        pair<int, int> mx {0, 0};
        for(auto &cur : cnt) if(cur.second > mx.second) mx = cur;
        if(n >= 2 * mx.second) break;
        int step = INT_MAX;
        for(int i = 0; i <= MVAL; i++)
            if(!invalid[i] && pid[i] == mx.first) step = min(step, pw[i]);
        for(int i = 0; i <= MVAL; i++) if(!invalid[i]) {
            if(pid[i] != mx.first) invalid[i] = true;
            else {
                pw[i] -= step;
                if(!pw[i]) {
                    if(!--pid[i]) invalid[i] = true;
                    else pw[i] = calc(i, pr[pid[i]]);
                }
            }
        }
        ans += (LL)step * (n - 2 * mx.second);
    }
    cout << ans << "\n";
    return 0;
}
