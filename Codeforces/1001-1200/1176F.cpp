#include<bits/stdc++.h>
using namespace std;

using LL = long long;
using pli = pair<LL, int>;
const int MX = 200005;

LL dp[2][10];
pli atk[MX][4];

inline void update(LL &a, LL b) {a = max(a, b);}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int k, val2 = 0;
        vector<int> val;
        cin >> k;
        while(k--) {
            int a, b;
            cin >> a >> b;
            atk[i][1] = max(atk[i][1], {b, b});
            if(a == 2) val2 = max(val2, b);
            if(a == 1) val.push_back(b);
        }
        sort(val.begin(), val.end(), greater<int>());
        if(val.size() >= 3) {
            atk[i][3] = {(LL)val[0] + val[1] + val[2], val[0]};
        }
        if(val2 != 0)
            val.push_back(val2);
        sort(val.begin(), val.end(), greater<int>());
        if(val.size() >= 2) {
            atk[i][2] = {val[0] + val[1], val[0]};
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        int cur = i & 1, pre = (i & 1) ^ 1;
        memcpy(dp[cur], dp[pre], sizeof(LL[10]));
        for(int j = 0; j < 10; j++) if(dp[pre][j] != -1) {
            for(int k = 1; k <= 3; k++) if(atk[i][k].first) {
                LL val = dp[pre][j] + atk[i][k].first;
                if(j + k >= 10) val += atk[i][k].second;
                update(dp[cur][(j + k) % 10], val);
            }
        }
    }
    LL ans = 0;
    for(LL i : dp[n & 1]) ans = max(ans, i);
    cout << ans << "\n";
    return 0;
}
