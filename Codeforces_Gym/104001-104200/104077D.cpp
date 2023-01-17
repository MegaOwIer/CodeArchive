/**
 * @date 2023-01-13
 * @author MegaOwIer (megaowier@gmail.com)
 * @brief Binary lifting.
 */

#include <bits/stdc++.h>
using namespace std;

const int MX = 100005;
const int MXLG = 17;
const int INF = 0x3F3F3F3F;

int rnklist[5][MX], rnk[5][MX];
int dp[MXLG + 1][MX][5];

void update(int &a, int b) {
    if(a == 0 || a > b) a = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        for(int j = 1; j <= n; j++) {
            int val;
            cin >> val;
            rnklist[i][j] = val;
            rnk[i][val] = j;
        }
    }

    for(int i = 0; i < m; i++) {
        vector<bool> vised(n + 1);
        vector<int> iter(m, 1);
        for(int j = 1; j <= n; j++) {
            int cur = rnklist[i][j];
            for(int k = 0; k < m; k++) {
                update(dp[0][cur][k], iter[k]);
            }

            vised[cur] = true;
            for(int k = 0; k < m; k++) {
                while(iter[k] <= n && vised[rnklist[k][iter[k]]]) iter[k]++;
            }
        }
    }

    for(int i = 1; i <= MXLG; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 0; k < m; k++) {
                int &cur = dp[i][j][k];
                cur = dp[i - 1][j][k];
                for(int l = 0; l < m; l++) {
                    int tmp = dp[i - 1][j][l];
                    if(tmp == n + 1) {
                        assert(false);
                    }
                    tmp = rnklist[l][tmp];
                    cur = min(cur, dp[i - 1][tmp][k]);
                }
            }
        }
    }

    function<int(int, int)> solve = [&] (int x, int y) {
        vector<int> point(m);
        for(int i = 0; i < m; i++) {
            if(rnk[i][x] < rnk[i][y]) {
                return 1;
            }
            point[i] = x;
        }

        int ans = 0;
        for(int i = MXLG; i >= 0; i--) {
            vector<int> tmp = point;
            for(int cur : point) {
                for(int j = 0; j < m; j++) {
                    int rk = dp[i][cur][j];
                    if(rk < rnk[j][tmp[j]]) {
                        tmp[j] = rnklist[j][rk];
                    }
                }
            }

            bool flag = false;
            for(int j = 0; j < m; j++) {
                if(rnk[j][tmp[j]] <= rnk[j][y]) {
                    flag = true;
                    break;
                }
            }

            if(!flag) {
                ans += 1 << i;
                point = tmp;
            }
        }

        return ans <= n ? ans + 2 : -1;
    };

    int q;
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        cout << solve(x, y) << "\n";
    }

    return 0;
}
