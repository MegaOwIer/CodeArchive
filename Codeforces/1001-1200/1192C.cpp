/**
 * @date 2022-03-24
 * @author MegaOwIer (megaowier@gmail.com)
 * @brief An interesting problem on counting.
 */

#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int mod = 998244353, MX = 62;

int calc(const set<string> &str) {
    auto get_id = [] (char c) {
        if(islower(c)) return c - 'a';
        if(isupper(c)) return (c - 'A') + 26;
        return (c - '0') + 52;
    };

    vector<vector<int>> cost(MX, vector<int>(MX, 0));
    for(const string &s : str) {
        cost[get_id(s.front())][get_id(s.back())] += 1;
    }

    int dp[MX][MX][MX];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < MX; i++) {
        for(int j = i; j < MX; j++) {
            for(int k = j; k < MX; k++) {
                LL cur = 0;
                for(int r = 0; r < MX; r++) {
                    cur += (LL)cost[r][i] * cost[r][j] * cost[r][k];
                }
                dp[i][j][k] = cur % mod;
            }
        }
    }

    int ans = 0;
    vector<int> ch {0};

    function<void(int, int)> dfs = [&] (int dep, int w) {
        if(dep > 4) {
            LL tmp = (LL)dp[ch[1]][ch[2]][ch[3]] * dp[ch[1]][ch[2]][ch[4]] % mod
                                                 * dp[ch[1]][ch[3]][ch[4]] % mod
                                                 * dp[ch[2]][ch[3]][ch[4]] % mod;
            ans = (ans + w * tmp) % mod;
            return;
        }
        for(int i = ch.back(); i < MX; i++) {
            ch.push_back(i);
            int tmp = count(ch.begin() + 1, ch.end(), i);
            dfs(dep + 1, w / tmp);
            ch.pop_back();
        }
    };

    dfs(1, 24);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<size_t, set<string>> str;
    while(n--) {
        string s;
        cin >> s;
        str[s.length()].insert(s);
        reverse(s.begin(), s.end());
        str[s.length()].insert(s);
    }

    int ans = 0;
    for(auto &tmp : str) {
        ans = (ans + calc(tmp.second)) % mod;
    }
    cout << ans << "\n";
    return 0;
}
